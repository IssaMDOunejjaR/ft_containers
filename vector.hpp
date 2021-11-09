/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issamdounejjar <issamdounejjar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:57:46 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/09 14:39:01 by issamdounej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "iterators.hpp"
# include "utility.hpp"

namespace ft {
	template <typename T, typename Allocator = std::allocator<T> >
	class	vector
	{
		T*				_list;
		unsigned int	_capacity;
		unsigned int	_size;
		Allocator		_allocation;

		public:

			typedef	T											value_type;
			typedef Allocator 									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef ft::Iterator<value_type>					iterator;
			typedef ft::Iterator<const value_type>				const_iterator;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			// Constructors and Destructor
			explicit vector(const allocator_type & alloc = allocator_type())
			: _allocation(alloc) {
				this->_list = NULL;
				this->_capacity = 0;
				this->_size = 0;
			};

			explicit vector(size_type size, const value_type & val = value_type(), const allocator_type & alloc = allocator_type())
			: _allocation(alloc) {
				this->_list = this->_allocation.allocate(size);
				this->_capacity = size;
				this->_size = size;

				for (unsigned int i = 0; i < size; i++)
					this->_allocation.construct(this->_list + i, val);
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type a = InputIterator())
			: _allocation(alloc) {
				(void)a;
				while (first != last) {
					this->push_back(*first);
					first++;
				}
			};

			vector(const vector & instance) {
				*this = instance;
			};

			~vector(void) {
				this->clear();
			};

			// Operators Overloads
			vector&		operator=(const vector & instance) {
				if (this != &instance) {
					this->clear();

					this->_allocation = instance._allocation;

					for (unsigned int i = 0; i < instance._size; i++)
						this->push_back(instance._list[i]);

					this->_capacity = this->_size;
				}
				return *this;
			};

			reference	operator[](size_type n) {
				return this->_list[n];
			};

			const_reference	operator[](size_type n) const {
				return this->_list[n];
			};

			// Iterators
			iterator	begin(void) {
				return iterator(this->_list);
			}

			const_iterator	begin(void) const {
				return const_iterator(this->_list);
			}

			iterator	end(void) {
				return iterator(this->_list + this->_size);
			}

			const_iterator	end(void) const {
				return const_iterator(this->_list + this->_size);
			}

			reverse_iterator	rbegin() {
				return reverse_iterator(end());
			}
			
			const_reverse_iterator 	rbegin() const {
				return const_reverse_iterator(end());
			}
			
			reverse_iterator	rend() {
				return reverse_iterator(begin());
			}
			
			const_reverse_iterator	rend() const {
				return const_reverse_iterator(begin());
			}

			// Capacity
			size_type	size(void) const {
				return this->_size;
			};

			size_type	max_size(void) const {
				return this->_allocation.max_size();
			};

			void		resize(size_type n, value_type val = value_type()) {
				if (n > this->max_size())
					throw std::out_of_range("vector");
				pointer	newList = this->_allocation.allocate(n);
				size_type	i;

				if (n < this->_size) {
					for (i = 0; i < n; i++) {
						this->_allocation.construct(newList + i, this->_list[i]);
						this->_allocation.destroy(this->_list + i);
					}
				}
				else if (n > this->_size) {
					if (n > this->_capacity)
						this->reserve(this->_capacity * 2);
					for (i = 0; i < this->_size; i++) {
						this->_allocation.construct(newList + i, this->_list[i]);
						this->_allocation.destroy(this->_list + i);
					}
					while (i < n) {
						newList[i] = val;
						i++;
					}
				}
				this->_allocation.deallocate(this->_list, this->_capacity);
				this->_size = n;
				this->_list = newList;
			};

			size_type	capacity(void) const {
				return this->_capacity;
			};

			bool		empty(void) const {
				return this->_size == 0;
			};

			void		reserve(size_type n) {
				if (n > this->_capacity) {
					pointer	newList = this->_allocation.allocate(n);

					if (this->_capacity > 0) {
						for (unsigned int i = 0; i < this->_size; i++) {
							this->_allocation.construct(newList + i, this->_list[i]);
							this->_allocation.destroy(this->_list + i);
						}
						this->_allocation.deallocate(this->_list, this->_capacity);
					}
					this->_capacity = n;
					this->_list = newList;
				}
			};

			// Element access
			reference		at(size_type n) {
				if (n >= this->_size || n < 0)
					throw std::out_of_range("vector");
				return this->_list[n];
			};

			const_reference	at(size_type n) const {
				if (n >= this->_size || n < 0)
					throw std::out_of_range("vector");
				return this->_list[n];
			};

			reference		front(void) {
				return *(this->_list);
			};

			const_reference	front(void) const {
				return *(this->_list);
			};

			reference		back(void) {
				return *(this->_list + (this->_size - 1));
			};

			const_reference	back(void) const {
				return *(this->_list + (this->_size - 1));
			};

			// Modifiers
			template<class InputIterator>
			void		assign(InputIterator first, InputIterator last) {
				unsigned int i = 0;
				unsigned int len = 0;
				InputIterator it = first;

				for (unsigned int i = 0; i < this->_size; i++)
					this->_allocation.destroy(this->_list + i);
				for (; it != last; it++)
					len++;
				if (len > this->_capacity)
					this->reserve(len);
				this->_size = 0;
				while (first != last) {
					this->_allocation.construct(this->_list + i, *first);
					i++;
					first++;
					this->_size++;
				}
			};

