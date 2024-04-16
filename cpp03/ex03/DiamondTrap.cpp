/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:38:43 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/25 10:57:05 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string _name):ScavTrap(_name), FragTrap(_name){
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    new_name = _name;
    ClapTrap::_name = _name + "_clap_name";
    ClapTrap::_hp = 100;
    ClapTrap::_ep = 50;
    ClapTrap::_ad = 30;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other):ClapTrap(other), ScavTrap(other), FragTrap(other){
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = other;
}

void DiamondTrap::printpoints(){
    std::cout << "DiamondTrap Hit points are " << FragTrap::_hp << ", Energy points are " <<
        ScavTrap::_ep << ", Attack damage is " << FragTrap::_ad << std::endl;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap name is " << new_name << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}