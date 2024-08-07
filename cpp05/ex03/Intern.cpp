/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:08:39 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/05 13:02:43 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = cpy;
}

Intern &Intern::operator=(const Intern &cpy)
{
	std::cout << "Intern copy assignment called" << std::endl;
	if (this == &cpy)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string Form, std::string target)
{
	std::string forms[3] = {"robotomy request", "shrubbery request", "presidential pardon"};
	AForm *(Intern::*func_ptr[3])(std::string target) = {&Intern::makeRobotomyForm,&Intern::makeShrubberyForm
		,&Intern::makePresidentialForm};
	AForm *form_ptr;

	int i = -1;
	while(++i < 3)
	{
		if (forms[i] == Form)
		{
			form_ptr = (this->*func_ptr[i])(target);
			std::cout << "Intern created " << form_ptr->getName() << " Form"<< std::endl; 
			return(form_ptr);			
		}
	}
	throw WrongForm();
}

AForm *Intern::makeRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyForm(std::string target)
{
	return new ShubberyCreationForm(target);
}

AForm *Intern::makePresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

const char *Intern::WrongForm::what() const throw()
{
	return ("Form not found");	
}