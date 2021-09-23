/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:27:22 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/23 17:39:08 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "iterators.hpp"

namespace ft {
	template <class T, class Compare>
	class RedBlackTree {
		public:

			typedef enum		s_color {
				BLACK,
				RED
			}					Color;

			class	Node {
				public:
					typedef T			value_type;

					T		data;
					Node*	parent;
					Node*	left;
					Node*	right;
					Color	color;

				Node(void): parent(nullptr), left(nullptr), right(nullptr), color(BLACK) {};

				Node(T data, Node * parent, Node * left, Node * right, Color color)
				: data(data), parent(parent), left(left), right(right), color(color) {};

				Node(const Node & instance)
				: data(instance.data), parent(instance.parent), left(instance.left), right(instance.right), color(instance.color) {};

				Node&	operator=(const Node & instance) {
					if (this == &instance)
						return *this;
					this->data = instance.data;
					this->parent = instance.parent;
					this->left = instance.left;
					this->right = instance.right;
					this->color = instance.color;

					return *this;
				}
			};

			typedef typename T::key						Key;
			typedef ft::bst_iterator<Node, Compare>		iterator;

		private:

			Node*					_root;
			Node*					_TNULL;
			size_t					_length;
			std::allocator<Node>	_allocator;

			Node*	newNode(T data) {
				// Node*	node = new Node();
				Node*	node = this->_allocator.allocate(1);

				this->_allocator.construct(node, Node(data, NULL, this->_TNULL, this->_TNULL, RED));
				// node->data = data;
				// node->parent = NULL;
				// node->left = _TNULL;
				// node->right = _TNULL;
				// node->color = RED;

				return node;
			};

