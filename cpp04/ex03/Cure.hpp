/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:45:05 by cacarval          #+#    #+#             */
/*   Updated: 2024/04/16 12:36:27 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP

#include "AMateria.hpp"


class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &copy);
		void use(ICharacter& target);
		AMateria* clone() const;

};



#endif