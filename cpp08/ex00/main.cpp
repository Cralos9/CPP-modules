/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:56:01 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/07 11:18:24 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() 
{
	try
	{
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5); 
        int value_to_find = 6;
        easyfind(vec, value_to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    

  
    return 0;
}