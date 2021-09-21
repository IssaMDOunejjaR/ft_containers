/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:03:47 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/21 17:42:08 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "iterators.hpp"
# include "red-black-tree.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> >
	>
	class map {

		public:

			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<key_type, mapped_type>							value_type;
			typedef Node<value_type>										Node;
			typedef Compare													key_compare;
			typedef ft::bst_iterator<Node, value_type, Compare>				iterator;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			// typedef typename ft::iterator_traits<iterator<T> >::difference_type	difference_type;
			typedef size_t													size_type;

			// Constructors and Destructor
			explicit map(key_compare const & comp = key_compare(), allocator_type const & alloc = allocator_type()) {};
			template <class InputIterator>
			map(InputIterator first, InputIterator last, key_compare const & comp = key_compare(), allocator_type const & alloc = allocator_type());

			map(map const & instance) {
				*this = instance;
			};

			~map(void) {};

			// Operators Overloads
			map&			operator=(map const & instance);

			mapped_type&	operator[](key_type const & k);

			// Iterators
			iterator					begin(void) {
				Node*	tmp = this->_tree.firstElement();

				return iterator(tmp);
			};

			iterator					end(void);

			// Capacity
			bool						empty(void) const;

			size_type					size(void) const;

			size_type					max_size(void) const {
				return this->_allocator.max_size();
			};

			// Modifiers
			ft::pair<iterator, bool>	insert(value_type const & val) {
				return ft::pair<iterator, bool>(iterator(this->_tree.insert(val)), true);
			};

			template <class InputIterator>
			void						insert(InputIterator first, InputIterator last);

			void						swap(map & x);
			void						clear(void);

			// Observers
			key_compare					key_comp(void) const;

			// Operations
			size_type					count(key_type const & k) const;
			
			// Allocator
			allocator_type				get_allocator(void) const {
				return this->_allocator;
			};

		private:
			Alloc								_allocator;
			Compare								_comp;
			Tree<value_type, Compare>			_tree;
	};
};

#endif