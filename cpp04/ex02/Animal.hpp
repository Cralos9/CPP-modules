/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:56:43 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/02 12:35:30 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP


#include <iostream>
#include <string>
    
class Animal
{
    public:

        Animal();
        virtual ~Animal();
        Animal(Animal &copy);
        virtual void makeSound() const = 0;
        std::string getType() const;

    protected:
    
        std::string type;
    
};

#endif