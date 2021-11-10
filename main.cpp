/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:16:11 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/10 10:54:43 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <type_traits>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
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

	// try {
	// 	std::map<int, int> m1;
	// 	std::map<int, int> m2;

	// 	std::pair<std::map<int, int>::iterator, bool>	check;

	// 	check = m1.insert(std::pair<int, int>(10, 1));
	// 	check = m1.insert(std::pair<int, int>(11, 2));
	// 	check = m1.insert(std::pair<int, int>(12, 3));
	// 	check = m1.insert(std::pair<int, int>(13, 4));
	// 	check = m1.insert(std::pair<int, int>(14, 5));
	// 	check = m1.insert(std::pair<int, int>(15, 6));
	// 	check = m1.insert(std::pair<int, int>(16, 7));

	// 	m2.insert(std::pair<int, int>(20, 46556415));
	// 	m2.insert(std::pair<int, int>(21, 46556415));
	// 	m2.insert(std::pair<int, int>(22, 46556415));

	// 	std::cout << (m1 <= m2) << std::endl;

	// 	// m.erase(m.begin(), m.end()--);

	// 	std::cout << "size\t\t: " << m1.size() << std::endl;
	// 	std::cout << "max_size\t: " << m1.max_size() << std::endl;
	// 	std::cout << "empty\t\t: " << (m1.empty() ? "true" : "false") << std::endl;
	// 	std::cout << "find: " << (m1.find(19) != m1.end() ? m1.find(19)->second : 0) << std::endl << std::endl;

	// 	// std::cout << m1[102] << std::endl;
	// 	// std::cout << m1[502] << std::endl;

	// 	// m1[98] = 1000;

	// 	std::map<int, int>::const_iterator it;

	// 	for (it = m1.begin(); it != m1.end(); ++it) {
	// 		std::cout << it->first << "\t===>\t" << it->second << std::endl;
	// 	}

	// 	std::cout << std::endl;

	// 	for (std::map<int, int>::iterator it = m2.begin(); it != m2.end(); it++) {
	// 		std::cout << it->first << "\t===>\t" << it->second << std::endl;
	// 	}
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::cout << "\n####################################\n" << std::endl;

	// try {
	// 	ft::map<int, int>	m1;
	// 	ft::map<int, int>	m2(m1);

	// 	ft::pair<ft::map<int, int>::iterator, bool>	check;

	// 	check = m1.insert(ft::pair<int, int>(10, 1));
	// 	check = m1.insert(ft::pair<int, int>(11, 2));
	// 	check = m1.insert(ft::pair<int, int>(12, 3));
	// 	check = m1.insert(ft::pair<int, int>(13, 4));
	// 	check = m1.insert(ft::pair<int, int>(14, 5));
	// 	check = m1.insert(ft::pair<int, int>(15, 6));
	// 	check = m1.insert(ft::pair<int, int>(16, 7));

	// 	m2.insert(ft::pair<int, int>(20, 46556415));
	// 	m2.insert(ft::pair<int, int>(21, 46556415));
	// 	m2.insert(ft::pair<int, int>(22, 46556415));

	// 	std::cout << (m1 <= m2) << std::endl;

	// 	// m1.erase(13);

	// 	std::cout << "size\t\t: " << m1.size() << std::endl;
	// 	std::cout << "max_size\t: " << m1.max_size() << std::endl;
	// 	std::cout << "empty\t\t: " << (m1.empty() ? "true" : "false") << std::endl;
	// 	std::cout << "find: " << (m1.find(19) != m1.end() ? m1.find(19)->second : 0) << std::endl << std::endl;

	// 	// std::cout << m1[102] << std::endl;
	// 	// std::cout << m1[502] << std::endl;

	// 	// m1[98] = 1000;

	// 	// ft::map<int, int>::reverse_iterator it = m1.rbegin();

	// 	// std::cout << it->first << "\t===>\t" << it->second << std::endl;
		
	// 	// it->first = 122222;	

	// 	for (ft::map<int, int>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++) {
	// 		std::cout << it->first << "\t===>\t" << it->second << std::endl;
	// 	}

	// 	std::cout << std::endl;

	// 	for (ft::map<int, int>::reverse_iterator it = m2.rbegin(); it != m2.rend(); it++) {
	// 		std::cout << it->first << "\t===>\t" << it->second << std::endl;
	// 	}
	// } catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// try {
	// 	std::set<int>	s1;
	// 	std::set<int>	s2;

	// 	s1.insert(10);
	// 	s1.insert(11);
	// 	s1.insert(12);
	// 	s1.insert(13);
	// 	s1.insert(14);
	// 	s1.insert(12);

	// 	s2.insert(1);
	// 	s2.insert(2);
	// 	s2.insert(3);

	// 	// std::set<int>::const_reverse_iterator it = s1.rbegin();

	// 	for (std::set<int>::const_reverse_iterator it = s1.rbegin(); it != s1.rend(); it++)
	// 		std::cout << *it << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::cout << "\n######################################\n" << std::endl;

	// try {
	// 	ft::set<int>	s1;

	// 	s1.insert(10);
	// 	s1.insert(11);
	// 	s1.insert(12);
	// 	s1.insert(13);
	// 	s1.insert(14);
	// 	s1.insert(12);

	// 	ft::set<int>::const_reverse_iterator itb = s1.rbegin();
	// 	ft::set<int>::const_reverse_iterator ite = s1.rend();

	// 	// std::cout << (itb != ite) << std::endl;

	// 	// while (itb != ite) {
	// 	// 	std::cout << *itb << std::endl;
	// 	// 	itb++;
	// 	// }

	// 	for (ft::set<int>::const_reverse_iterator it = s1.rbegin(); it != s1.rend(); it++)
	// 		std::cout << *it << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	std::vector<int>	v1;
	ft::vector<int>		v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	v1.resize(7);
	v2.resize(7);

	std::cout << "size: " << v1.size() << std::endl;
	std::cout << "capacity: " << v1.capacity() << std::endl;

	std::cout << "=================" << std::endl;

	std::cout << "size: " << v2.size() << std::endl;
	std::cout << "capacity: " << v2.capacity() << std::endl;

	return (0);
}