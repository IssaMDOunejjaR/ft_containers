/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:42:02 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/23 12:18:18 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {
	template <class T1, class T2>
	struct	pair {
		typedef	T1	key;
		typedef	T2	value;

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

	template <bool Cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <class T>
	struct is_integral: public std::integral_constant<T> {};

	// template <class T>
	// struct less: std::binary_function<T, T, bool> {
	// 	bool	operator()(const T & x, const T & y) const {
	// 		return x < y;
	// 	};
	// };
}

#endif