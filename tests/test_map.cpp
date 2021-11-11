/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:42:24 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/11 11:26:30 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "../map.hpp"

int		main(void) {
	{
		std::cout << "#====================================== map ======================================#" << std::endl;

		NAME_SPACE::map<int, int>	m1;
		NAME_SPACE::map<int, int>	m2(m1);
		NAME_SPACE::map<int, int>	m4;

		m1.insert(NAME_SPACE::make_pair<int, int>(0, 10));
		m1.insert(NAME_SPACE::make_pair<int, int>(1, 11));
		m1.insert(NAME_SPACE::make_pair<int, int>(2, 12));

		NAME_SPACE::map<int, int>	m3(m1.begin(), m1.end());

		m4 = m3;

		std::cout << "size\t: " << m4.size() << std::endl;
		std::cout << "max_size: " << m4.max_size() << std::endl;
		std::cout << "empty\t: " << (m4.empty() ? "true" : "false") << std::endl;

		std::cout << std::endl;

		NAME_SPACE::map<int, int>::iterator it;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << std::endl;

		std::cout << "#===================================== END ======================================#" << std::endl;
	}
	return 0;
}