/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:55:33 by cacarval          #+#    #+#             */
/*   Updated: 2024/09/03 14:16:24 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


Bitcoin::Bitcoin()
{

}

Bitcoin::~Bitcoin()
{

}

float Bitcoin::findValue(std::string date)
{
	std::map<std::string, float>::iterator it = this->_database.begin();

	while (it != this->_database.end())
	{
		if (date <= it->first)
		{
			if (date < it->first)
			{
				if (it != this->_database.begin())
					it--;
			}
			return(it->second);
		}
		it++;
	}
	it--;
	return (it->second);
}

bool check_date(int year, int month, int day)
{
	if ((month == 4 || month == 6 || month == 9 ||month == 11) 
		&& day > 30)
		return(false);
	else if (month == 2 && day > 28)
	{
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day == 29) 
			return(true);
		return(false);
	}
	else if (day > 31)
		return(false);
	return(true);
}

void Bitcoin::getInputFile(std::string file)
{
	std::ifstream input_file(file.c_str());
	std::string str;
	if (!input_file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return ;
    }
	int i = 0;
	while (std::getline(input_file, str)) 
	{
		if (i++ == 0)
      		continue;
		std::string datePart = str.substr(0, str.find(" | "));
		struct tm tm = {};
		if (datePart == "")
			continue;
		std::string year = datePart.substr(0, str.find("-"));
		if (!strptime(datePart.c_str(), "%Y-%m-%d", &tm) || year.length() < 4 
			|| (datePart[0] < '0' || datePart[0] > '9'))
		{
			std::cerr << "Error: bad input => " << datePart << std::endl;
			continue ;
		}
		std::string month = (datePart.substr(str.find("-")+ 1, 2));
		std::string day = datePart.substr(8, str.find(" | "));
		if (!check_date(std::atoi((year).c_str()), std::atoi(month.c_str()), 
			std::atoi(day.c_str())) || day.find_first_not_of("0123456789") != std::string::npos || month.length() < 2 || day.length() < 2)
		{
			std::cerr << "Error: bad input => " << datePart << std::endl;
			continue ;
		}
		std::string amountPart = str.substr(str.find(" | ") + 3);
		float amount = 0.0;
		if ((isdigit(amountPart[0]) || amountPart[0] == '-'))
			amount = atof(amountPart.c_str());
		else
		{
			std::cerr << "Error: bad input => " << str << std::endl;
			continue ;
		}
		if (amount < 0 || amount > 1000)
		{
			if (amount < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			if (amount > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		if ((str.find(" | ")) == std::string::npos  || !(amountPart.find_first_not_of("0123456789.") == std::string::npos)
			|| amountPart.find_first_of(".") != amountPart.find_last_of(".")
				|| !isdigit(amountPart[amountPart.length() - 1]))
		{
			std::cerr << "Error: bad input => " << str << std::endl;
			continue ;
		}
		float value = findValue(datePart);
		std::cout << datePart << " => " << amount << " = " << value * amount << std::endl;	
    }
}

void Bitcoin::makeDatabase()
{
	std::ifstream data_file("data.csv");
	std::string str;
	
    if (!data_file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return ;
    }

	int i = 0;
	while (std::getline(data_file, str)) 
	{
		if (i++ == 0)
      		continue;
		std::string datePart = str.substr(0, str.find(','));
		std::string pricePart = str.substr(str.find(',') + 1);
		this->_database[datePart] = atof(pricePart.c_str());
	}
}

Bitcoin::Bitcoin(std::string file)
{
	makeDatabase();
	getInputFile(file);

}

Bitcoin::Bitcoin(const Bitcoin &cpy)
{
	*this = cpy;
}

Bitcoin &Bitcoin::operator=(const Bitcoin &cpy)
{
	if (this == &cpy)
		return (*this);
	this->_database = cpy._database;
	return (*this);
}


