/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:04:52 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/29 11:47:37 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("RandomForm"), _signedForm(false), _signGrade(150), _executeGrade(150)
{
	 std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string const name, const unsigned int signGrade, const unsigned int execGrade) : _name(name), _signGrade(signGrade), _executeGrade(execGrade)
{
	std::cout << "AForm Constructor Called" << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	this->_signedForm = false;
}

AForm::AForm (const AForm &cpy) : _name(cpy._name), _signedForm(), _signGrade(cpy._signGrade), _executeGrade(cpy._executeGrade)
{
	std::cout << "AForm copy Constructor Called" << std::endl;
	this->_signedForm = cpy._signedForm;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm	&AForm::operator=(AForm const &cpy)
{
	if (this == &cpy)
		return *this;
	this->_signedForm = cpy._signedForm;
	return *this;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else if (!this->_signedForm)
	{
		std::cout <<bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signedForm = true;
	}
	else
		std::cout <<bureaucrat.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
}

void AForm::getSigned(bool signature)
{
	this->_signedForm = signature;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSignedForm() const
{
	return this->_signedForm;
}

unsigned int AForm::getSignGrade() const
{
	return this->_signGrade;
}

unsigned int AForm::getExecGrade() const
{
	return this->_executeGrade;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->_signedForm)
		this->executer();
	else
		std::cout << this->_name << " is not signed" << std::endl;
}

std::ostream &operator<<(std::ostream &msg, const AForm &cpy)
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