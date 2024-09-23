/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:55:36 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/30 12:52:06 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class Bitcoin
{
	public:
		Bitcoin();
		~Bitcoin();
		Bitcoin(std::string file);
		Bitcoin(const Bitcoin &cpy);
		Bitcoin &operator=(const Bitcoin &cpy);
		void makeDatabase();
		void getInputFile(std::string file);
		float findValue(std::string);
	private:
		std::map<std::string, float> _database;
};



#endif