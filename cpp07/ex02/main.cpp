/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:10:26 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/06 14:19:02 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> teste(10);
	for(int i = 0; i < 10; i++)
		teste[i] = i;
	std::cout << teste[8] << std::endl;
}