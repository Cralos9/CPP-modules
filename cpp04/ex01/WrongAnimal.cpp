/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:22 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/28 12:42:51 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "[WrongAnimal] constructor was called" << std::endl;
    this->type = "Default";
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
    std::cout << "[WrongAnimal] copy constructor called" << std::endl;
	*this = copy;
}


void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}