/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issamdounejjar <issamdounejjar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:16:11 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/06 18:21:11 by issamdounej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <iterator>
#include <type_traits>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "utility.hpp"

int		main(void) {
	// try {
	// 	std::vector<int>	v1;
	// 	std::vector<int>	v2;
	// 	std::vector<int>	v3;

	// 	v1.push_back(10);
	// 	v1.push_back(11);
	// 	v1.push_back(12);

	// 	v2.push_back(0);
	// 	v2.push_back(1);
	// 	v2.push_back(2);

	// 	// ft::swap(v1, v2);
	// 	v1.swap(v2);

	// 	v3 = v1;

	// 	std::vector<int>::iterator it = v1.begin();
	// 	std::vector<int>::iterator it2 = v2.begin();

	// 	std::cout << "size = " << v1.size() << std::endl;
	// 	std::cout << "capacity = " << v1.capacity() << std::endl;

	// 	std::cout << "size = " << v2.size() << std::endl;
	// 	std::cout << "capacity = " << v2.capacity() << std::endl;

	// 	std::cout << "size = " << v3.size() << std::endl;
	// 	std::cout << "capacity = " << v3.capacity() << std::endl;

	// 	for (; it != v1.end(); it++)
	// 		std::cout << *it << std::endl;

	// 	std::cout << std::endl;

	// 	for (; it2 != v2.end(); it2++)
	// 		std::cout << *it2 << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::cout << "\n#######################\n" << std::endl;

	// try {
	// 	ft::vector<int>	v1;
	// 	ft::vector<int>	v2;
	// 	ft::vector<int>	v3;

	// 	v1.push_back(10);
	// 	v1.push_back(11);
	// 	v1.push_back(12);

	// 	v2.push_back(0);
	// 	v2.push_back(1);
	// 	v2.push_back(2);

	// 	// ft::swap(v1, v2);
	// 	v1.swap(v2);

	// 	v3 = v1;

	// 	ft::vector<int>::iterator it = v1.begin();
	// 	ft::vector<int>::iterator it2 = v2.begin();

	// 	std::cout << "size = " << v1.size() << std::endl;
	// 	std::cout << "capacity = " << v1.capacity() << std::endl;

	// 	std::cout << "size = " << v2.size() << std::endl;
	// 	std::cout << "capacity = " << v2.capacity() << std::endl;

	// 	std::cout << "size = " << v3.size() << std::endl;
	// 	std::cout << "capacity = " << v3.capacity() << std::endl;

	// 	for (; it != v1.end(); it++)
	// 		std::cout << *it << std::endl;

	// 	std::cout << std::endl;

	// 	for (; it2 != v2.end(); it2++)
	// 		std::cout << *it2 << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	try {
		std::map<int, int> m;
		std::map<int, int> test;

		std::pair<std::map<int, int>::iterator, bool>	check;

		check = m.insert(std::pair<int, int>(10, 1));
		check = m.insert(std::pair<int, int>(11, 2));
		check = m.insert(std::pair<int, int>(12, 3));
		check = m.insert(std::pair<int, int>(13, 4));
		check = m.insert(std::pair<int, int>(14, 5));
		check = m.insert(std::pair<int, int>(15, 6));
		check = m.insert(std::pair<int, int>(16, 7));

		test.insert(std::pair<int, int>(20, 46556415));
		test.insert(std::pair<int, int>(21, 46556415));
		test.insert(std::pair<int, int>(22, 46556415));

		// m.erase(m.begin(), m.end()--);

		std::cout << "size\t\t: " << m.size() << std::endl;
		std::cout << "max_size\t: " << m.max_size() << std::endl;
		std::cout << "empty\t\t: " << (m.empty() ? "true" : "false") << std::endl << std::endl;
		std::cout << "find: " << (m.find(19) != m.end() ? m.find(19)->second : 0) << std::endl;

		std::cout << (m == m) << std::endl;

		std::map<int, int>::const_iterator it;

		// it->first = 100;

		// for (it = m.begin(); it != m.end(); ++it) {
		// 	std::cout << it->first << "\t===>\t" << it->second << std::endl;
		// }
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "####################################" << std::endl;

	try {
		ft::map<int, int>	m1;
		// ft::map<int, int>	m2(m1);

		ft::pair<ft::map<int, int>::iterator, bool>	check;

		check = m1.insert(ft::pair<int, int>(10, 1));
		check = m1.insert(ft::pair<int, int>(11, 2));
		check = m1.insert(ft::pair<int, int>(12, 3));
		check = m1.insert(ft::pair<int, int>(13, 3));
		check = m1.insert(ft::pair<int, int>(14, 3));
		check = m1.insert(ft::pair<int, int>(15, 3));
		check = m1.insert(ft::pair<int, int>(16, 1415465));

		// m2.insert(ft::pair<int, int>(20, 1415));
		// m2.insert(ft::pair<int, int>(21, 1415));
		// m2.insert(ft::pair<int, int>(22, 1415));

		// m.erase(m.begin(), m.end()--);

		std::cout << "size\t\t: " << m1.size() << std::endl;
		std::cout << "max_size\t: " << m1.max_size() << std::endl;
		std::cout << "empty\t\t: " << (m1.empty() ? "true" : "false") << std::endl;
		std::cout << "find: " << (m1.find(19) != m1.end() ? m1.find(19)->second : 0) << std::endl << std::endl;

		// std::cout << (m1 == m1) << std::endl;

		// for (ft::map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) {
		// 	std::cout << it->first << std::endl;
		// }

		// std::cout << std::endl;

		// for (ft::map<int, int>::iterator it = m2.begin(); it != m2.end(); it++) {
		// 	std::cout << it->first << std::endl;
		// }

		ft::map<int, int>::const_iterator it = m1.cbegin();

		// it->first = 100;

		// std::cout << it->first << std::endl;

		for (it = m1.cbegin(); it != m1.cend(); it++) {
			std::cout << it->first << std::endl;
		}

		// --it;
		// --it;
		// std::cout << (*it++).first << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}