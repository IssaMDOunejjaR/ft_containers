/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issamdounejjar <issamdounejjar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:25:30 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/09 14:42:53 by issamdounej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {

		protected:
			Container	_cont;

		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			stack(container_type const & ctnr = container_type()): _cont(ctnr) {};

			stack(stack const & instance) {
				*this = instance;
			};

			~stack() {};

			stack&		operator=(stack const & instance) {
				this->_cont = instance._cont;
				return *this;
			};

			bool				empty(void) const {
				return this->_cont.empty();
			};

			size_type			size(void) const {
				return this->_cont.size();
			};

			value_type&			top(void) {
				return this->_cont.back();
			};

			const value_type&	top(void) const {
				return this->_cont.back();
			};

			void				push(value_type const & val) {
				this->_cont.push_back(val);
			};

			void				pop(void) {
				this->_cont.pop_back();
			};

			friend bool operator==(const stack & lhs, const stack & rhs) {
				return lhs._cont == rhs._cont;
			};

			friend bool operator!=(const stack & lhs, const stack & rhs) {
				return lhs._cont != rhs._cont;
			};

			friend bool operator<(const stack & lhs, const stack & rhs) {
				return lhs._cont < rhs._cont;
			};

			friend bool operator<=(const stack & lhs, const stack & rhs) {
				return lhs._cont <= rhs._cont;
			};

			friend bool operator>(const stack & lhs, const stack & rhs) {
				return lhs._cont > rhs._cont;
			};

			friend bool operator>=(const stack & lhs, const stack & rhs) {
				return lhs._cont >= rhs._cont;
			};
	};
};

#endif