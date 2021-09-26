/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:41:48 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/26 12:21:36 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include "red_black_tree.hpp"

namespace ft {

	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <
		class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&
	>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef	Reference	reference;
		typedef Category	iterator_category;
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
		typedef ptrdiff_t 					difference_type;
		typedef T 							value_type;
		typedef T* 							pointer;
		typedef T& 							reference;
		typedef random_access_iterator_tag 	iterator_category;
	};

	template <typename T>
	class Iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
		public:

			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef T*																			pointer;
			typedef T&																			reference;

			Iterator(void) {};
			Iterator(pointer ptr): _ptr(ptr) {};
			Iterator(const Iterator & instance): _ptr(instance._ptr) {};
			~Iterator(void) {};

			pointer		base(void) const {
				return this->_ptr;
			}

			Iterator&	operator=(Iterator const & instance) {
				if (this == &instance)
					return *this;
				this->_ptr = instance._ptr;
				return *this;
			};

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

			Iterator&	operator+=(Iterator const & instance) {
				this->_ptr += instance._ptr;
				return *this;
			}

			Iterator&	operator-=(Iterator const & instance) {
				this->_ptr += instance._ptr;
				return *this;
			}

			reference	operator[](int index) const {
				return *(this->_ptr + index);
			}

			// bool		operator==(Iterator const & instance) const {
			// 	return this->_ptr == instance._ptr;
			// }

			// bool		operator!=(Iterator const & instance) const {
			// 	return !(*this == instance);
			// }

			reference	operator*(void) {
				return *(this->_ptr);
			}

			reference	operator*(void) const {
				return *(this->_ptr);
			}

			// bool		operator<(Iterator const & instance) const {
			// 	return this->_ptr < instance._ptr;
			// }

			// bool		operator<=(Iterator const & instance) const {
			// 	return this->_ptr <= instance._ptr;
			// }

			// bool		operator>(Iterator const & instance) const {
			// 	return this->_ptr > instance._ptr;
			// }

			// bool		operator>=(Iterator const & instance) const {
			// 	return this->_ptr >= instance._ptr;
			// }

			pointer		operator->(void) const {
				return this->_ptr;
			}

			Iterator	operator+(difference_type n) const {
				return this->_ptr + n;
			}

			Iterator	operator-(difference_type n) const {
				return this->_ptr - n;
			}

		private:
			pointer		_ptr;
	};

	template <class Iterator1, class Iterator2>
	bool	operator==(ft::Iterator<Iterator1> const & it1, ft::Iterator<Iterator2> const & it2) {
		return it1.base() == it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator!=(ft::Iterator<Iterator1> const & it1, ft::Iterator<Iterator2> const & it2) {
		return it1.base() != it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator<(ft::Iterator<Iterator1> const & it1, ft::Iterator<Iterator2> const & it2) {
		return it1.base() < it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator>(ft::Iterator<Iterator1> const & it1, ft::Iterator<Iterator2> const & it2) {
		return it1.base() > it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator>=(ft::Iterator<Iterator1> const & it1, ft::Iterator<Iterator2> const & it2) {
		return it1.base() >= it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator<=(ft::Iterator<Iterator1> const & it1, ft::Iterator<Iterator2> const & it2) {
		return it1.base() <= it2.base();
	}

	template <typename T, class Compare>
	class	bst_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		public:
			
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
			typedef T*																			pointer;
			typedef T&																			reference;

			typedef ft::Node<T>																	Node;

			bst_iterator(void): _current(nullptr), _TNULL(nullptr), _root(nullptr), _first(nullptr), _last(nullptr) {};
			bst_iterator(Node * node): _current(node), _TNULL(node->right) {
				while (node->parent != NULL)
					node = node->parent;

				this->_root = node;
				this->_first = this->_getFirst(this->_root);
				this->_last = this->_getLast(this->_root);
			};
			bst_iterator(const bst_iterator & instance): _current(instance._current) {};
			~bst_iterator(void) {};

			Node* base(void) const {
				return this->_current;
			};

			bst_iterator&	operator=(const bst_iterator & instance) {
				if (this == &instance)
					return *this;
				this->_current = instance._current;
				this->_root = instance._root;
				this->_TNULL = instance._TNULL;
				return *this;
			};

			bool		operator==(bst_iterator const & instance) const {
				return this->_current == instance._current;
			}

			bool		operator!=(bst_iterator const & instance) const {
				return !(*this == instance);
			}

			bst_iterator&	operator++(void) {
				if (this->_current == this->_last)
					this->_current = this->_TNULL;
				else if (this->_current->right == this->_TNULL)
					this->_current = this->_current->parent;
				else
					this->_current = this->_inOrderSuccessor(this->_current->right);
				return *this;
			};

			bst_iterator	operator++(int) {
				bst_iterator tmp = *this;

				if (this->_current == this->_last)
					this->_current = this->_TNULL;
				else if (this->_current->right == this->_TNULL)
					this->_current = this->_current->parent;
				else
					this->_current = this->_inOrderSuccessor(this->_current->right);
				return tmp;
			};

			bst_iterator&	operator--(void) {
				if (this->_current == this->_first)
					this->_current = this->_TNULL;
				else if (this->_current->left == this->_TNULL)
					this->_current = this->_current->parent;
				else {
					std::cout << (this->_current->right == this->_TNULL) << std::endl;
					this->_current = this->_inOrderPredeccessor(this->_current->left);
				}
				return *this;
			};

			bst_iterator	operator--(int) {
				bst_iterator tmp = *this;

				if (this->_current == this->_last)
					this->_current = this->_TNULL;
				else if (this->_current->left == this->_TNULL)
					this->_current = this->_current->parent;
				else
					this->_current = this->_inOrderPredeccessor(this->_current->left);
				return tmp;
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
			Node*	_TNULL;

			Node*		_getFirst(Node * root) {
				if (root->left == this->_TNULL)
					return root;
				return _getFirst(root->left);
			}

			Node*		_getLast(Node * root) {
				if (root->right == this->_TNULL)
					return root;
				return _getLast(root->right);
			}

			Node*	_inOrderSuccessor(Node * node) {
				if (node->left == this->_TNULL)
					return node;
				return _inOrderSuccessor(node->left);
			};

			Node*	_inOrderPredeccessor(Node * node) {
				if (node->right == this->_TNULL)
					return node;
				return _inOrderPredeccessor(node->right);
			};
	};

	template <class Iterator>
	class reverse_iterator: public iterator <
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
	};

	template <class Iterator1, class Iterator2>
	bool	operator==(ft::reverse_iterator<Iterator1> const & it1, ft::reverse_iterator<Iterator2> const & it2) {
		return it1.base() == it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator!=(ft::reverse_iterator<Iterator1> const & it1, ft::reverse_iterator<Iterator2> const & it2) {
		return it1.base() != it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator<(ft::reverse_iterator<Iterator1> const & it1, ft::reverse_iterator<Iterator2> const & it2) {
		return it1.base() < it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator>(ft::reverse_iterator<Iterator1> const & it1, ft::reverse_iterator<Iterator2> const & it2) {
		return it1.base() > it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator>=(ft::reverse_iterator<Iterator1> const & it1, ft::reverse_iterator<Iterator2> const & it2) {
		return it1.base() >= it2.base();
	}
	
	template <class Iterator1, class Iterator2>
	bool	operator<=(ft::reverse_iterator<Iterator1> const & it1, ft::reverse_iterator<Iterator2> const & it2) {
		return it1.base() <= it2.base();
	}
};

#endif