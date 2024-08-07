/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:55:36 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/05 10:57:18 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data Teste = {2};

	std::cout << Teste.stuff << std::endl;

	uintptr_t convert = Serializer::serialize(&Teste);

	std::cout << *reinterpret_cast<int *>(convert) << std::endl;

	Data *deserialized = Serializer::deserialize(convert);
	
	std::cout << deserialized->stuff << std::endl; 
	
}