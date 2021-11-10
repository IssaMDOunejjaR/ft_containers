/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:42:02 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/10 10:44:28 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {
	// template <typename T>
	// void	swap(T & a, T & b) {
	// 	T tmp;

	// 	tmp = a;
	// 	a = b;
	// 	b = tmp;
	// }

	template <class T1, class T2>
	struct	pair {
		typedef T1	key;
		typedef T2	value;

		T1	first;
		T2	second;

		pair(void): first(), second() {};

		pair(T1 const & first, T2 const & second): first(first), second(second) {};

		template <class U, class V>
		pair(const pair<U, V> &p) : first(p.first), second(p.second) {}

		~pair(void) {};

		pair&	operator=(pair const & instance) {
			if (this != &instance) {
				this->first = instance.first;
				this->second = instance.second;
			}
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
	bool	equal(IteratorInput1 first1, IteratorInput1 last1, IteratorInput2 first2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	};

	template <class IteratorInput1, class IteratorInput2, class BinaryPredicate>
	bool	equal(IteratorInput1 first1, IteratorInput1 last1, IteratorInput2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	};

	template <class IteratorInput1, class IteratorInput2>
	bool	lexicographical_compare(IteratorInput1 first1, IteratorInput1 last1, IteratorInput2 first2, IteratorInput2 last2) {
		while (first1 != last1 && first2 != last2) {
			if (*first1 < *first2)	return true;
			if (*first2 < *first1)	return false;
			first1++;
			first2++;
		}
		return (first1 == last1) && (first2 != last2);
	};

	template <class IteratorInput1, class IteratorInput2, class Compare>
	bool	lexicographical_compare(IteratorInput1 first1, IteratorInput1 last1, IteratorInput2 first2, IteratorInput2 last2, Compare comp) {
		while (first1 != last1 && first2 != last2) {
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
			first1++;
			first2++;
		}
		return (first1 == last1) && (first2 != last2);
	};

	template <bool Cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { typedef T type; };

	template<class T, T v>
	struct integral_constant {
		static const T	value = v;

		typedef T					value_type;
		typedef integral_constant	type;

		operator value_type() const {
			return value;
		}
	};

	typedef	integral_constant<bool, true>	true_type;
	typedef	integral_constant<bool, false>	false_type;

	template <class T>
	struct is_integral: public false_type {};

	template <>
	struct is_integral<bool>: public true_type {};

	template <>
	struct is_integral<char>: public true_type {};

	template <>
	struct is_integral<char16_t>: public true_type {};

	template <>
	struct is_integral<char32_t>: public true_type {};

	template <>
	struct is_integral<wchar_t>: public true_type {};

	template <>
	struct is_integral<short int>: public true_type {};

	template <>
	struct is_integral<int>: public true_type {};

	template <>
	struct is_integral<long int>: public true_type {};

	template <>
	struct is_integral<long long int>: public true_type {};

	template <>
	struct is_integral<unsigned char>: public true_type {};

	template <>
	struct is_integral<unsigned short int>: public true_type {};

	template <>
	struct is_integral<unsigned int>: public true_type {};

	template <>
	struct is_integral<unsigned long int>: public true_type {};

	template <>
	struct is_integral<unsigned long long int>: public true_type {};

	template <>
	struct is_integral<signed char>: public true_type {};
}

#endif