			void	insertFix(Node * node) {
				Node *tmp;

				while (node->parent->color == RED) {
					if (node->parent == node->parent->parent->left) {
						tmp = node->parent->parent->right;
						if (tmp != _TNULL && tmp->color == RED) {
							node->parent->color = BLACK;
							tmp->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (tmp == _TNULL || tmp->color == BLACK) {
							if (node == node->parent->right) {
								node = node->parent;
								leftRotation(node);
							}

							rightRotation(node->parent->parent);
							node->parent->color = BLACK;
							node->parent->right->color = RED;
							if (node->parent->parent != NULL)
								node->parent->parent->color = RED;
						}
					}
					else if (node->parent == node->parent->parent->right) {
						tmp = node->parent->parent->left;
						if (tmp != _TNULL && tmp->color == RED) {
							node->parent->color = BLACK;
							tmp->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (tmp == _TNULL || tmp->color == BLACK) {
							if (node == node->parent->left) {
								node = node->parent;
								rightRotation(node);
							}

							leftRotation(node->parent->parent);
							node->parent->color = BLACK;
							node->parent->left->color = RED;
							if (node->parent->parent != NULL)
								node->parent->parent->color = RED;
						}
					}
					if (node == _root)
						break ;
				}

				_root->color = BLACK;
			};

			void	leftRotation(Node * x) {
				Node	*y = x->right;

				x->right = y->left;

				if (y->left != _TNULL)
					y->left->parent = x;

				y->parent = x->parent;

				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;

				y->left = x;
				x->parent = y;
			}

			void	rightRotation(Node * x) {
				Node	*y = x->left;

				x->left = y->right;

				if (y->right != _TNULL)
					y->right->parent = x;
				
				y->parent = x->parent;

				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;

				y->right = x;
				x->parent = y;
			}

			void	transplant(Node * u, Node * v) {
				if (u->parent == NULL)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			};

			Node*	minimum(Node * node) {
				if (node->left == _TNULL)
					return node;

				return minimum(node->left);
			}

			Node*	maximum(Node * node) {
				if (node->right == _TNULL)
					return node;

				return minimum(node->right);
			}

			void	delFix(Node * node) {
				Node*	tmp;

				while (node != _root && node->color == BLACK) {
					if (node == node->parent->left) {
						tmp = node->parent->right;

						if (tmp->color == RED) {
							tmp->color = BLACK;
							node->parent->color = RED;

							leftRotation(node->parent);
							tmp = node->parent->right;
						}

						if (tmp->left->color == BLACK && tmp->right->color== BLACK) {
							tmp->color = RED;
							node = node->parent;
						}
						else {
							if (tmp->right->color == BLACK) {
								tmp->left->color = BLACK;
								tmp->color = RED;
								rightRotation(tmp);
								tmp = node->parent->right;
							}

							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->right->color = BLACK;
							leftRotation(node->parent);
							node = _root;
						}
					}
					else {
						tmp = node->parent->left;

						if (tmp->color == RED) {
							tmp->color = BLACK;
							node->parent->color = RED;

							rightRotation(node->parent);
							tmp = node->parent->left;
						}

						if (tmp->right->color == BLACK && tmp->left->color == BLACK) {
							tmp->color = RED;
							node = node->parent;
						}
						else {
							if (tmp->left->color == BLACK) {
								tmp->right->color = BLACK;
								tmp->color = RED;

								leftRotation(tmp);
								tmp = node->parent->left;
							}

							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->left->color = BLACK;

							rightRotation(node->parent);
							node = _root;
						}
					}
				}

				node->color = BLACK;
			};

			void	delHelper(Node * root, Key key) {
				Node	*node = _TNULL;
				Node	*x, *y;

				while (root != _TNULL) {
					if (root->data.first == key) {
						node = root;
						break ;
					}
					else if (key < root->data.first)
						root = root->left;
					else if (key > root->data.first)
						root = root->right;
				}

				if (node == _TNULL)
					return ;

				y = node;

				Color originalColor = y->color;

				if (node->left == _TNULL) {
					x = node->right;
					transplant(node, node->right);
				}
				else if (node->right == _TNULL) {
					x = node->left;
					transplant(node, node->left);
				}
				else {
					y = minimum(node->right);
					originalColor = y->color;
					x = y->right;

					if (y->parent == node) {
						x->parent = y;
					}
					else {
						transplant(y, y->right);
						y->right = node->right;
						y->right->parent = y;
					}

					transplant(node, y);
					y->left = node->left;
					y->left->parent = y;
					y->color = node->color;
				}

				delete node;

				if (originalColor == BLACK) {
					delFix(x);
				}

				_length--;
			};

			void	printHelper(Node * node) {
				if (node == _TNULL)
					return ;

				printHelper(node->left);
				std::cout << "#===============#" << std::endl;
				std::cout << "# first\t: " << node->data.first << "\t#" << std::endl;
				// std::cout << "# second: " << node->data.second << "\t#" << std::endl;
				std::cout << "# parent: " << (node->parent != NULL ? node->parent->data.first : NULL) << "\t#" << std::endl;
				std::cout << "# left\t: " << (node->left != NULL ? node->left->data.first : NULL) << "\t#" << std::endl;
				std::cout << "# right\t: " << (node->right != NULL ? node->right->data.first : NULL) << "\t#" << std::endl;
				std::cout << "# color\t: " << (node->color == BLACK ? "Black" : "Red") << "\t#" << std::endl;
				std::cout << "#===============#\n" << std::endl;
				printHelper(node->right);
			};

			Node* searchHelper(Node * node, Key const & key) {
				if (node == _TNULL)
					return node;

				if (key < node->data.first)
					return searchHelper(node->left, key);
				else if (key > node->data.first)
					return searchHelper(node->right, key);
				return node;
			};

		public:
			RedBlackTree(void) {
				// _TNULL = new Node();
				_TNULL = this->_allocator.allocate(1);

				this->_allocator.construct(_TNULL, Node());

				// _TNULL->left = NULL;
				// _TNULL->right = NULL;
				// _TNULL->color = BLACK;

				_length = 0;

				_root = _TNULL;
			};

			~RedBlackTree(void) {
				this->_allocator.destroy(_TNULL);
				this->_allocator.deallocate(_TNULL, 1);
			}

			Node*	insert(T data) {
				_length++;

				if (_root == _TNULL) {
					_root = newNode(data);
					_root->color = BLACK;
					return _root;
				}

				Node *tmp = _root;
				Node *node = NULL;

				while (tmp != _TNULL) {
					if (data.first < tmp->data.first) {
						if (tmp->left == _TNULL) {
							tmp->left = newNode(data);
							tmp->left->parent = tmp;
							node = tmp->left;
							break ;
						}
						tmp = tmp->left;
					}
					else if (data.first >= tmp->data.first) {
						if (tmp->right == _TNULL) {
							tmp->right = newNode(data);
							tmp->right->parent = tmp;
							node = tmp->right;
							break ;
						}
						tmp = tmp->right;
					}
				}

				insertFix(node);

				return node;
			};

			void	del(Key key) {
				delHelper(_root, key);
			};

			size_t	size(void) const {
				return this->_length;
			};

			Node*	search(Key const & key) {
				return searchHelper(_root, key);
			};

			void	print(void) {
				if (_root)
					printHelper(_root);
			};

			Node*	firstElement(void) {
				return minimum(_root);
			};

			Node*	lastElement(void) {
				Node* node = maximum(_root);
				return node->right;
			};

			Node*	getRoot(void) {
				return this->_root;
			}

			Node*	getTNULL(void) {
				return this->_TNULL;
			}
	};
}


#endif