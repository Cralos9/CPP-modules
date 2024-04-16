/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:46 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/28 13:15:55 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal()
{

    this->type = "Gato";
    std::cout << "[Cat] Constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::~Cat()
{
    delete(this->brain);
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
    if (this == &obj)
        return *this;
    delete this->brain;
    this->brain = new Brain(*obj.brain);
	return (*this);
}

Brain *Cat::getBrain() const
 {
    return(this->brain);
 }


void Cat::makeSound() const
{
    std::cout << "Miau, miau, miau" << std::endl;
}