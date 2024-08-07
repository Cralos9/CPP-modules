/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:41:21 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/05 10:54:39 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(Serializer const &cpy)
{
	*this = cpy;
}

Serializer &Serializer::operator=(const Serializer &cpy)
{
	if (this == &cpy)
		return (*this);
	*this = cpy;
	return(*this);
}

uintptr_t Serializer::serialize(Data *ptr) 
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) 
{
  return (reinterpret_cast<Data *>(raw));
}