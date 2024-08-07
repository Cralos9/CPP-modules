/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:07:00 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/06 11:25:48 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"


void printElement(int element) {
    std::cout << element << " ";
}


int main()
{
	int array[4] = {1 , 2, 3,4};

	iter(array, 4, printElement);
}