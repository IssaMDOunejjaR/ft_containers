/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:27:22 by iounejja          #+#    #+#             */
/*   Updated: 2021/10/31 12:00:03 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

// # include "iterators.hpp"

namespace ft {
	typedef enum		s_color {
		BLACK,
		RED
	}					Color;

	template <class T>
	class	Node {
		public:
			T		data;
			Node*	parent;
			Node*	left;
			Node*	right;
			Color	color;

			Node(void): parent(NULL), left(NULL), right(NULL), color(BLACK) {};

			Node(Node * parent, Node * left, Node * right, Color color)
			: parent(parent), left(left), right(right), color(color) {};

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

	template <class T, class Compare>
	class RedBlackTree {
		public:
			typedef typename T::key						Key;
			typedef Node<T>								Node;

		private:

			Node*					_root;
			size_t					_length;
			Compare					_Comp;
			std::allocator<Node>	_allocator;

			Node*	newNode(T data) {
				Node*	node = this->_allocator.allocate(1);
				Node*	leafLeft = this->_allocator.allocate(1);
				Node*	leafRight = this->_allocator.allocate(1);

				this->_allocator.construct(leafLeft, Node(node, NULL, NULL, BLACK));
				this->_allocator.construct(leafRight, Node(node, NULL, NULL, BLACK));
				this->_allocator.construct(node, Node(data, NULL, leafLeft, leafRight, RED));

				return node;
			};

			void	insertFix(Node * node) {
				Node *tmp;

				while (node->parent->color == RED) {
					if (node->parent == node->parent->parent->left) {
						tmp = node->parent->parent->right;
						if ((tmp->left != NULL && tmp->right != NULL) && tmp->color == RED) {
							node->parent->color = BLACK;
							tmp->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if ((tmp->left == NULL && tmp->right == NULL) || tmp->color == BLACK) {
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
						if ((tmp->left != NULL && tmp->right != NULL) && tmp->color == RED) {
							node->parent->color = BLACK;
							tmp->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if ((tmp->left == NULL && tmp->right == NULL) || tmp->color == BLACK) {
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

				if (y->left->left != NULL && y->left->right != NULL)
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

				if (y->right->left != NULL && y->right->right != NULL)
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
				if (node->left->left == NULL && node->left->right == NULL)
					return node;

				return minimum(node->left);
			}

			Node*	maximum(Node * node) {
				if (node->right->left == NULL && node->right->right == NULL)
					return node;

				return maximum(node->right);
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

						if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
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
				Node	*node = NULL;
				Node	*x, *y;

				while (root->left != NULL && root->right != NULL) {
					if (root->data.first == key) {
						node = root;
						break ;
					}
					else if (key < root->data.first)
						root = root->left;
					else if (key > root->data.first)
						root = root->right;
				}

				if (node->left == NULL && node->right == NULL)
					return ;

				y = node;

				Color originalColor = y->color;

				if (node->left->left == NULL && node->left->right == NULL) {
					x = node->right;
					transplant(node, node->right);
				}
				else if (node->right->left == NULL && node->right->right == NULL) {
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
				if (node->left == NULL && node->right == NULL)
					return ;

				printHelper(node->left);
				std::cout << "#===============#" << std::endl;
				std::cout << "# first\t: " << node->data.first << "\t#" << std::endl;
				// std::cout << "# second: " << node->data.second << "\t#" << std::endl;
				std::cout << "# parent: " << (node->parent != NULL ? node->parent->data.first : NULL) << "\t#" << std::endl;
				std::cout << "# left\t: " << (node->left->left != NULL && node->left->right != NULL ? node->left->data.first : NULL) << "\t#" << std::endl;
				std::cout << "# right\t: " << (node->right->left != NULL && node->right->right != NULL ? node->right->data.first : NULL) << "\t#" << std::endl;
				std::cout << "# color\t: " << (node->color == BLACK ? "Black" : "Red") << "\t#" << std::endl;
				std::cout << "#===============#\n" << std::endl;
				printHelper(node->right);
			};

			Node* searchHelper(Node * node, Key const & key) {
				if (node->left == NULL && node->right == NULL)
					return node;

				// if (key < node->data.first)
				// 	return searchHelper(node->left, key);
				// else if (key > node->data.first)
				// 	return searchHelper(node->right, key);
				if (this->_Comp()(key, ))
				return node;
			};

		public:
			RedBlackTree(void) {
				// _TNULL = this->_allocator.allocate(1);

				// this->_allocator.construct(_TNULL, Node());

				_length = 0;

				_root = this->_allocator.allocate(1);

				this->_allocator.construct(_root, Node());

				_root->parent = NULL;
				_root->left = NULL;
				_root->right = NULL;
				_root->color = BLACK;
			};

			~RedBlackTree(void) {
				// this->_allocator.destroy(_TNULL);
				// this->_allocator.deallocate(_TNULL, 1);
			}

			Node*	insert(T data) {
				_length++;

				if (_root->left == NULL && _root->right == NULL) {
					_root = newNode(data);
					_root->color = BLACK;
					return _root;
				}

				Node *tmp = _root;
				Node *node = NULL;

				while (tmp->left != NULL && tmp->right != NULL) {
					if (data.first < tmp->data.first) {
						if (tmp->left->left == NULL && tmp->left->right == NULL) {
							tmp->left = newNode(data);
							tmp->left->parent = tmp;
							node = tmp->left;
							break ;
						}
						tmp = tmp->left;
					}
					else if (data.first >= tmp->data.first) {
						if (tmp->right->left == NULL && tmp->right->right == NULL) {
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
				Node* node = maximum(this->_root);

				return node;
			};

			Node*	getRoot(void) {
				return this->_root;
			}

			// Node*	getTNULL(void) {
			// 	return this->_TNULL;
			// }
	};
}

#endif