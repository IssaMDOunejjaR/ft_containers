/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:41:48 by iounejja          #+#    #+#             */
/*   Updated: 2021/10/31 12:32:40 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include "red_black_tree.hpp"

namespace ft {

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type 		difference_type;
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category 	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t 						difference_type;
		typedef T 								value_type;
		typedef T* 								pointer;
		typedef T& 								reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <typename T>
	class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
		public:
			typedef typename std::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef T*																				pointer;
			typedef T&																				reference;

			Iterator(void) {};
			Iterator(pointer ptr): _ptr(ptr) {};
			Iterator(const Iterator & instance): _ptr(instance._ptr) {};
			~Iterator(void) {};

			// Convert from iterator to const_iterator
			operator Iterator<const T>(void) const {
				return Iterator<const T>(this->_ptr);
			};

			Iterator&	operator=(Iterator const & instance) {
				if (this != &instance)
					this->_ptr = instance.base();
				return *this;
			};

			pointer		base(void) const {
				return this->_ptr;
			}

			Iterator&	operator++(void) {
				this->_ptr++;
				return *this;
			};

			Iterator	operator++(int) {
				Iterator tmp = *this;
				++(*this);
				return tmp;
			}

			Iterator&	operator--(void) {
				this->_ptr--;
				return *this;
			};

			Iterator	operator--(int) {
				Iterator tmp = *this;
				--(*this);
				return tmp;
			}

			Iterator&	operator+=(difference_type n) {
				this->_ptr += n;
				return *this;
			}

			Iterator&	operator-=(difference_type n) {
				this->_ptr -= n;
				return *this;
			}

			reference	operator[](int index) const {
				return *(this->_ptr + index);
			}

			reference	operator*(void) {
				return *(this->_ptr);
			}

			reference	operator*(void) const {
				return *(this->_ptr);
			}

			pointer		operator->(void) const {
				return this->_ptr;
			}

			Iterator	operator+(difference_type n) const {
				return Iterator(this->_ptr + n);
			}

			Iterator	operator-(difference_type n) const {
				return Iterator(this->_ptr - n);
			}

			friend Iterator operator+(int nb, const Iterator & it) {
                Iterator tmp = it;

                return (tmp += nb);
            }

			friend Iterator operator-(const Iterator & it1, const Iterator & it2) {
				return Iterator(it1 - it2);
            }

			friend bool	operator==(Iterator const & it1, Iterator const & it2) {
				return it1.base() == it2.base();
			}

			friend bool	operator!=(Iterator const & it1, Iterator const & it2) {
				return it1.base() != it2.base();
			}
			
			friend bool	operator<(Iterator const & it1, Iterator const & it2) {
				return it1.base() < it2.base();
			}
			
			friend bool	operator>(Iterator const & it1, Iterator const & it2) {
				return it1.base() > it2.base();
			}
			
			friend bool	operator>=(Iterator const & it1, Iterator const & it2) {
				return it1.base() >= it2.base();
			}
			
			friend bool	operator<=(Iterator const & it1, Iterator const & it2) {
				return it1.base() <= it2.base();
			}

		private:
			pointer		_ptr;
	};

	template <typename T, class Compare>
	class	bst_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
		public:
			
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef T*																				pointer;
			typedef T&																				reference;
			typedef ft::Node<T>																		Node;

			bst_iterator(void): _current(NULL), _root(NULL), _first(NULL), _last(NULL) {};
			bst_iterator(Node * current, Node * root)
			: _current(current), _root(root) {
				this->_first = this->_getFirst(root);
				this->_last = this->_getLast(root);
			};
			bst_iterator(const bst_iterator & instance) {
				*this = instance;
			};
			~bst_iterator(void) {};

			Node* base(void) const {
				return this->_current;
			};

			bst_iterator&	operator=(const bst_iterator & instance) {
				if (this != &instance) {
					this->_current = instance._current;
					this->_first = instance._first;
					this->_last = instance._last;
					this->_root = instance._root;
				}
				return *this;
			};

			bool		operator==(bst_iterator const & instance) const {
				return this->_current == instance._current;
			}

			bool		operator!=(bst_iterator const & instance) const {
				return !(*this == instance);
			}

			bst_iterator&	operator++(void) {
				Node* tmp;

				if (this->_current->left == NULL && this->_current->right == NULL)
					this->_current = this->_current->parent;
				else if (this->_current != this->_last) {
					if (this->_current->right->left != NULL && this->_current->right->right != NULL) {
						this->_current = this->_current->right;

						while (this->_current->left->left != NULL && this->_current->left->right != NULL)
							this->_current = this->_current->left;
					}
					else {
						tmp = this->_current->parent;
						while ((tmp->left != NULL && tmp->right != NULL) && this->_current == tmp->right) {
							this->_current = tmp;
							tmp = tmp->parent;
						}
						this->_current = tmp;
					}
				}
				else
					this->_current = this->_current->right;

				return *this;
			};

			bst_iterator	operator++(int) {
				bst_iterator instance = *this;
				Node* tmp;

				if (this->_current->left == NULL && this->_current->right == NULL)
					this->_current = this->_current->parent;
				else if (this->_current != this->_last) {
					if (this->_current->right->left != NULL && this->_current->right->right != NULL) {
						this->_current = this->_current->right;

						while (this->_current->left->left != NULL && this->_current->left->right != NULL)
							this->_current = this->_current->left;
					}
					else {
						tmp = this->_current->parent;
						while ((tmp->left != NULL && tmp->right != NULL) && this->_current == tmp->right) {
							this->_current = tmp;
							tmp = tmp->parent;
						}
						this->_current = tmp;
					}
				}
				else
					this->_current = this->_current->right;

				return instance;
			};

			bst_iterator&	operator--(void) {
				Node* tmp;

				if (this->_current->left == NULL && this->_current->right == NULL)
					this->_current = this->_current->parent;
				else if (this->_current != this->_first) {
					if (this->_current->right->left != NULL && this->_current->right->right != NULL) {
						this->_current = this->_current->left;

						while (this->_current->left->left != NULL && this->_current->left->right != NULL)
							this->_current = this->_current->right;
					}
					else {
						tmp = this->_current->parent;
						while ((tmp->left != NULL && tmp->right != NULL) && this->_current == tmp->left) {
							this->_current = tmp;
							tmp = tmp->parent;
						}
						this->_current = tmp;
					}
				}
				else
					this->_current = this->_current->left;
				return *this;
			};

			bst_iterator	operator--(int) {
				bst_iterator instance = *this;
				Node* tmp;

				if (this->_current->left == NULL && this->_current->right == NULL)
					this->_current = this->_current->parent;
				else if (this->_current != this->_first) {
					if (this->_current->right->left != NULL && this->_current->right->right != NULL) {
						this->_current = this->_current->left;

						while (this->_current->left->left != NULL && this->_current->left->right != NULL)
							this->_current = this->_current->right;
					}
					else {
						tmp = this->_current->parent;
						while ((tmp->left != NULL && tmp->right != NULL) && this->_current == tmp->left) {
							this->_current = tmp;
							tmp = tmp->parent;
						}
						this->_current = tmp;
					}
				}
				else
					this->_current = this->_current->left;
				return instance;
			};

			reference	operator*(void) const {
				return this->_current->data;
			};

			pointer		operator->(void) const {
				return &this->_current->data;
			};

		private:
			Node*	_current;
			Node*	_root;
			Node*	_first;
			Node*	_last;

			Node*		_getFirst(Node * root) {
				if (root->left->left == NULL && root->left->right == NULL)
					return root;
				return _getFirst(root->left);
			}

			Node*		_getLast(Node * root) {
				if (root->right->left == NULL && root->right->right == NULL)
					return root;
				return _getLast(root->right);
			}
	};

	template <class Iterator>
	class reverse_iterator: public std::iterator <
		typename ft::iterator_traits<Iterator>::iterator_category,
		typename ft::iterator_traits<Iterator>::value_type,
		typename ft::iterator_traits<Iterator>::difference_type,
		typename ft::iterator_traits<Iterator>::pointer,
		typename ft::iterator_traits<Iterator>::reference
	> {
		protected:
			Iterator	_current;

		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;

			reverse_iterator(void) {};
			reverse_iterator(iterator_type it): _current(it) {};
			reverse_iterator(const reverse_iterator & instance): _current(instance._current) {};
			~reverse_iterator(void) {};

			operator reverse_iterator<const Iterator>(void) const {
				return reverse_iterator<const Iterator>(this->_current);
			};

			iterator_type		base(void) const {
				return this->_current;
			};

			reverse_iterator&	operator=(const reverse_iterator & instance) {
				this->_current = instance._current;
				return *this;
			};

			reverse_iterator&	operator++(void) {
				--_current;
				return *this;
			};

			reverse_iterator	operator++(int) {
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			};

			reverse_iterator&	operator--(void) {
				++_current;
				return *this;
			};

			reverse_iterator	operator--(int) {
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			};

			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator(_current - n);
			};

			friend reverse_iterator operator+(int nb, const reverse_iterator & it) {
                reverse_iterator tmp = it;

                return (tmp += nb);
            };

			reverse_iterator&	operator+=(difference_type n) {
				_current -= n;
				return *this;
			};

			reverse_iterator	operator-(difference_type n) const {
				return reverse_iterator(_current + n);
			};

			reverse_iterator&	operator-=(difference_type n) {
				_current += n;
				return *this;
			};

			reference			operator[](difference_type n) const {
				return *(*this + n);
			};

			reference			operator*(void) const {
				Iterator tmp = this->_current;

				return *(--tmp);
			}

			pointer		operator->(void) const {
				return &(operator*());
			}

			friend reverse_iterator operator-(const reverse_iterator & it1, const reverse_iterator & it2) {
				return reverse_iterator(it1 - it2);
            };

			friend bool	operator==(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() == it2.base();
			}

			friend bool	operator!=(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() != it2.base();
			}
			
			friend bool	operator<(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() < it2.base();
			}
			
			friend bool	operator>(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() > it2.base();
			}
			
			friend bool	operator>=(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() >= it2.base();
			}
			
			friend bool	operator<=(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() <= it2.base();
			}
	};
};

#endif