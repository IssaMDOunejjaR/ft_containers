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
#include "red_black_tree.hpp"
#include "utility.hpp"

int		main(void) {
	ft::RedBlackTree<ft::pair<int, int>, std::less<int> >	root;

	root.insert(ft::pair<int, int>(0, 123));
	root.insert(ft::pair<int, int>(1, 123));
	root.insert(ft::pair<int, int>(2, 123));
	root.insert(ft::pair<int, int>(3, 123));
	root.insert(ft::pair<int, int>(4, 123));
	root.insert(ft::pair<int, int>(5, 123));
	root.insert(ft::pair<int, int>(6, 123));

	root.del(2);
	root.del(1);

	root.print();

	// std::cout << root.search(33) << std::endl;

	std::cout << "Length = " << root.size() << std::endl;

	return 0;
}