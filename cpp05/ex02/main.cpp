/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:27:09 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/05 15:28:23 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat A("Rogerio", 12);
		Bureaucrat B("Constancio", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : "<< e.what() <<  std::endl;
	}
	std::cout << "============================" << std::endl;
    try 
	{
        Bureaucrat A("Rogerio", 5);
        std::cout << A;
		RobotomyRequestForm Teste("Arnaldo");
		RobotomyRequestForm B = Teste;
		std::cout << B;
		B.beSigned(A);
		A.executeForm(B);
    } 
	catch (std::exception & e) 
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
	std::cout << "============================" << std::endl;
	try
	{
		Bureaucrat A("Rogerio", 5);
		ShubberyCreationForm Teste("Shrub");
		Teste.beSigned(A);
		A.executeForm(Teste);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}