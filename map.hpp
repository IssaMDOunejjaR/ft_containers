/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:03:47 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/26 11:51:26 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "iterators.hpp"
# include "utility.hpp"
# include "red_black_tree.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> >
	>
	class map {
		public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef ft::pair<key_type, mapped_type>								value_type;
			typedef Compare														key_compare;
			// value_compare
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::bst_iterator<value_type, Compare>						iterator;
			typedef ft::bst_iterator<const value_type, Compare>					const_iterator;
			// typedef typename ft::RedBlackTree<value_type, Compare>::iterator	iterator;
			// typedef ft::RedBlackTree<const value_type, Compare>					const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef ptrdiff_t													difference_type;
			typedef size_t														size_type;

			typedef ft::Node<value_type>										Node;

			// Constructors and Destructor
			explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
			: _comp(comp), _allocator(alloc) {};

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
			: _comp(comp), _allocator(alloc) {
				while(first != last) {
					this->insert(*first);
					first++;
				}
			};

			map(const map & instance): _tree(instance._tree), _comp(instance._comp), _allocator(instance._allocator) {};

			~map(void) {};

			// Operators Overloads
			map&			operator=(const map & instance);

			mapped_type&	operator[](const key_type & k) {
				Node*	node = this->_tree.search(k);

				return node->data.second;
			};

			// Iterators
			iterator	begin(void) {
				return iterator(this->_tree.firstElement());
			};

			const_iterator	begin(void) const {
				return const_iterator(this->_tree.firstElement());
			};

			iterator	end(void) {
				Node* node = this->_tree.lastElement();
				
				return iterator(node->right);
			};

			const_iterator	end(void) const {
				Node* node = this->_tree.lastElement();

				return const_iterator(node->right);
			};

			reverse_iterator	rbegin(void) {
				return reverse_iterator(this->_tree.lastElement());
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
				return this->_tree.size();
			};

			size_type	max_size(void) const {
				return this->_allocator.max_size();
			};

			// Modifiers
			ft::pair<iterator, bool>	insert(value_type const & val) {
				Node*	node = this->_tree.search(val.first);
				if (node != this->_tree.getTNULL())
					return ft::pair<iterator, bool>(iterator(node), false);
				return ft::pair<iterator, bool>(iterator(this->_tree.insert(val)), true);
			};

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) {
				while (first != last) {
					this->_tree.insert(*first);
					first++;
				}
			};

		// 	void						swap(map & x);
		// 	void						clear(void);

		// 	// Observers
		// 	key_compare					key_comp(void) const;

		// 	// Operations
		// 	size_type					count(key_type const & k) const;
			
		// 	// Allocator
		// 	allocator_type				get_allocator(void) const {
		// 		return this->_allocator;
		// 	};

		private:
			Alloc									_allocator;
			Compare									_comp;
			ft::RedBlackTree<value_type, Compare>	_tree;
	};
};

#endif