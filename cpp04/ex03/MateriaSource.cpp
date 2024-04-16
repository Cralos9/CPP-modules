/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:49:30 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/16 15:02:47 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"



MateriaSource::MateriaSource()
{
	std::cout << "[MateriaSource] constructor called" << std::endl;
	this->_storageCount = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "[MateriaSource] copy constructor called" << std::endl;
	*this = copy;
}


MateriaSource::~MateriaSource() 
{
	std::cout << "[MateriaSource] destructor called" << std::endl;
	for (int i = 0; i < this->_storageCount; i++)
		delete this->_storage[i];
}


MateriaSource &MateriaSource::operator = (MateriaSource const & src)
{
	int i = 0;
	if (this != &src)
	{
		if (this->_storage[i])
			this->cleanspace();
		this->_storageCount = src._storageCount;
		for (int i = 0; i < 4; i++)
			this->_storage[i] = src._storage[i]->clone();
	}
	return(*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (this->_storageCount < 4)
	{
		// std::cout << "Materia Source " << materia->getType() << " learned" << std::endl;
		this->_storage[this->_storageCount++] = materia;
	}
	else
		std::cout << "Storage is full" << std::endl;

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < this->_storageCount; i++)
	{
		if(this->_storage[i]->getType() == type)
		{
			// std::cout << type << " Materia was created" << std::endl;
			return(this->_storage[i]->clone());
		}
	}
	std::cout << "Materia hasn't been learned" << std::endl;
	return(0);
}



void MateriaSource::cleanspace()
{
	for(int i = 0; i < 4 ; i++)
		delete this->_storage[i];
}