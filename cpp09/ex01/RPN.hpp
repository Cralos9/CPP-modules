/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:39:18 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/28 13:51:09 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(std::string string);
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &cpy);
		void parseString(std::string string);
		void makeOperation(char operand);
		class ErrorThrows : public std::exception
		{
			public:
				const char * what() const throw();
		};
	private:
		std::stack<int> _stack;
};