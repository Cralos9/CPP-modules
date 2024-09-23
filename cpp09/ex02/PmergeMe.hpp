/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:05:01 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/28 13:54:03 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cpy);
		PmergeMe &operator=(const PmergeMe &cpy);
		std::vector<int> containVec(int argc, char **array);
		std::list<int> containLst(int argc, char **array);
		void fordSort();
		void divideAndConquer(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void mergeVec(std::vector<int> &vec);
		void mergeLst(std::list<int> &lst);
		void insertionLst(std::list<int> &lst);
		void insertionVec(std::vector<int> &vec);
	
		class Errors : public std::exception
		{
			const char *what() const throw();
		};
	private:
		std::list<int> _list;
		std::vector<int> _vec;
};