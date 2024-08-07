/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:04:52 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/29 11:47:55 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("RandomForm"), _signedForm(false), _signGrade(150), _executeGrade(150)
{
	 std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string const name, const unsigned int signGrade, const unsigned int execGrade) : _name(name), _signGrade(signGrade), _executeGrade(execGrade)
{
	std::cout << "Form Constructor Called" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	this->_signedForm = false;
}

Form::Form (const Form &cpy) : _name(cpy._name), _signedForm(), _signGrade(cpy._signGrade), _executeGrade(cpy._executeGrade)
{
	std::cout << "Form copy Constructor Called" << std::endl;
	this->_signedForm = cpy._signedForm;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form	&Form::operator=(Form const &cpy)
{
	if (this == &cpy)
		return *this;
	this->_signedForm = cpy._signedForm;
	return *this;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else if (!this->_signedForm)
	{
		std::cout <<bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signedForm = true;
	}
	else
		std::cout <<bureaucrat.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSignedForm() const
{
	return this->_signedForm;
}

unsigned int Form::getSignGrade() const
{
	return this->_signGrade;
}

unsigned int Form::getExecGrade() const
{
	return this->_executeGrade;
}

std::ostream &operator<<(std::ostream &msg, const Form &cpy)
{
	std::cout << std::endl << "==========Form's Informations==========" << std::endl;
	msg << cpy.getName() << " Form";
	if (cpy.getSignedForm())
		msg << " is signed" << std::endl;
	else
		msg << " is not signed" << std::endl;
	msg << "Sign Grade is " << cpy.getSignGrade() << std::endl;
	msg << "Execute Grade is " << cpy.getExecGrade() << std::endl;
	msg << "=======================================" << std::endl << std::endl;
	return msg;
}