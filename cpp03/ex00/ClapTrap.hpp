/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:32:36 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/31 15:15:05 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

# define CLEAR "\033c"

class ClapTrap
{
	private:
		std::string _name;
		int _hp;
		int _ep;
		int _ad;
	public:

		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &copy);
		std::string getName(void)const;
		int			getHP(void)const;
		int			getEP(void)const;
		int			getAD(void) const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool GameOver()const;
};

std::ostream	&operator<<(std::ostream &out, ClapTrap const &trap);

#endif