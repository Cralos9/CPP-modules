/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:26:14 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/12 15:20:49 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			RPN test(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Wrong Arguments" << std::endl;
}