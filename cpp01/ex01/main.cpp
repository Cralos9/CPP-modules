/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:47:17 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/18 15:55:36 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <iomanip>

void mainheader()
{
	std::cout << CLEAR;
	std::cout << "******************Zombie Horde********************" << std::endl << std::endl;
}

int main(void)
{
	int hordesize;
	std::string zombieName;

	while (1)
	{
		std::cout << "Select a number of zombies" << std::endl;
		std::cin >> hordesize;
		if (std::cin.fail() || hordesize <= 0)
		{
			std::cout << "Invalid input. Try again with a positive integer." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
			break ;
	}
	std::cout << "Enter a name for the horde: " << std::endl;
    std::cin >> zombieName;
	
	mainheader();
	Zombie *horde = zombieHorde(hordesize, zombieName);
	for(int i = 0; i < hordesize; i++)
		horde[i].announce();

	delete [] horde;
	return(0);		
}
