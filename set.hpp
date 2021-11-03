/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:05:27 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/03 09:40:08 by iounejja         ###   ########.fr       */
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

			typedef ft::Node<value_type>										Node;

			// Contructors and Destructor
			explicit set (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
			: _Comp(comp), _allocator(alloc) {};

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _Comp(comp), _allocator(alloc) {};

			set (const set & x) {
				*this = x;
			};

			~set (void) {
				this->clear();
			};

			// Operators overloads
			set&	operator=(const set & x) {
				if (this != &instance) {
					this->_allocator = x._allocator;
					this->_Comp = x._Comp;
					this->_tree = x._tree;
				}
				return *this;
			};

			// Iterators
			iterator	begin(void) {
				return iterator(this->_tree.firstElement(), this->_tree.getRoot());
			};

			const_iterator	begin(void) const {
				return const_iterator(this->_tree.firstElement(), this->_tree.getRoot())
			};

			iterator	end(void) {
				Node* node = this->_tree.lastElement();
				
				return iterator(node->right, this->_tree.getRoot());
			};

			const_iterator	end(void) const {
				Node* node = this->_tree.lastElement();

				return const_iterator(node->right, this->_tree.getRoot());
			};

			reverse_iterator	rbegin(void) {
				return reverse_iterator(this->end());
			}

			const_reverse_iterator	rbegin(void) const {
				return const_reverse_iterator(this->end());
			}

			reverse_iterator	rend(void) {
				return reverse_iterator(this->begin());
			}

			const_reverse_iterator	rend(void) const {
				return const_reverse_iterator(this->begin());
			}

			// Capacity
			bool	empty(void) const {
				return this->_tree.size() == 0;
			};

			size_type	size(void) const {
				return this->_tree.size() == 0;
			};

			size_type	max_size(void) const {
				return this->_allocator.max_size();
			};

			// Modifiers
			ft::pair<iterator, bool>	insert(const value_type & val);
			iterator	insert(iterator position, const value_type & val);
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last);
			void	erase(iterator position);
			size_type	erase(const value_type & val);
			void	erase(iterator first, iterator last);

			void	swap(set & x) {
				set tmp;

				tmp = *this;
				*this = x;
				x = tmp;
			};

			void	clear(void) {
				this->_tree.clear();
			};

			// Observers
			key_compare	key_comp(void) const {
				return key_compare();
			};

			key_compare	value_comp(void) const {
				return value_compare(key_compare());
			};

			// Operations
			iterator	find(const value_type & val) const;
			size_type	count(const value_type & val) const;
			iterator	lower_bound(const value_type & val) const;
			iterator	upper_bound(const value_type & val) const;
			ft::pair<iterator, iterator>	equal_range(const value_type & val) const;

			// Allocator
			allocator_type	get_allocator(void) const {
				return this->_allocator;
			};

		private:
			Alloc								_allocator;
			Compare								_Comp;
			ft::RedBlackTree<value_type, Comp>	_tree;
	};
};

#endif