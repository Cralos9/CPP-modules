/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:27:09 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/18 14:48:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A("Rogerio", 12);
		Bureaucrat B("Constancio", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Wrong Grade"<< std::endl;
	}
	std::cout << "============================" << std::endl;
    try 
	{
        Bureaucrat A("Rogerio", 2);
        std::cout << A;
		Form C("Pato", 2, 1);
		C.beSigned(A);
		std::cout << C;
    } 
	catch (std::exception & e) 
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
	
    return 0;
}