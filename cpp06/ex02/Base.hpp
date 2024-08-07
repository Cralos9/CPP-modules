/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:00:27 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/05 12:31:27 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <ctime>
#include <iostream>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base();
	
};

void identify(Base* p);
void identify(Base& p);
Base * generate(void);

#endif