/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:53:45 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/29 11:15:49 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :_name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade()
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;		
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	 std::cout << "Bureaucrat copy assignment called." << std::endl;
	if (this == &cpy)
		return *this;
	this->_grade = cpy._grade;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

std::ostream &operator<<(std::ostream &msg, const Bureaucrat &cpy)
{
	msg << cpy.getName() << ", bureaucrat grade, " << cpy.getGrade() << "." << std::endl;	
	return msg;
}