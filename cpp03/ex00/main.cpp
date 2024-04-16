/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:37:49 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/15 10:49:21 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap first;
	std::string name;

	std::cout <<"Choose a name" << std::endl;
	getline(std::cin, name);
	first = name;
	std::cout <<"Press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << CLEAR;
	first.attack("Ducks");
	first.takeDamage(9);
	std::cout << "ClapTrap " << first.getName() << " has " << first.getHP()<< " hp and " << first.getEP()<< " ep"<< std::endl;
	first.beRepaired(8);
	std::cout << "ClapTrap " << first.getName() << " has " << first.getHP()<< " hp and " << first.getEP()<< " ep"<< std::endl;
	first.takeDamage(9);
	first.beRepaired(8);
	std::cout << std::endl;
	std::cout <<"Press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << CLEAR;
	
}