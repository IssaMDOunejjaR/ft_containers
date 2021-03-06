/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:05:27 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/12 11:06:16 by iounejja         ###   ########.fr       */
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
			typedef ft::Node<value_type>						Node;
			typedef ft::bst_iterator<value_type, Node>			iterator;
			typedef ft::bst_iterator<const value_type, Node>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

			// Contructors and Destructor
			explicit set (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
			: _allocator(alloc), _comp(comp) {};

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _comp(comp) {
				while(first != last) {
					this->insert(*first);
					first++;
				}
			};

			set (const set & x) {
				*this = x;
			};

			~set (void) {
				this->_tree.clear();
			};

			// Operators overloads
			set&	operator=(const set & x) {
				if (this != &x) {
					this->clear();

					if (x.size() > 0)
						this->insert(x.begin(), x.end());
					this->_allocator = x._allocator;
					this->_comp = x._comp;
				}
				return *this;
			};

			// Iterators
			iterator	begin(void) {
				return iterator(this->_tree.firstElement(), this->_tree.getRoot());
			};

			const_iterator	begin(void) const {
				return const_iterator(this->_tree.firstElement(), this->_tree.getRoot());
			};

			iterator	end(void) {
				Node* node = this->_tree.lastElement();

				if (node->left == NULL && node->right == NULL)
					return iterator(node, this->_tree.getRoot());
				
				return iterator(node->right, this->_tree.getRoot());
			};

			const_iterator	end(void) const {
				Node* node = this->_tree.lastElement();

				if (node->left == NULL && node->right == NULL)
					return iterator(node, this->_tree.getRoot());

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
				return this->_tree.size();
			};

			size_type	max_size(void) const {
				return this->_tree.getAllocator().max_size();
			};

			// Modifiers
			ft::pair<iterator, bool>	insert(const value_type & val) {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data == val)
						break ;
					if (val < node->data)
						node = node->left;
					else if (val > node->data)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL)
					return ft::pair<iterator, bool>(iterator(node, this->_tree.getRoot()), false);
				return ft::pair<iterator, bool>(iterator(this->_tree.insert(val), this->_tree.getRoot()), true);
			};

			iterator	insert(iterator position, const value_type & val) {
				ft::pair<iterator, bool>	res;

				(void)position;
				res = this->insert(val);
				return res.first;
			};

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) {
				while (first != last) {
					this->_tree.insert(*first);
					first++;
				}
			};

			void	erase(iterator position) {
				iterator it = this->begin();

				while (it != position)
					it++;
				this->_tree.del(*it);
			};

			size_type	erase(const value_type & val) {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data == val)
						break ;
					if (val < node->data)
						node = node->left;
					else if (val > node->data)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL) {
					this->_tree.del(node->data);
					return 1;
				}
				return 0;
			};

			void	erase(iterator first, iterator last) {
				while (first != last) {
					this->_tree.del(*first);
					first++;
				}
			};

			void	swap(set & x) {
				set tmp;

				tmp = *this;
				*this = x;
				x = tmp;
			};

			void	clear(void) {
				this->_tree.clear();
				this->_tree = ft::RedBlackTree<value_type, Node>();
			};

			// Observers
			key_compare	key_comp(void) const {
				return key_compare();
			};

			key_compare	value_comp(void) const {
				return value_compare();
			};

			// Operations
			iterator	find(const value_type & val) const {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data == val)
						break ;
					else if (val < node->data)
						node = node->left;
					else if (val > node->data)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL)
					return iterator(node, this->_tree.getRoot());
				return iterator(node, this->_tree.getRoot());
			};

			size_type	count(const value_type & val) const {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data == val)
						break ;
					else if (val < node->data)
						node = node->left;
					else if (val > node->data)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL)
					return 1;
				return 0;
			};

			iterator	lower_bound(const value_type & val) const {
				iterator itb = iterator(this->_tree.firstElement(), this->_tree.getRoot());
				iterator ite = iterator(this->_tree.lastElement(), this->_tree.getRoot());

				while (itb != ite) {
					if (!this->_comp(*itb, val))
						return itb;
					itb++;
				}

				return ite;
			};

			iterator	upper_bound(const value_type & val) const {
				iterator itb = iterator(this->_tree.firstElement(), this->_tree.getRoot());
				iterator ite = iterator(this->_tree.lastElement(), this->_tree.getRoot());

				while (itb != ite) {
					if (this->_comp(val, *itb))
						return itb;
					itb++;
				}

				return ite;
			};

			ft::pair<iterator, iterator>	equal_range(const value_type & val) const {
				return ft::pair<iterator, iterator>(lower_bound(val), upper_bound(val));
			};

			// Allocator
			allocator_type	get_allocator(void) const {
				return this->_allocator;
			};

			friend	bool	operator==(const set & lhs, const set & rhs) {
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			};

			friend	bool	operator!=(const set & lhs, const set & rhs) {
				return !(lhs == rhs);
			};

			friend	bool	operator<(const set & lhs, const set & rhs) {
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			};

			friend	bool	operator<=(const set & lhs, const set & rhs) {
				return lhs < rhs || lhs == rhs;
			};

			friend	bool	operator>(const set & lhs, const set & rhs) {
				return rhs < lhs;
			};

			friend	bool	operator>=(const set & lhs, const set & rhs) {
				return lhs > rhs || lhs == rhs;
			};

		private:
			Alloc								_allocator;
			Compare								_comp;
			ft::RedBlackTree<value_type, Node>	_tree;
	};
};

#endif