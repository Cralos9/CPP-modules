/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:58:28 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/31 11:00:38 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &cpy);
		AForm *makeForm(std::string Form, std::string target);
		AForm *makeShrubberyForm(std::string target);
		AForm *makeRobotomyForm(std::string target);
		AForm *makePresidentialForm(std::string target);
		class WrongForm : public std::exception
		{
			const char *what() const throw();
		};
};

#endif