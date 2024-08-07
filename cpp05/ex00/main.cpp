/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:27:09 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/16 14:55:10 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A("Rogerio", 12);
		Bureaucrat B("Constancio", 0);
		Bureaucrat C("Arnaldo", 151);
	}
	catch (std::exception & e)
	{
		std::cout << "Wrong Grade"<< std::endl;
	}
	std::cout << "============================" << std::endl;
    try {
        Bureaucrat A("Rogerio", 1);
        std::cout << A;

        A.incrementGrade();
        std::cout << A;
    } catch (std::exception & e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}