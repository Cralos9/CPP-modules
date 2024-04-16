/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:47 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/22 11:41:45 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;


	std::cout << "String memory Address " << &string << std::endl;
	std::cout << "StringPTR memory Address " << stringPTR << std::endl;
	std::cout << "StringREF memory Address " << &stringREF << std::endl;

	std::cout << "String value " << string << std::endl;
	std::cout << "StringPTR value " << *stringPTR << std::endl;
	std::cout << "StringREF value " << stringREF << std::endl;
}
