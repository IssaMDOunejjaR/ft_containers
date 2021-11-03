/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:03:47 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/03 11:07:02 by iounejja         ###   ########.fr       */
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
			typedef Compare														value_compare;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::bst_iterator<value_type, Compare>						iterator;
			typedef ft::bst_iterator<const value_type, Compare>					const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
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

			~map(void) {
				this->clear();
			};

			// Operators Overloads
			map&			operator=(const map & instance) {
				if (this != &instance) {
					this->_tree = instance._tree;
					this->_comp = instance._comp;
					this->_allocator = instance._allocator;
				}
				return *this;
			};

			mapped_type&	operator[](const key_type & k) {
				Node*	node = this->_tree.search(k);

				return node->data.second;
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
				return this->_tree.size();
			};

			size_type	max_size(void) const {
				return this->_allocator.max_size();
			};

			// Modifiers
			ft::pair<iterator, bool>	insert(value_type const & val) {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data.first == val.first)
						break ;
					if (val.first < node->data.first)
						node = node->left;
					else if (val.first > node->data.first)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL)
					return ft::pair<iterator, bool>(iterator(node, this->_tree.getRoot()), false);
				return ft::pair<iterator, bool>(iterator(this->_tree.insert(val), this->_tree.getRoot()), true);
			};

			// iterator	insert(iterator position, const value_type & val) {
				
			// };

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
				this->_tree.del(it->_first);
			};

			size_type	erase(const key_type & k) {
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
					this->_tree.del(first->first);
					first++;
				}
			};

			void	swap(map & x) {
				map tmp;

				tmp = *this;
				*this = x;
				x = tmp;
			};

			void	clear(void) {
				this->_tree.clear();
			};

			// Observers
			key_compare		key_comp(void) const {
				return key_compare();
			};

			value_compare	value_comp(void) const {
				return value_compare(key_compare());
			};	

			// Operations
			iterator	find(const key_type & k) {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data.first == k)
						break ;
					else if (k < node->data.first)
						node = node->left;
					else if (k > node->data.first)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL)
					return iterator(node, this->_tree.getRoot());
				return this->end();
			};
			
			const_iterator	find(const key_type & k) const {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data.first == k)
						break ;
					else if (k < node->data.first)
						node = node->left;
					else if (k > node->data.first)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL)
					return iterator(node, this->_tree.getRoot());
				return this->end();
			};

			size_type	count(key_type const & k) const {
				Node*	node = this->_tree.getRoot();

				while (node->left != NULL && node->right != NULL) {
					if (node->data.first == k)
						break ;
					else if (k < node->data.first)
						node = node->left;
					else if (k > node->data.first)
						node = node->right;
				}

				if (node->left != NULL && node->right != NULL)
					return 1;
				return 0;
			};

			iterator	lower_bound(const key_type & k) {
				Node*	root = this->_tree.getRoot();

				while (root != NULL) {
					if (!this->_comp(root->data.first, k))
						return iterator(root, this->_tree.getRoot());
					else
						root = root->right;
				}

				return this->end();
			};

			const_iterator	lower_bound(const key_type & k) const {
				Node*	root = this->_tree.getRoot();

				while (root != NULL) {
					if (!this->_comp(root->data.first, k))
						return const_iterator(root, this->_tree.getRoot());
					else
						root = root->right;
				}

				return this->end();
			};

			iterator	upper_bound(const key_type & k) {
				Node*	root = this->_tree.getRoot();

				while (root != NULL) {
					if (this->_comp(k, root->data.first)) {
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
			}

			const_iterator	upper_bound(const key_type & k) const {
				Node*	root = this->_tree.getRoot();

				while (root != NULL) {
					if (this->_comp(k, root->data.first)) {
						if (root->left->left == NULL && root->left->right == NULL)
							return const_iterator(root, this->_tree.getRoot());
						root = root->left;
					}
					else if (root->right->left == NULL && root->right->right == NULL)
						return const_iterator(root->parent, this->_tree.getRoot());
					else
						root = root->right;
				}

				return this->end();
			}

			ft::pair<iterator, iterator>	equal_range(const key_type & k) {
				return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			};
			
			// Allocator
			allocator_type	get_allocator(void) const {
				return this->_allocator;
			};

		private:
			Alloc							_allocator;
			Compare							_comp;
			ft::RedBlackTree<value_type>	_tree;
	};
};

#endif