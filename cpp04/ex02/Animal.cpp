/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:40 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/02 12:35:19 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "[Animal] constructor was called" << std::endl;
    this->type = "Default";
}
Animal::~Animal()
{
    std::cout << "[Animal] Destructor called" << std::endl;
}

Animal::Animal(Animal &copy)
{
    std::cout << "[Animal] copy constructor called" << std::endl;
	*this = copy;
}


// void Animal::makeSound() const
// {
//     std::cout << "[Animal] sound" << std::endl;
// }

std::string Animal::getType() const
{
    return(this->type);
}