			void		assign(size_type n, const value_type & val) {
				if (n > this->_capacity)
					this->reserve(n);
				for (unsigned int i = 0; i < this->_size; i++)
					this->_allocation.destroy(this->_list + i);
				for (unsigned int i = 0; i < n; i++)
					this->_allocation.construct(this->_list + i, val);
				this->_size = n;
			};

			void		push_back(const value_type & val) {
				if (this->_size == this->_capacity) {
					if (this->_capacity == 0)
						this->reserve(1);
					else
						this->reserve(this->_capacity * 2);
				}
				this->_allocation.construct(this->_list + this->_size, val);
				this->_size++;
			};

			void		pop_back(void) {
				this->_allocation.destroy(this->_list + (this->_size - 1));
				this->_size--;
			};

			iterator	insert(iterator position, const value_type & val) {
				int i = 0;
				pointer	newList = this->_allocation.allocate(this->_capacity);

				for (iterator it = this->begin(); it != this->end(); it++) {
					if (it == position) {
						this->_allocation.construct(newList + i, val);
						i++;
						this->_allocation.construct(newList + i, *it);
					}
					else {
						this->_allocation.construct(newList + i, *it);
					}
					this->_allocation.destroy(this->_list + i);
					i++;
				}
				this->_allocation.deallocate(this->_list, this->_capacity);
				this->_list = newList;
				this->_size++;
				return position;
			};

			void	insert(iterator position, size_type n, const value_type & val) {
				int i = 0;
				pointer	newList;

				if (n + this->_size > this->_capacity) {
					newList = this->_allocation.allocate(this->_capacity * 2);
					this->_capacity *= 2;
				}
				else
					newList = this->_allocation.allocate(this->_capacity);


				for (iterator it = this->begin(); it != this->end(); it++) {
					if (it == position) {
						for (unsigned int j = 0; j < n; j++) {
							this->_allocation.construct(newList + i, val);
							i++;
						}
						this->_allocation.construct(newList + i, *it);
					}
					else
						this->_allocation.construct(newList + i, *it);
					this->_allocation.destroy(this->_list + i);
					i++;
				}
				this->_allocation.deallocate(this->_list, this->_capacity);
				this->_list = newList;
				this->_size = i;
			};

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type a = InputIterator()) {

				(void)a;

				int i = 0;
				pointer newList;

				for (InputIterator it = first; it != last; it++)
					i++;
				
				if (i + this->_size > this->_capacity) {
					newList = this->_allocation.allocate(this->_capacity * 2);
					this->_capacity *= 2;
				}
				else
					newList = this->_allocation.allocate(this->_capacity);

				i = 0;
				for (iterator it = this->begin(); it != this->end(); it++) {
					if (it == position) {
						for (; first != last; first++) {
							this->_allocation.construct(newList + i, *first);
							i++;
						}
						this->_allocation.construct(newList + i, *it);
					}
					else
						this->_allocation.construct(newList + i, *it);
					i++;
					this->_allocation.destroy(this->_list + i);
				}
				this->_allocation.deallocate(this->_list, this->_capacity);
				this->_list = newList;
				this->_size = i;
			};
			
			iterator	erase(iterator position) {
				int		i = 0;
				pointer	newList = this->_allocation.allocate(this->_capacity);

				for (iterator it = this->begin(); it != this->end(); it++) {
					if (it != position) {
						this->_allocation.construct(newList + i, *it);
						i++;
					}
					this->_allocation.destroy(this->_list + i);
				}
				this->_allocation.deallocate(this->_list, this->_capacity);
				this->_list = newList;
				this->_size--;
				return ++position;
			};

			iterator	erase(iterator first, iterator last) {
				int i = 0;
				pointer newList = this->_allocation.allocate(this->_capacity);

				for (iterator it = this->begin(); it != this->end(); it++) {
					if (it == first && first != last)
						first++;
					else {
						this->_allocation.construct(newList + i, *it);
						i++;
					}
					this->_allocation.destroy(this->_list + i);
				}
				this->_allocation.deallocate(this->_list, this->_capacity);
				this->_list = newList;
				this->_size = i;
				return last;
			};

			void		swap(vector & x) {
				vector tmp;

				tmp = *this;
				*this = x;
				x = tmp;
			};

			void		clear(void) {
				if (this->_capacity > 0) {
					for (unsigned int i = 0; i < this->_size; i++)
						this->_allocation.destroy(this->_list + i);
					this->_allocation.deallocate(this->_list, this->_capacity);
					this->_size = 0;
					this->_capacity = 0;
				}
			};

			// Allocator
			allocator_type	get_allocator(void) const {
				return this->_allocation;
			}
	};

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs) {
		if (lhs.size() != rhs.size())
			return false;

		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs) {
		return !(lhs == rhs);
	};

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs) {
		return !(rhs < lhs);
	};

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs) {
		return rhs < lhs;
	};

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs) {
		return !(lhs < rhs);
	};
};

#endif