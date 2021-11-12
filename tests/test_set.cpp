/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:42:24 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/12 13:23:21 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "../set.hpp"

int		main(void) {
	{
		std::cout << "#====================================== set ======================================#" << std::endl;

		NAME_SPACE::set<int>	m1;
		NAME_SPACE::set<int>	m2(m1);
		NAME_SPACE::set<int>	m4;

		m1.insert(10);
		m1.insert(11);
		m1.insert(12);
		m1.insert(13);
		m1.insert(14);
		m1.insert(15);
		m1.insert(16);
		m1.insert(17);
		m1.insert(18);
		m1.insert(19);
		m1.insert(20);
		m1.insert(21);
		m1.insert(22);
		m1.insert(23);
		m1.insert(24);
		m1.insert(25);
		m1.insert(26);
		m1.insert(27);
		m1.insert(28);
		m1.insert(29);
		m1.insert(30);
		m1.insert(31);
		m1.insert(32);
		m1.insert(33);
		m1.insert(34);

		NAME_SPACE::set<int>	m3(m1.begin(), m1.end());

		m4 = m3;

		std::cout << "size\t\t\t: " << m4.size() << std::endl;
		std::cout << "empty\t\t\t: " << (m4.empty() ? "true" : "false") << std::endl;
		std::cout << "find\t\t\t: " << (m4.find(22) != m4.end() ? *(m4.find(22)) : 0) << std::endl;
		std::cout << "count\t\t\t: " << (m4.count(22) ? "true" : "false") << std::endl;
		std::cout << "lower_bound\t\t: " << (m4.lower_bound(22) != m4.end() ? *(m4.lower_bound(22)) : 0) << std::endl;
		std::cout << "upper_bound\t\t: " << (m4.upper_bound(22) != m4.end() ? *(m4.upper_bound(22)) : 0) << std::endl;
		std::cout << "equal_range lower\t: " << *(m4.equal_range(22).first) << std::endl;
		std::cout << "equal_range upper\t: " << *(m4.equal_range(22).second )<< std::endl;

		std::cout << std::endl;

		NAME_SPACE::set<int>::iterator it;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		for (NAME_SPACE::set<int>::reverse_iterator it = m4.rbegin(); it != m4.rend(); it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << *it << std::endl;

		m4.insert(100);
		m4.insert(101);
		m4.insert(102);

		m4.insert(m4.begin(), 0);

		m4.clear();

		m4.insert(m1.begin(), m1.end());

		m4.erase(100);

		std::cout << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		m4.swap(m1);

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << *it << std::endl;

		std::cout << "#===================================== END ======================================#" << std::endl;
	}
	return 0;
}