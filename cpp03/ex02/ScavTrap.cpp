/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:40:14 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/17 10:42:05 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
    this->_name = _name;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called"<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->GameOver())
		return ;
	std::cout <<"ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " enters guard Mode" << std::endl; 
}