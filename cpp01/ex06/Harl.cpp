/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:18:03 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/29 10:22:58 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{

	void (Harl::*func_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
                                   &Harl::error};
	std::string str(level);
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;

	while(i <= 3)
	{
		if (level == levels[i])
			break;
		if (i == 3 && level != levels[i])
		{
			i = -1;
			break;
		}
		i++;
	}
	switch (i) 
	{
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
        case 0:
            (this->*func_ptr[0])();
			// Intentional fall-through
        case 1:
            (this->*func_ptr[1])();
			// Intentional fall-through
        case 2:
            (this->*func_ptr[2])();
			// Intentional fall-through
        case 3:
            (this->*func_ptr[3])();
            break;
	}

}

void Harl::debug()
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<< std::endl;
}
void Harl::info()
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<< std::endl;
}
void Harl::warning()
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error()
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}
