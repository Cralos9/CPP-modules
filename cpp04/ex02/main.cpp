/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:36 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/02 12:35:46 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main()
{
    int k = 0;
    // Dog basic;
    // {
    //     Dog temp = basic;
    // }
    std::cout << "      Make sound" << std::endl << std::endl;
    
    Animal *j = new Dog();
    Animal *i = new Cat();

    j->makeSound();
    i->makeSound();
    delete i;
    delete j;

    std::cout << std::endl <<  "      Wrong Animal Sound" << std::endl << std::endl;

    WrongAnimal *Wrongi = new WrongCat();
    WrongAnimal *Wrongbasic = new WrongAnimal();

    Wrongbasic->makeSound();
    Wrongi->makeSound();

    delete Wrongbasic;
    delete Wrongi;
    std::cout << std::endl << "      Many Animals" << std::endl << std::endl;
    Animal* Animals[50];
    while (k <25)
        Animals[k++] = new Cat();
    while(k < 50)
        Animals[k++] = new Dog();
    k = 0;
    while(k < 50)
        delete Animals[k++];

    std::cout << std::endl << "      Brain Ideas" << std::endl << std::endl;
    Cat *l = new Cat();
    
    l->getBrain()->showIdea();
    delete l;
return 0;
}