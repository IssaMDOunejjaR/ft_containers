/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:16:11 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/22 18:04:04 by iounejja         ###   ########.fr       */
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

int		main(void) {
	// try {
	// 	std::vector<std::string> lst;

	// 	lst.push_back("hello");
	// 	lst.push_back("test");
	// 	lst.push_back("issam");
	// 	lst.push_back("ounejjar");
	// 	lst.push_back("aaaaaaa");
	// 	lst.push_back("bbbbbbb");

	// 	std::cout << "at\t\t: " << lst.back() << std::endl;

	// 	std::cout << "size\t\t: " << lst.size() << std::endl;
	// 	std::cout << "max_size\t: " << lst.max_size() << std::endl;
	// 	std::cout << "capacity\t: " << lst.capacity() << std::endl;
	// 	std::cout << "empty\t\t: " << (lst.empty() ? "true" : "false") << std::endl << std::endl;

	// 	for (std::vector<std::string>::iterator it = lst.begin(); it != lst.end(); it++)
	// 		std::cout << *it << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::cout << "\n#######################\n" << std::endl;

	// try {
	// 	ft::vector<std::string> lst;

	// 	lst.push_back("hello");
	// 	lst.push_back("test");
	// 	lst.push_back("issam");
	// 	lst.push_back("ounejjar");
	// 	lst.push_back("aaaaaaa");
	// 	lst.push_back("bbbbbbb");

	// 	std::cout << "at\t\t: " << lst.back() << std::endl;

	// 	std::cout << "size\t\t: " << lst.size() << std::endl;
	// 	std::cout << "max_size\t: " << lst.max_size() << std::endl;
	// 	std::cout << "capacity\t: " << lst.capacity() << std::endl;
	// 	std::cout << "empty\t\t: " << (lst.empty() ? "true" : "false") << std::endl << std::endl;

	// 	for (ft::vector<std::string>::iterator it = lst.begin(); it != lst.end(); it++)
	// 		std::cout << *it << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::pair<std::string, std::string> t("hello", "world");
	// ft::pair<std::string, std::string>	p("hello", "world");
	// // std::string test;

	// std::cout << t.first << std::endl;
	// std::cout << t.second << std::endl;
	// std::cout << p.first << std::endl;
	// std::cout << p.second << std::endl;
	// std::cout << test << std::endl;

	// ft::pair<int, std::string> pr(41, "hello");
	// ft::pair<int, std::string> pr = ft::make_pair(41, "5");

	// std::cout << pr.first << std::endl;
	// std::cout << pr.second << std::endl;

	// try {
	// 	std::stack<int>	s;
	// 	std::stack<int>	t;

	// 	s.push(10);
	// 	s.push(11);
	// 	s.push(12);

	// 	t.push(100);
	// 	t.push(101);
	// 	t.push(102);

	// 	std::cout << "empty\t\t: " << s.empty() << std::endl;
	// 	std::cout << "size\t\t: " << s.size() << std::endl;
	// 	std::cout << "top\t\t: " << s.top() << std::endl;
	// 	std::cout << "equal\t\t: " << (s == t ? "true" : "false") << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << "###########################" << std::endl;
	// try {
	// 	ft::stack<int>	s;
	// 	ft::stack<int>	t;

	// 	s.push(10);
	// 	s.push(11);
	// 	s.push(12);

	// 	t.push(100);
	// 	t.push(101);
	// 	t.push(102);

	// 	std::cout << "empty\t\t: " << s.empty() << std::endl;
	// 	std::cout << "size\t\t: " << s.size() << std::endl;
	// 	std::cout << "top\t\t: " << s.top() << std::endl;
	// 	std::cout << "equal\t\t: " << (s == t ? "true" : "false") << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }


	try {
		std::map<int, int> m;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "####################################" << std::endl;
	try {
		ft::map<int, int>	m;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}