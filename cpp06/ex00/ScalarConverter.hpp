/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:09:05 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/05 14:45:14 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &cpy);

		static bool	checkInt(std::string string);
		static void print(char c, int i, float f, double d);
		static int	isDisplayable(char c);
		static bool checkFloat(std::string string);
		static bool checkDouble(std::string string);
		static void printExcept(float f, double d);
		static bool checkSignal(std::string string);
		static int checkOverflows(std::string string);
		static void fromChar(std::string);
		static void fromInt(std::string);
		static void fromFloat(std::string);
		static void fromDouble(std::string);
		class ImpossibleExcept : public std::exception
		{
			public:
				const char *what() const throw();
		};
	public:
		static void convert(std::string string);
};

#endif