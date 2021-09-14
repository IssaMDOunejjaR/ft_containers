/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:41:48 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/12 16:52:07 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

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
	class MyIterator {
		// typedef T				value_type;
		// typedef value_type*		pointer;
		// typedef value_type&		reference;

		public:

			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef ptrdiff_t					difference_type;
			typedef random_access_iterator_tag	iterator_category;

			MyIterator(void) {};
			MyIterator(pointer ptr): _ptr(ptr) {};
			MyIterator(MyIterator const & instance) {
				*this = instance;
			};
			~MyIterator(void) {};

			MyIterator&		operator=(MyIterator const & instance) {
				this->_ptr = instance._ptr;
				return *this;
			};

			MyIterator&	operator++(void) {
				this->_ptr++;
				return *this;
			};

			MyIterator	operator++(int) {
				MyIterator tmp = *this;
				++(*this);
				return tmp;
			}

			MyIterator&	operator--(void) {
				this->_ptr--;
				return *this;
			};

			MyIterator	operator--(int) {
				MyIterator tmp = *this;
				--(*this);
				return tmp;
			}

			MyIterator&	operator+=(MyIterator const & instance) {
				this->_ptr += instance._ptr;
				return *this;
			}

			MyIterator&	operator-=(MyIterator const & instance) {
				this->_ptr += instance._ptr;
				return *this;
			}

			reference	operator[](int index) {
				return *(this->_ptr + index);
			}

			bool		operator==(MyIterator const & instance) const {
				return this->_ptr == instance._ptr;
			}

			bool		operator!=(MyIterator const & instance) const {
				return !(*this == instance);
			}

			reference	operator*(void) {
				return *(this->_ptr);
			}

			reference	operator*(void) const {
				return *(this->_ptr);
			}

			bool		operator<(MyIterator const & instance) const {
				return this->_ptr < instance._ptr;
			}

			bool		operator<=(MyIterator const & instance) const {
				return this->_ptr <= instance._ptr;
			}

			bool		operator>(MyIterator const & instance) const {
				return this->_ptr > instance._ptr;
			}

			bool		operator>=(MyIterator const & instance) const {
				return this->_ptr >= instance._ptr;
			}

			pointer		operator->(void) const {
				return this->_ptr;
			}

			MyIterator	operator+(MyIterator const & instance) {
				return MyIterator(this->_ptr + instance._ptr);
			}
			
			MyIterator	operator+(int val) {
				return MyIterator(this->_ptr + val);
			}

			MyIterator	operator-(MyIterator const & instance) {
				return MyIterator(this->_ptr - instance._ptr);
			}

			MyIterator	operator-(int val) {
				return MyIterator(this->_ptr - val);
			}

		private:
			pointer		_ptr;
	};

	template <class Iterator>
	class reverse_iterator: public iterator <
		typename ft::iterator_traits<Iterator>::iterator_category,
		typename ft::iterator_traits<Iterator>::value_type,
		typename ft::iterator_traits<Iterator>::difference_type,
		typename ft::iterator_traits<Iterator>::pointer,
		typename ft::iterator_traits<Iterator>::reference
	> {
		private:
			Iterator	current;

		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;

			reverse_iterator(void) {};

			reverse_iterator(iterator_type it): current(it) {};

			reverse_iterator(reverse_iterator const & instance) {
				*this = instance;
			};

			~reverse_iterator(void) {};

			iterator_type		base(void) const {
				return current;
			};

			reverse_iterator&	operator=(reverse_iterator const & instance) {
				this->current = instance.current;
				return *this;
			};

			reverse_iterator&	operator++(void) {
				--current;
				return *this;
			};

			reverse_iterator	operator++(int) {
				reverse_iterator tmp = *this;
				--current;
				return tmp;
			};

			reverse_iterator&	operator--(void) {
				++current;
				return *this;
			};

			reverse_iterator	operator--(int) {
				reverse_iterator tmp = this;
				++current;
				return tmp;
			};

			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator(current - n);
			};

			reverse_iterator&	operator+=(difference_type n) {
				current -= n;
				return *this;
			};

			reverse_iterator	operator-(difference_type n) const {
				return reverse_iterator(current + n);
			};

			reverse_iterator&	operator-=(difference_type n) {
				current += n;
				return *this;
			};

			reference			operator[](difference_type n) const {
				return *(*this + n);
			};

			reference			operator*(void) {
				Iterator tmp = current;
				return *--tmp;
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

	template <class IteratorInput1, class IteratorInput2>
	bool	equal(IteratorInput1 first1, IteratorInput1 last1, IteratorInput2 first2, IteratorInput2 last2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	};

	template <class IteratorInput1, class IteratorInput2>
	bool	lexicographical_compare(IteratorInput1 first1, IteratorInput1 last1, IteratorInput2 first2, IteratorInput2 last2) {
		while (first1 != last1 && first2 != last2) {
			// if (*first1 < *first2)
			// 	return true;
			if (*first2 < *first1)
				return false;
			first1++;
			first2++;
		}
		return (first1 == last1) && (first2 != last2);
	};

	template <class T1, class T2>
	struct	pair {
		T1	first;
		T2	second;

		pair(void) {};
		pair(T1 const & first, T2 const & second) {
			this->first = first;
			this->second = second;
		};
		template <class U, class V>
		pair(pair<U, V> const & instance) {
			*this = instance;
		};
		~pair(void) {};

		pair&	operator=(pair const & instance) {
			this->first = instance.first;
			this->second = instance.second;
			return *this;
		};
	};

	template <class T1, class T2>
	bool	operator==(pair<T1, T2> const & lhs, pair<T1, T2> const & rhs) {
		return (lhs.first == rhs.first) && (lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool	operator!=(pair<T1, T2> const & lhs, pair<T1, T2> const & rhs) {
		return !(lhs == rhs);
	};

	template <class T1, class T2>
	bool	operator<(pair<T1, T2> const & lhs, pair<T1, T2> const & rhs) {
		return (lhs.first < rhs.first) && (lhs.second < rhs.second);
	};

	template <class T1, class T2>
	bool	operator<=(pair<T1, T2> const & lhs, pair<T1, T2> const & rhs) {
		return (lhs.first <= rhs.first) && (lhs.second <= rhs.second);
	};

	template <class T1, class T2>
	bool	operator>(pair<T1, T2> const & lhs, pair<T1, T2> const & rhs) {
		return rhs < lhs;
	};

	template <class T1, class T2>
	bool	operator>=(pair<T1, T2> const & lhs, pair<T1, T2> const & rhs) {
		return (lhs.first >= rhs.first) && (lhs.second >= rhs.second);
	};

	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y) {
		return pair<T1, T2>(x, y);
	};
};

#endif