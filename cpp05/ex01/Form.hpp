/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:04:49 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/16 12:41:58 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signedForm;
		const unsigned int _signGrade;
		const unsigned int _executeGrade;
	public:
		Form();
		~Form();
		Form(std::string const name, const unsigned int signGrade, const unsigned int execGrade);
		Form(Form const &cpy);
		Form &operator=(const Form &other);
		std::string getName() const;
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

};

std::ostream &operator<<(std::ostream &msg, const Form &cpy);

#endif