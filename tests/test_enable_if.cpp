/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_enable_if.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:56:32 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/03 12:21:20 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../utility.hpp"

int		main(void) {
	
	{
		std::cout << "======================= TEST std::equal =======================" << std::endl;
		// std::cout << std::enable_if<std::is_integral<int>::value>::type << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
	{
		std::cout << "======================= TEST ft::equal =======================" << std::endl;
		// std::cout << (ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) ? "true" : "false") << std::endl;
		std::cout << "==============================================================" << std::endl;
	}

	return 0;
}