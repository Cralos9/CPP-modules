/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:52 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/02 12:41:42 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Rogerio";
    std::cout << "[Dog] constructor was called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(Dog &copy) : Animal(copy)
{
    std::cout << "[Dog] copy constructor called" << std::endl;
	this->type = copy.type;
    this->brain = new Brain(*copy.brain);
}

Dog	&Dog::operator=(const Dog &obj)
{
    std::cout << "[Dog] assignation operator called" << std::endl;
	Animal::operator=(obj);
    if (this == &obj)
        return *this;
    delete this->brain;
    this->brain = new Brain(*obj.brain);
	return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "[Dog] Destructor called" << std::endl;
}

 Brain *Dog::getBrain() const
 {
    return(this->brain);
 }

void Dog::makeSound() const
{
    std::cout << "Au au au..."<< std::endl;
}
