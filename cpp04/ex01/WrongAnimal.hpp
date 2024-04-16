/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:32 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/20 11:22:58 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP


#include <iostream>
#include <string>

class WrongAnimal
{
    public:

        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(WrongAnimal &copy);
        void makeSound() const;
        std::string getType() const;

    protected:
    
        std::string type;
    
};

#endif