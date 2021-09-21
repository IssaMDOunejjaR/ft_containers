	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:34:23 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/19 17:13:02 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "red-black-tree.hpp"

int		main(void) {
	Tree<int, int>	root;

	root.insert(100, 431);
	root.insert(50, 89);
	root.insert(200, 456);
	root.insert(25, 456);
	root.insert(75, 456);
	root.insert(20, 456);
	root.insert(30, 456);

	// root.del(100);
	// root.del(200);
	// root.del(30);
	// root.del(20);
	// root.del(75);
	// root.del(50);
	// root.del(25);

	// root.print();

	// std::cout << root.search(33) << std::endl;

	// std::cout << "Length = " << root.size() << std::endl;

	std::map<int, int> m;

	m.insert(std::pair<int, int>(0, 500));
	m.insert(std::pair<int, int>(5, 100));
	m.insert(std::pair<int, int>(3, 6000));

	// // m.erase(500);

	// for(std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
	// 	std::cout << "key: " << it->first << std::endl;
	// 	std::cout << "value: " << it->second << std::endl;
	// 	std::cout << "==============" << std::endl;
	// }

	m[5] = 789;

	std::cout << m[5] << std::endl;

	return 0;
}