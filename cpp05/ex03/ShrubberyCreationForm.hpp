/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:59:39 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/22 13:03:13 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShubberyCreationForm : public AForm
{
	public:
		ShubberyCreationForm();
		~ShubberyCreationForm();
		ShubberyCreationForm(std::string file);
		ShubberyCreationForm(const ShubberyCreationForm &cpy);
		ShubberyCreationForm &operator=(const ShubberyCreationForm & other);
		void executer() const;
	private:
		std::string _file;
		
};


#endif