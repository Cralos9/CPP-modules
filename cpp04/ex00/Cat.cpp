/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:46 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/28 12:49:47 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal()
{
    std::cout << "[Cat] Constructor called" << std::endl;
    this->type = "Gato";
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called" << std::endl;
}

Cat::Cat(Cat &copy) : Animal(copy)
{
    std::cout << "[Cat] Copy constructor called" << std::endl;
    *this = copy;
}

Cat	&Cat::operator=(const Cat &obj)
{
    std::cout << "[Cat] assignation operator called" << std::endl;
	Animal::operator=(obj);
	return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Miau, miau, miau" << std::endl;
}