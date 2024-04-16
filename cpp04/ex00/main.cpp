/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:36 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/28 12:47:50 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
    std::cout << "      Make sound" << std::endl << std::endl;
    
    Animal *j = new Dog();
    Animal *i = new Cat();
    Animal *basic = new Animal;

    basic->makeSound();
    j->makeSound();
    i->makeSound();

    delete i;
    delete j;
    delete basic;

    std::cout << std::endl <<  "      Wrong Animal Sound" << std::endl << std::endl;

    WrongAnimal *Wrongi = new WrongCat();
    WrongAnimal Wrongbasic;

    Wrongbasic.makeSound();
    Wrongi->makeSound();
    return 0;
}