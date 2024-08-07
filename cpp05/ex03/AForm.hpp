/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:04:49 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/26 14:20:17 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signedForm;
		const unsigned int _signGrade;
		const unsigned int _executeGrade;
	public:
		AForm();
		virtual ~AForm() = 0;
		AForm(std::string const name, const unsigned int signGrade, const unsigned int execGrade);
		AForm(AForm const &cpy);
		AForm &operator=(const AForm &other);
		std::string getName() const;
		void getSigned(bool signature);
		bool getSignedForm() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;
		void beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		virtual void executer() const = 0;
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &msg, const AForm &cpy);

#endif