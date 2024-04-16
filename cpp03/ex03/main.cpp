/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:37:49 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/16 10:56:08 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap first("Bill");
	std::string name;

	std::cout <<"Choose a name" << std::endl;
	getline(std::cin, name);
	first = name;
	first.highFivesGuys();
	first.guardGate();
	first.attack("Ducks");
	first.whoAmI();
	
}