/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:51:50 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/02 14:34:11 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>


Brain::Brain()
{
    std::cout << "[Brain] constructor was called" << std::endl;
    std::string const	ideas[] =
	{
		"I need to eat",
		"I need to sleep",
		"I need to play",
		"I need to run",
		"I need to walk",
		"I need to drink",
		"I need attention",
		"I need to be petted",
		"I need to be brushed",
		"I need to be washed",
	};
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[rand() % 10];
}

Brain::Brain(Brain &copy)
{   
    int i = -1;
    std::cout << "[Brain] copy constructor called.\n";
    while(++i < 100)
        this->ideas[i] = copy.ideas[i];
}

Brain::~Brain()
{
    std::cout << "[Brain] destructor was called" << std::endl;
}

void Brain::showIdea()
{
    for (int i = 0; i < 5; i++)
		std::cout << "Idea #" << i + 1 << ": " << this->ideas[i] << std::endl;
}