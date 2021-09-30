/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:05:27 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/27 10:41:18 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <iostream>
# include "red_black_tree.hpp"
# include "iterators.hpp"
# include "utility.hpp"

namespace ft {
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:
			typedef T											key_type;
			typedef T											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::bst_iterator<value_type, Compare>		iterator;
			typedef ft::bst_iterator<const value_type, Compare>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

			// Contructors and Destructor
			explicit set (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
			: _Comp(comp), _allocator(alloc) {};

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _Comp(comp), _allocator(alloc) {};

			set (const set & x) {};

			~set (void) {};

			// Operators overloads
			set&	operator=(const set & x) {
				return *this;
			};

			// Iterators
			iterator	begin(void);
			const_iterator	begin(void) const;
			iterator	end(void);
			const_iterator	end(void) const;
			reverse_iterator	rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator	rend(void);
			const_reverse_iterator	rend(void) const;

			// Capacity
			bool	empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

			// Modifiers
			ft::pair<iterator, bool>	insert(const value_type & val);
			iterator	insert(iterator position, const value_type & val);
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last);
			void	erase(iterator position);
			size_type	erase(const value_type & val);
			void	erase(iterator first, iterator last);
			void	swap(set & x);
			void	clear(void);

			// Observers
			key_compare	key_comp(void) const;
			key_compare	value_comp(void) const;

			// Operations
			iterator	find(const value_type & val) const;
			size_type	count(const value_type & val) const;
			iterator	lower_bound(const value_type & val) const;
			iterator	upper_bound(const value_type & val) const;
			ft::pair<iterator, iterator>	equal_range(const value_type & val) const;

			// Allocator
			allocator_type	get_allocator(void) const;

		private:
			Alloc								_allocator;
			Compare								_Comp;
			ft::RedBlackTree<value_type, Comp>	_tree;
	};
};

#endif