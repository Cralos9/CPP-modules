/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:38:51 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/25 10:55:20 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP


#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

    public:
        DiamondTrap(std::string _name);
        ~DiamondTrap();
        DiamondTrap( DiamondTrap const &other);

        void printpoints();
        using ScavTrap::attack;
        void whoAmI();
    
    protected:
        std::string new_name;
        void set_attackfunction();
    
};

#endif