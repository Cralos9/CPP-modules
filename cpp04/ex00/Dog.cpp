/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:52 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/28 12:48:16 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "[Dog] constructor was called" << std::endl;
    this->type = "Rogerio";
}

Dog::Dog(Dog &copy) : Animal(copy)
{
    std::cout << "[Dog] copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
    std::cout << "[Dog] assignation operator called" << std::endl;
	Animal::operator=(obj);
	return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Au au au..."<< std::endl;
}
