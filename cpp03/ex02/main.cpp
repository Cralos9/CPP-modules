/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:37:49 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/19 11:36:16 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap first("Bill");
	std::string name;

	// std::cout <<"Choose a name" << std::endl;
	// getline(std::cin, name);
	// first = name;
	first.highFivesGuys();
	first.attack("Ducks");
	
}