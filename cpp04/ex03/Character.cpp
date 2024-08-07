/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:39:18 by cacarval          #+#    #+#             */
/*   Updated: 2024/06/06 15:12:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for(int i = 0; i < 4;i++)
		this->_inventory[i] = NULL;
	this->_inventoryCount = 0;
}

Character::Character(std::string name)
{
	this->_name = name;
	this->_inventoryCount = 0;
	for(int i = 0; i < 4;i++)
		this->_inventory[i] = NULL;
	this->list = new spellHolder();
	this->head = this->list;
}

Character::Character(const Character &copy)
{
	// std::cout << "[Character] copy constructor was called" << std::endl;
	for(int i = 0; i < 4;i++)
		this->_inventory[i] = NULL;
	*this = copy;
}

Character::~Character()
{
	spellHolder *tmp;
	this->list = this->head;
	while(this->list)
	{
		tmp = this->list;
		this->list = this->list->next;
		delete tmp->spell;
		delete tmp;
	}
	for (int i = 0; i < this->_inventoryCount; i++)
		delete this->_inventory[i];
}

std::string const &Character::getName() const
{
	return(this->_name);
}

Character &Character::operator = (Character const & src)
{
	if (this != &src)
	{
		this->_inventoryCount = src._inventoryCount;
		this->cleanspace();
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return(*this);
}

void Character::equip(AMateria *m)
{
	if (m == 0)
		std::cout << "Materia doesn't exist" << std::endl;
	else if (m->flag)
			std::cout << "Materia is already equiped"<< std::endl;
	else
	{
		for(int i = 0; i < 4; i++)
		{
				if (this->_inventory[i] == NULL && !m->flag)
				{
					this->_inventory[i] = m;
					this->_inventoryCount++;
					m->flag = 1;
					break;
				}
		}
	}
	// else
	// 	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if(idx >= 0 && idx < this->_inventoryCount)
	{
		std::cout << "Unequipped" << std::endl;
		this->list->spell = this->_inventory[idx];
		this->list->next = new spellHolder();
		this->_inventory[idx] = NULL;
		this->list = this->list->next;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < this->_inventoryCount)
		this->_inventory[idx]->use(target);
	else
		std::cout << "No Materia on this index" << std::endl;
}

void Character::cleanspace()
{
	for(int i = 0; i < 4 ; i++)
		delete this->_inventory[i];
}