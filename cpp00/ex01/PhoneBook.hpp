/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:26:13 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/15 11:21:09 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();

	private:
		int		_id;
		Contacts	_contacts[8];
		void	_printTable(void);
};

#endif
