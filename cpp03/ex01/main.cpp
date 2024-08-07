/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:37:49 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/17 10:47:44 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap first("Bill");
	std::string name;

	// std::cout <<"Choose a name" << std::endl;
	// getline(std::cin, name);
	// first = name;
	first.guardGate();
	first.attack("Ducks");
	
}