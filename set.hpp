/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issamdounejjar <issamdounejjar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:05:27 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/09 11:40:30 by issamdounej      ###   ########.fr       */
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
			: _allocator(alloc), _comp(comp) {};

			set (const set & x) {
				*this = x;
			};

			~set (void) {
				this->clear();
			};

			// Operators overloads
			set&	operator=(const set & x) {
				if (this != &x) {
					this->clear();

					if (x.size() > 0)
						this->insert(x.begin(), x.end());
					this->_allocator = x._allocator;
					this->_Comp = x._Comp;
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
					if (node->data.first == k)
						break ;
					if (k < node->data.first)
						node = node->left;
					else if (k > node->data.first)
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
				if (this->size() > 0)
					this->_tree.clear();
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
				return this->end();
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
				Node*	root = this->_tree.getRoot();

				while (root != NULL) {
					if (!this->_comp(root->data, val))
						return iterator(root, this->_tree.getRoot());
					else
						root = root->right;
				}

				return this->end();
			};

			iterator	upper_bound(const value_type & val) const {
				Node*	root = this->_tree.getRoot();

				while (root != NULL) {
					if (this->_comp(val, root->data)) {
						if (root->left->left == NULL && root->left->right == NULL)
							return iterator(root, this->_tree.getRoot());
						root = root->left;
					}
					else if (root->right->left == NULL && root->right->right == NULL)
						return iterator(root->parent, this->_tree.getRoot());
					else
						root = root->right;
				}

				return this->end();
			};

			ft::pair<iterator, iterator>	equal_range(const value_type & val) const {
				return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			};

			// Allocator
			allocator_type	get_allocator(void) const {
				return this->_allocator;
			};

		private:
			Alloc								_allocator;
			Compare								_comp;
			ft::RedBlackTree<value_type, Node>	_tree;
	};
};

#endif