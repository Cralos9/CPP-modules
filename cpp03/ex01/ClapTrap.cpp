/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:37:51 by cacarval          #+#    #+#             */
/*   Updated: 2024/03/19 11:37:18 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name = _name;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (ClapTrap const &copy)
{
	if (this ==  &copy)
		return(*this);
	this->_name = copy.getName();
	this->_hp = copy.getHP();
	this->_ep = copy.getEP();
	this->_ad = copy.getAD();
	return (*this);
}

std::string ClapTrap::getName(void)const
{
	return(this->_name);
}

int	ClapTrap::getHP(void)const
{
	return(this->_hp);
}

int	ClapTrap::getEP(void)const
{
	return(this->_ep);
}

int	ClapTrap::getAD(void) const
{
	return(this->_ad);
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->GameOver())
		return ;
	std::cout <<"ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep--;
}

bool ClapTrap::GameOver() const
{
	
	if (!this->_hp || !this->_ep)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return(false);
	}
	return(true);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->GameOver())
		return ;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	if(this->_hp == 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " lost "<< amount << " health" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->GameOver())
		return ;
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name << " is repairing and gained " << amount << " health" << std::endl;
	this->_ep--;
}