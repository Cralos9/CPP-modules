/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:43:02 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/16 15:34:33 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


typedef struct s_test
{

	struct s_test *next;
	AMateria *atum; 

}	t_test;


class Character : public ICharacter
{
	private:
	std::string _name;
	int _inventoryCount;
	AMateria *_inventory[4];
	
	public:
	Character();
	Character(std::string name);
	Character(const Character &copy);
	~Character();
	void cleanspace();
	Character & operator = (Character const & src);
	void equip(AMateria* m);
	std::string const & getName() const;
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	t_test *azul;
	t_test *head;
};

#endif