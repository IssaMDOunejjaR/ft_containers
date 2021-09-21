/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:25:30 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/14 10:02:49 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {

		Container	cont;

		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			stack(container_type const & ctnr = container_type()) {};
			stack(stack const & instance) {
				*this = instance;
			};
			~stack() {};

			stack&		operator=(stack const & instance) {
				this->cont = instance.cont;
				return *this;
			};

			bool				empty(void) const {
				return cont.empty();
			};

			size_type			size(void) const {
				return cont.size();
			};

			value_type&			top(void) {
				return cont.back();
			};

			const value_type&	top(void) const {
				return cont.back();
			};

			void				push(value_type const & val) {
				cont.push_back(val);
			};

			void				pop(void) {
				cont.pop_back();
			};

			template <class T1, class Container1>
			friend bool operator==(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);

			template <class T1, class Container1>
			friend bool operator!=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);

			template <class T1, class Container1>
			friend bool operator<(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);

			template <class T1, class Container1>
			friend bool operator<=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);

			template <class T1, class Container1>
			friend bool operator>(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);

			template <class T1, class Container1>
			friend bool operator>=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container> & lhs, const stack<T,Container> & rhs) {
		return lhs.cont == rhs.cont;
	};

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs == rhs);
	};

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.cont < rhs.cont;
	};

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.cont <= rhs.cont;
	};

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.cont > rhs.cont;
	};

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.cont >= rhs.cont;
	};
};

#endif