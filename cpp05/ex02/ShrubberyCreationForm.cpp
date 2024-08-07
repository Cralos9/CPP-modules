/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:59:37 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/26 14:11:57 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShubberyCreationForm::ShubberyCreationForm() : AForm("" , 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}
ShubberyCreationForm::~ShubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShubberyCreationForm::ShubberyCreationForm(std::string file) : AForm("Shrubbery Creation", 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	this->_file = file;
}

ShubberyCreationForm::ShubberyCreationForm(const ShubberyCreationForm &cpy) : AForm(cpy.getName(), 25, 5) 
{
	std::cout << "ShubberyCreationForm copy constructor called" << std::endl;
	this->getSigned(cpy.getSignedForm());
	this->_file = cpy._file;
}

ShubberyCreationForm &ShubberyCreationForm::operator=(const ShubberyCreationForm &cpy)
{
	if (this == &cpy)
		return *this;
	this->getSigned(cpy.getSignedForm());
	this->_file = cpy._file;
	return *this;
}

void ShubberyCreationForm::executer() const
{
	std::string file(this->_file + "_shrubbery");
	std::ofstream outputFile(file.c_str());
	if (outputFile.fail()) 
	{
		std::cerr << "Error opening file: " << file << std::endl;
        return ;
    }
	outputFile << "       /\\       " << std::endl;
    outputFile << "      /  \\      " << std::endl;
    outputFile << "     /    \\     " << std::endl;
    outputFile << "    /      \\    " << std::endl;
    outputFile << "   /        \\   " << std::endl;
    outputFile << "  /          \\  " << std::endl;
    outputFile << " /            \\ " << std::endl;
    outputFile << "/______________\\" << std::endl;
    outputFile << "      ||||      " << std::endl;
    outputFile << "      ||||      " << std::endl;
	outputFile.close();
}