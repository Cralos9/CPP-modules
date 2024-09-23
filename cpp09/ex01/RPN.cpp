/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:30:02 by cacarval          #+#    #+#             */
/*   Updated: 2024/09/02 14:19:06 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN(){}

RPN::~RPN(){}


RPN::RPN(std::string string)
{
	parseString(string);
}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;
}

RPN &RPN::operator=(const RPN &cpy)
{
	if (this == &cpy)
		return (*this);
	this->_stack = cpy._stack;
	return(*this);
}

void RPN::makeOperation(char op)
{
	long result;
	if (this->_stack.size() < 2)
		 throw ErrorThrows();
	long operand1 = this->_stack.top();
	this->_stack.pop();
	long operand2 = this->_stack.top();
	this->_stack.pop();
	if (!operand1)
		if (op == '/')
			throw ErrorThrows();
	if (op == '-')
		result = (operand2 - operand1);
	if (op == '+')
		result = (operand2 + operand1);
	if (op == '/')
		result = (operand2 / operand1);
	if (op == '*')
		result = (operand2 * operand1);
	if (result > __INT_MAX__ || result < -2147483648)
		throw ErrorThrows();
	this->_stack.push(result);
}

void RPN::parseString(std::string string)
{
	size_t i = -1;
	bool flag = false;
	if(string.length() == 1 && (string[0] >= '0' && string[0] <= '9'))
	{
		std::cout << "Result: " << string[0] << std::endl;
		return;
	}
	while(++i < string.length())
	{
		if (string[i] == ' ')
			continue;
		else if (string[i] == '-' || string[i] == '+'|| string[i] == '*'|| string[i] == '/' )
		{
			flag = true;
			makeOperation(string[i]);
			continue;
		}
		else if (string[i] < '0' || string[i] > '9')
			throw ErrorThrows();
		this->_stack.push(string[i] - '0');
	}
	if (!flag || this->_stack.size() > 1)
		throw ErrorThrows();
	std::cout << "Result: " << this->_stack.top() << std::endl;
}

const char * RPN::ErrorThrows::what() const throw()
{
	return ("Error");
}