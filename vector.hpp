/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:57:46 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/13 17:25:02 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "iterators.hpp"

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
			typedef ft::MyIterator<T>							iterator;
			typedef const iterator								const_iterator;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			// Constructors and Destructors
			vector(void) {
				this->_list = this->_allocation.allocate(0);
				this->_capacity = 0;
				this->_size = 0;
			};

			vector(unsigned int const & size, T const & value = 0) {
				this->_list = this->_allocation.allocate(size);
				this->_capacity = size;
				this->_size = size;

				for (int i = 0; i < size; i++)
					this->_allocation.construct(this->_list + i, value);
			};

			template <class IteratorInput>
			vector<T>(IteratorInput first, IteratorInput last) {
				while (first != last) {
					this->push_back(*first);
					first++;
				}
			};
			vector<T>(vector<T> const & instance) {
				*this = instance;
			};

			~vector<T>(void) {
				for (int i = 0; i < this->_size; i++)
					this->_allocation.destroy(this->_list + i);
				this->_allocation.deallocate(this->_list, this->_capacity);
			};

			// // Operators Overloads
			vector<T>&	operator=(vector<T> const & instance) {
				clear();
				this->_list = instance._list;
				this->_capacity = instance._capacity;
				this->_size = instance._size;
				this->_allocation = instance._allocation;

				return *this;
			};

			T&	operator[](int index) {
				return this->_list[index];
			};

			// Iterators
			iterator	begin(void) {
				return iterator(this->_list);
			}

			const_iterator begin(void) const {
				return iterator(this->_list);
			}

			iterator	end(void) {
				return iterator(this->_list + this->_size);
			}

			const_iterator	end(void) const {
				return iterator(this->_list + this->_size);
			}

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}
			
			const_reverse_iterator rbegin() const {
				return reverse_iterator(end());
			}

			const_reverse_iterator rend() const {
				return reverse_iterator(begin());
			}
			
			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			

			// Capacity
			size_type	size(void) const {
				return this->_size;
			};

			size_type	max_size(void) const {
				return this->_allocation.max_size();
			};

			void		resize(size_type n, value_type value = 0) {
				pointer	newList = this->_allocation.allocate(n);
				int	i;

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
						newList[i] = value;
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
				return this->_size == 0 ? true : false;
			};

			void		reserve(size_type n) {
				if (n > this->_capacity) {
					// this->_list = this->_allocation.allocate(n);
					// this->_capacity = n;
					pointer	newList = this->_allocation.allocate(n);

					for (int i = 0; i < this->_size; i++) {
						this->_allocation.construct(newList + i, this->_list[i]);
						this->_allocation.destroy(this->_list + i);
					}
					this->_capacity = n;
					this->_allocation.deallocate(this->_list, this->_capacity);
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
				int i = 0;
				int len = 0;
				InputIterator it = first;

				for (int i = 0; i < this->_size; i++)
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

			void		assign(size_type n, value_type const & val) {
				if (n > this->_capacity)
					this->reserve(n);
				for (int i = 0; i < this->_size; i++)
					this->_allocation.destroy(this->_list + i);
				for (int i = 0; i < n; i++)
					this->_allocation.construct(this->_list + i, val);
				this->_size = n;
			};

			void		push_back(value_type const & val) {
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

			iterator	insert(iterator position, value_type const & val) {
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

			void	insert(iterator position, size_type n, value_type const & val) {
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
						for (int j = 0; j < n; j++) {
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
			void	insert(iterator position, InputIterator first, InputIterator last) {
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
				int i = 0;
				int len = this->_size;
				pointer	tmpList = this->_allocation.allocate(this->_size);

				for (iterator it = begin(); it != end(); it++) {
					this->_allocation.construct(tmpList + i, *it);
					i++;
				}
				clear();
				for (iterator it = x.begin(); it != x.end(); it++)
					push_back(*it);
				x.clear();
				for (int i = 0; i < len; i++) {
					x.push_back(tmpList[i]);
					this->_allocation.destroy(tmpList + i);
				}
				this->_allocation.deallocate(tmpList, len);
			};

			void		clear(void) {
				for (int i = 0; i < this->_size; i++)
					this->_allocation.destroy(this->_list + i);
				this->_size = 0;
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

		return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> & x, vector<T, Alloc> & y) {
		vector<T, Alloc> tmp;

		for (int i = 0; i < x.size(); i++)
			tmp.push_back(x[i]);
		x.clear();
		for (int i = 0; i < y.size(); i++)
			x.push_back(y[i]);
		y.clear();
		for (int i = 0; i < tmp.size(); i++)
			y.push_back(tmp[i]);
		tmp.clear();
	};
};

#endif