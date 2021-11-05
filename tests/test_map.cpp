/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:42:24 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/05 10:49:06 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "../map.hpp"

int		main(void) {
	{
		std::cout << "#====================================== std::map ======================================#" << std::endl;

		std::map<int, int>	m1;

		std::cout << std::endl;

		std::cout << "#----------------- Empty -----------------#" << std::endl;
		std::cout << (m1.empty() ? "true" : "false") << std::endl;

		std::cout << std::endl;

		std::cout << "#----------------- Size -----------------#" << std::endl;
		std::cout << "size = " << m1.size() << std::endl;


		std::cout << "#======================================== END =========================================#" << std::endl;
	}
	return 0;
}