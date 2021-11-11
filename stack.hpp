/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:25:30 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/11 11:34:18 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {

		protected:
			Container	c;

		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			stack(container_type const & ctnr = container_type()): c(ctnr) {};

			stack(stack const & instance) {
				*this = instance;
			};

			~stack() {};

			stack&		operator=(stack const & instance) {
				this->c = instance.c;
				return *this;
			};

			bool				empty(void) const {
				return this->c.empty();
			};

			size_type			size(void) const {
				return this->c.size();
			};

			value_type&			top(void) {
				return this->c.back();
			};

			const value_type&	top(void) const {
				return this->c.back();
			};

			void				push(value_type const & val) {
				this->c.push_back(val);
			};

			void				pop(void) {
				this->c.pop_back();
			};

			friend bool operator==(const stack & lhs, const stack & rhs) {
				return lhs.c == rhs.c;
			};

			friend bool operator!=(const stack & lhs, const stack & rhs) {
				return lhs.c != rhs.c;
			};

			friend bool operator<(const stack & lhs, const stack & rhs) {
				return lhs.c < rhs.c;
			};

			friend bool operator<=(const stack & lhs, const stack & rhs) {
				return lhs.c <= rhs.c;
			};

			friend bool operator>(const stack & lhs, const stack & rhs) {
				return lhs.c > rhs.c;
			};

			friend bool operator>=(const stack & lhs, const stack & rhs) {
				return lhs.c >= rhs.c;
			};
	};
};

#endif