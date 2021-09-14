/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:16:11 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/13 18:05:58 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include "vector.hpp"
#include "stack.hpp"

int		main(void) {
	// try {
	// 	std::vector<int> lst;

	// 	lst.push_back(5);
	// 	lst.push_back(6);
	// 	lst.push_back(7);
	// 	lst.push_back(8);
	// 	lst.push_back(9);

	// 	std::vector<int> test;

	// 	test.push_back(15);
	// 	test.push_back(16);
	// 	test.push_back(17);
	// 	test.push_back(18);
	// 	test.push_back(19);
	// 	test.push_back(20);

	// 	// lst.push_back(11);
	// 	// lst.push_back(12);
	// 	// lst.push_back(13);
	// 	// lst.push_back(14);

	// 	// lst.resize(5, 1);
	// 	// lst.reserve(10);
	// 	// lst.pop_back();
	// 	// lst.push_back(8);
	// 	// lst.push_back(9);
	// 	// lst.push_back(10);

	// 	// lst.clear();
	// 	// lst.assign(test.begin(), test.end());
	// 	// lst.swap(test);
	// 	// std::cout << *(lst.erase(lst.begin() + 1, lst.begin() + 3)) << std::endl;
	// 	// std::cout << *(lst.insert(lst.begin() + 2, 4, 5000)) << std::endl;
	// 	// lst.insert(lst.begin() + 2, test.begin(), test.begin() + 4);
	// 	std::swap(lst, test);

	// 	std::cout << "size\t\t: " << lst.size() << std::endl;
	// 	std::cout << "max_size\t: " << lst.max_size() << std::endl;
	// 	std::cout << "capacity\t: " << lst.capacity() << std::endl;
	// 	std::cout << "empty\t\t: " << (lst.empty() ? "true" : "false") << std::endl;
	// 	std::cout << "equal\t\t: " << (lst >= test ? "true" : "false") << std::endl;
	// 	// std::cout << "at\t\t: " << lst.at(1) << std::endl;
	// 	// std::cout << "front\t\t: " << lst.front() << std::endl;
	// 	// std::cout << "back\t\t: " << lst.back() << std::endl;
	// 	for (std::vector<int>::iterator i = lst.begin(); i != lst.end(); i++)
	// 		std::cout << *i << std::endl;
	// 	// for (std::vector<int>::iterator i = test.begin(); i != test.end(); i++)
	// 	// 	std::cout << *i << std::endl;

	// 	// std::vector<int>::const_reverse_iterator it = lst.rbegin();
	// 	// it--;
	// 	// for (std::vector<int>::const_reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
	// 	// 	std::cout << *it << std::endl;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::cout << "#######################" << std::endl;

	// try {
	// 	ft::vector<int> myList;

	// 	myList.push_back(5);
	// 	myList.push_back(6);
	// 	myList.push_back(7);
	// 	myList.push_back(8);
	// 	myList.push_back(9);

	// 	ft::vector<int> test;

	// 	test.push_back(15);
	// 	test.push_back(16);
	// 	test.push_back(17);
	// 	test.push_back(18);
	// 	test.push_back(19);
	// 	test.push_back(20);

	// 	// myList.resize(5, 1);
	// 	// myList.reserve(10);
	// 	// myList.pop_back();
	// 	// myList.push_back(8);
	// 	// myList.push_back(9);
	// 	// myList.push_back(10);

	// 	// myList.clear();
	// 	// myList.assign(test.begin(), test.end());
	// 	// std::cout << *(myList.erase(myList.begin() + 1, myList.begin() + 3)) << std::endl;
	// 	// std::cout << *(myList.insert(myList.begin() + 2, 4, 5000)) << std::endl;
	// 	// myList.insert(myList.begin() + 2, test.begin(), test.begin() + 4);
	// 	// myList.swap(test);
	// 	ft::swap(myList, test);

	// 	std::cout << "size\t\t: " << myList.size() << std::endl;
	// 	std::cout << "max_size\t: " << myList.max_size() << std::endl;
	// 	std::cout << "capacity\t: " << myList.capacity() << std::endl;
	// 	std::cout << "empty\t\t: " << (myList.empty() ? "true" : "false") << std::endl;
	// 	std::cout << "equal\t\t: " << (myList >= test ? "true" : "false") << std::endl;
	// 	// std::cout << "at\t\t: " << myList.at(1) << std::endl;
	// 	// std::cout << "front\t\t: " << myList.front() << std::endl;
	// 	// std::cout << "back\t\t: " << myList.back() << std::endl;
	// 	// for (int i = 0; i < 3; i++)
	// 	// 	std::cout << myList[i] << std::endl;
	// 	// ft::vector<int>::const_reverse_iterator it = myList.rbegin();
	// 	// it++;

	// 	// for (ft::vector<int>::const_reverse_iterator it = myList.rbegin(); it != myList.rend(); it++)
	// 	// 	std::cout << *it << std::endl;
	// 	for (ft::vector<int>::iterator it = myList.begin(); it != myList.end(); it++)
	// 		std::cout << *it << std::endl;
	// 	// for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
	// 	// 	std::cout << *it << std::endl;
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

	try {
		std::stack<int>	s;
		std::stack<int>	t;

		s.push(10);
		s.push(11);
		s.push(12);

		t.push(100);
		t.push(101);
		t.push(102);

		std::cout << "empty\t\t: " << s.empty() << std::endl;
		std::cout << "size\t\t: " << s.size() << std::endl;
		std::cout << "top\t\t: " << s.top() << std::endl;
		std::cout << "equal\t\t: " << (s == t ? "true" : "false") << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "###########################" << std::endl;
	try {
		ft::stack<int>	s;
		ft::stack<int>	t;

		s.push(10);
		s.push(11);
		s.push(12);

		t.push(100);
		t.push(101);
		t.push(102);

		std::cout << "empty\t\t: " << s.empty() << std::endl;
		std::cout << "size\t\t: " << s.size() << std::endl;
		std::cout << "top\t\t: " << s.top() << std::endl;
		std::cout << "equal\t\t: " << (s == t ? "true" : "false") << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}


	return (0);
}