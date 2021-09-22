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

int		main(void) {
	ft::RedBlackTree<int>	root;

	root.insert(100);
	root.insert(50);
	root.insert(200);
	root.insert(25);
	root.insert(75);
	root.insert(20);
	root.insert(30);

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

	return 0;
}