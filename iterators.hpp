/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:41:48 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/12 10:52:52 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include "red_black_tree.hpp"

namespace ft {
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <
		typename Category,
		typename T,
		typename Distance = ptrdiff_t,
		typename Pointer = T*,
		typename Reference = T&
	>
	struct iterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
	
	};

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
		typedef std::ptrdiff_t 					difference_type;
		typedef T 								value_type;
		typedef T* 								pointer;
		typedef T& 								reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t 						difference_type;
		typedef T 								value_type;
		typedef T* 								pointer;
		typedef T& 								reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <typename T>
	class Iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef T*																				pointer;
			typedef T&																				reference;

			Iterator(void) {};

			Iterator(pointer ptr): _ptr(ptr) {};

			template <class Iter>
			Iterator(const Iterator<Iter> & instance): _ptr(instance._ptr) {};

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

			friend difference_type operator-(const Iterator & it1, const Iterator & it2) {
				return it1.base() - it2.base();
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

	template <class T, class Node>
	class	bst_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		public:
			
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef T*																				pointer;
			typedef T&																				reference;

			bst_iterator(void): _current(NULL), _root(NULL), _first(NULL), _last(NULL) {};

			bst_iterator(Node * current, Node * root)
			: _current(current), _root(root) {
				this->_first = this->_getFirst(root);
				this->_last = this->_getLast(root);
			};

			template <class Iter>
			bst_iterator(const Iter & instance) {
				*this = instance;
			};

			~bst_iterator(void) {};

			bst_iterator&	operator=(const bst_iterator & instance) {
				if (this != &instance) {
					this->_current = instance._current;
					this->_first = instance._first;
					this->_last = instance._last;
					this->_root = instance._root;
				}
				return *this;
			};

			operator bst_iterator<const T, Node>(void) const {
				return bst_iterator<const T, Node>(this->_current, this->_root);
			};

			Node* base(void) const {
				return this->_current;
			};

			bool	operator==(bst_iterator const & instance) const {
				return this->_current == instance._current;
			}

			bool	operator!=(bst_iterator const & instance) const {
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

		protected:
			Node*	_current;
			Node*	_root;
			Node*	_first;
			Node*	_last;

			Node*		_getFirst(Node * root) {
				if (root->left == NULL && root->right == NULL)
					return root;

				while (root->left->left != NULL && root->left->right != NULL)
					root = root->left;

				return root;
			}

			Node*		_getLast(Node * root) {
				if (root->left == NULL && root->right == NULL)
					return root;

				while (root->right->left != NULL && root->right->right != NULL)
					root = root->right;

				return root;
			}
	};
	
	template <class Iterator>
	class reverse_iterator: public ft::iterator <
		typename ft::iterator_traits<Iterator>::iterator_category,
		typename ft::iterator_traits<Iterator>::value_type,
		typename ft::iterator_traits<Iterator>::difference_type,
		typename ft::iterator_traits<Iterator>::pointer,
		typename ft::iterator_traits<Iterator>::reference
	> {
		Iterator	_current;

		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;

			reverse_iterator(void) {};

			reverse_iterator(iterator_type it): _current(it) {};

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> & instance): _current(instance.base()) {};

			~reverse_iterator(void) {};

			iterator_type		base(void) const {
				return this->_current;
			};

			reverse_iterator&	operator=(const reverse_iterator & instance) {
				if (this != &instance)
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

			friend difference_type operator-(const reverse_iterator & it1, const reverse_iterator & it2) {
				return it2.base() - it1.base();
            };

			friend reverse_iterator operator+(difference_type n, const reverse_iterator & it) {
				return reverse_iterator(it.base() - n);
            };

			friend bool	operator==(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() == it2.base();
			}

			friend bool	operator!=(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() != it2.base();
			}
			
			friend bool	operator<(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() > it2.base();
			}
			
			friend bool	operator>(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() < it2.base();
			}
			
			friend bool	operator>=(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() <= it2.base();
			}
			
			friend bool	operator<=(reverse_iterator const & it1, reverse_iterator const & it2) {
				return it1.base() >= it2.base();
			}
	};

	template <class Iter1, class Iter2>
	bool	operator!=(Iter1 const & it1, Iter2 const & it2) {
		return it1.base() != it2.base();
	}
};

#endif