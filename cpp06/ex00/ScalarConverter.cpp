/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:09:01 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/06 15:32:41 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}


void ScalarConverter::fromInt(std::string string)
{
	int i = atoi(string.c_str());
	char c = static_cast<unsigned char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	ScalarConverter::print(c, i, f, d);
}

void ScalarConverter::fromFloat(std::string string)
{
	float f = atof(string.c_str());
	char c = static_cast<unsigned char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	ScalarConverter::print(c, i, f, d);
}

void ScalarConverter::fromDouble(std::string string)
{
	
	double d = strtod(string.c_str(), NULL);
	char c = static_cast<unsigned char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	ScalarConverter::print(c, i, f, d);
}

void ScalarConverter::fromChar(std::string string)
{
	char c = string[0];
	double d = static_cast<double>(c);
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);

	ScalarConverter::print(c, i, f, d);
}

bool ScalarConverter::checkDouble(std::string string)
{
	size_t dot = string.find_first_of('.');
	if	(dot == string.find_last_of('.') && isdigit(string[dot + 1])
		&& string.find_first_not_of("0123456789+.-") == std::string::npos)
		return(true);
	return(false);
}

bool ScalarConverter::checkFloat(std::string string)
{
	size_t f = string.find_first_of('f');
	if	(isdigit(string[f - 1]) &&string.find_first_of('.') == string.find_last_of('.') 
		&& string.find_first_not_of("0123456789f.-+") == std::string::npos && f == string.length() - 1)
		return(true);
	return(false);
}

int ScalarConverter::checkOverflows(std::string string)
{
	double check = strtod(string.c_str(), NULL);
	
	if (check > INT_MAX || check < INT_MIN)
		return (1);
	return(0);
}

bool ScalarConverter::checkSignal(std::string string)
{
	if(string.find_first_of('+') == string.find_last_of('+') && (string.find_first_of('+') == 0 
		|| string.find_first_of('+') == std::string::npos))
		if(string.find_first_of('-') == std::string::npos)
			return(true);
	if(string.find_first_of('-') == string.find_last_of('-') && (string.find_first_of('-')== 0 
		|| string.find_first_of('-') == std::string::npos))
		if(string.find_first_of('+') == std::string::npos)
			return(true);
	return(false);
}

void ScalarConverter::convert(std::string string)
{
	int check = ScalarConverter::checkOverflows(string);
	bool signal = ScalarConverter::checkSignal(string);
	if (string == "nan" || string == "-inf" || string == "+inf")
	{
		double d = strtod(string.c_str(), NULL);
		float f = static_cast<float>(d);
		ScalarConverter::printExcept(f , d);
		return ;
	}
	else if (string == "-inff" || string == "+inff")
	{
		float f = strtof(string.c_str(), NULL);
		double d = static_cast<double>(f);
		ScalarConverter::printExcept(f , d);
		return ;
	}
	if (signal)
	{
		if (string.length() == 1 && !isdigit(string[0]))
			ScalarConverter::fromChar(string);
		else if (string.find_first_not_of("0123456789+-") == std::string::npos && check == 0)
			ScalarConverter::fromInt(string);
		else if (ScalarConverter::checkDouble(string))
			ScalarConverter::fromDouble(string);
		else if (ScalarConverter::checkFloat(string))
			ScalarConverter::fromFloat(string);
		else
			throw ImpossibleExcept();
	}
	else
		throw ImpossibleExcept();
}

int ScalarConverter::isDisplayable(char c)
{
	if (c >= 32 && c <= 126)
		return(1);
	return(0);
}

void ScalarConverter::printExcept(float f, double d)
{
	std::cout << "==========================" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible"  << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d <<std::endl;
	std::cout << "==========================" << std::endl << std::endl;
}

void ScalarConverter::print(char c, int i, float f, double d)
{
	std::cout << "==========================" << std::endl;
	if (d < -128 || d > 127)
		std::cout << "char: Overflows" << std::endl;
	else
	{
		if (ScalarConverter::isDisplayable(c))
			std::cout << "char: '" << c << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (d > INT_MAX || d < INT_MIN)
	{
		std::cout << "int : Overflows" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	std::cout << "==========================" << std::endl;
}

const char *ScalarConverter::ImpossibleExcept::what() const throw()
{
	return("Impossible to convert");
}