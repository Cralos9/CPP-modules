/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:20:04 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/18 11:07:57 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string zombiename;
	std::string chumpname;
	Zombie *zombie;

	std::cout << "Enter a name to the zombie: " << std::endl;
	std::cin >> zombiename;
	std::cout << "Enter a name to the chump: " << std::endl;
	std::cin >> chumpname;

	zombie = newZombie(zombiename);
	zombie->announce();

	randomChump(chumpname);

	delete(zombie);
}
