/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red-black-tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:27:22 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/22 17:47:15 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

namespace ft {
	template <class T>
	class RedBlackTree {

		typedef enum		s_color {
			BLACK,
			RED
		}					Color;

		struct	Node {
			typedef T			value_type;

			T					data;

			struct Node			*parent;

			struct Node			*left;
			struct Node			*right;

			Color				color;
		};

		private:
			Node*	root;
			Node*	TNULL;
			size_t	length;

			Node*	newNode(T data) {
				Node*	node = new Node();

				node->data = data;
				node->parent = NULL;
				node->left = TNULL;
				node->right = TNULL;
				node->color = RED;

				return node;
			};

			void	insertFix(Node * node) {
				Node *tmp;

				while (node->parent->color == RED) {
					if (node->parent == node->parent->parent->left) {
						tmp = node->parent->parent->right;
						if (tmp != TNULL && tmp->color == RED) {
							node->parent->color = BLACK;
							tmp->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (tmp == TNULL || tmp->color == BLACK) {
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
						if (tmp != TNULL && tmp->color == RED) {
							node->parent->color = BLACK;
							tmp->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (tmp == TNULL || tmp->color == BLACK) {
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
					if (node == root)
						break ;
				}

				root->color = BLACK;
			};

			void	leftRotation(Node * x) {
				Node	*y = x->right;

				x->right = y->left;

				if (y->left != TNULL)
					y->left->parent = x;

				y->parent = x->parent;

				if (x->parent == NULL)
					root = y;
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

				if (y->right != TNULL)
					y->right->parent = x;
				
				y->parent = x->parent;

				if (x->parent == NULL)
					root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;

				y->right = x;
				x->parent = y;
			}

			void	transplant(Node * u, Node * v) {
				if (u->parent == NULL)
					root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			};

			Node*	minimum(Node * node) {
				if (node->left == TNULL)
					return node;

				return minimum(node->left);
			}

			Node*	maximum(Node * node) {
				if (node->right == TNULL)
					return node;

				return minimum(node->right);
			}

			void	delFix(Node * node) {
				Node*	tmp;

				while (node != root && node->color == BLACK) {
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
							node = root;
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
							node = root;
						}
					}
				}

				node->color = BLACK;
			};

			void	delHelper(Node * root, T first) {
				Node	*node = TNULL;
				Node	*x, *y;

				while (root != TNULL) {
					if (root->first == first) {
						node = root;
						break ;
					}
					else if (first < root->first)
						root = root->left;
					else if (first > root->first)
						root = root->right;
				}

				if (node == TNULL)
					return ;

				y = node;

				Color originalColor = y->color;

				if (node->left == TNULL) {
					x = node->right;
					transplant(node, node->right);
				}
				else if (node->right == TNULL) {
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

				length--;
			};

			void	printHelper(Node * node) {
				if (node == TNULL)
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
				if (node == TNULL)
					return node;

				if (key < node->data.first)
					return searchHelper(node->left, key);
				else if (key > node->data.first)
					return searchHelper(node->right, key);
				return node;
			};

		public:

			Tree(void) {
				TNULL = new Node();

				TNULL->left = NULL;
				TNULL->right = NULL;
				TNULL->color = BLACK;

				length = 0;

				root = TNULL;
			};

			~Tree(void) {
				delete TNULL;
			}

			Node*	insert(T data) {
				length++;

				if (root == TNULL) {
					root = newNode(data);
					root->color = BLACK;
					return root;
				}

				Node *tmp = root;
				Node *node = NULL;

				while (tmp != TNULL) {
					if (data.first < tmp->data.first) {
						if (tmp->left == TNULL) {
							tmp->left = newNode(data);
							tmp->left->parent = tmp;
							node = tmp->left;
							break ;
						}
						tmp = tmp->left;
					}
					else if (data.first >= tmp->data.first) {
						if (tmp->right == TNULL) {
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

			void	del(T first) {
				delHelper(root, first);
			};

			size_t	size(void) const {
				return this->length;
			};

			Node*	search(Key const & key) {
				return searchHelper(root, key);
			};

			void	print(void) {
				if (root)
					printHelper(root);
			};

			Node*	firstElement(void) {
				return minimum(root);
			};

			Node*	lastElement(void) {
				Node* node = maximum(root);
				return node->right;
			};

			Node*	getRoot(void) {
				return this->root;
			}

			Node*	getTNULL(void) {
				return this->TNULL;
			}
	};
}


#endif