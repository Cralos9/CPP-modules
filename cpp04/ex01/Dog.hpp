/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:57:08 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/15 13:50:41 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(Dog &copy);
        Dog	&operator=(const Dog &obj);
        Dog(std::string type);
        Brain *getBrain() const;
        void makeSound() const;
    
    protected:
        Brain* brain;


};

#endif