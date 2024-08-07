/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:49:24 by cacarval          #+#    #+#             */
/*   Updated: 2024/07/29 11:48:44 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade;

	public:
	
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &other);
		std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);
		class GradeTooHighException : public std::exception 
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &msg, const Bureaucrat &cpy);


#endif