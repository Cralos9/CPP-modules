/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:24 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/20 11:22:25 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal()
{
    std::cout << "[WrongCat] Constructor called" << std::endl;
    this->type = "Gato";
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "[WrongCat] Copy constructor called" << std::endl;
    *this = copy;
}

void WrongCat::makeSound() const
{
    std::cout << "Miau, miau, miau" << std::endl;
}