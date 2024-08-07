/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:59:31 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/26 14:11:33 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy.getName(), 72, 45)
{
	std::cout << "RobotomyRequestFrom copy constructor called" << std::endl;
	this->getSigned(cpy.getSignedForm());
	this->_target = cpy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this == &cpy)
		return *this;
	this->getSigned(cpy.getSignedForm());
	this->_target = cpy._target;
	return *this;
}

void RobotomyRequestForm::executer() const
{
	std::srand(std::time(0));
	if (rand() % 2 == 0)
	{
		std::cout << this->_target << " has been Robotomized" << std::endl;
	}
	else
		std::cout << "Robotomy Failed" << std::endl;
}