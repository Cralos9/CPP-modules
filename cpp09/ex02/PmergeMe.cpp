/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:04:59 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/29 12:48:01 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}


PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
	if (this == &cpy)
		return(*this);
	this->_list = cpy._list;
	this->_vec = cpy._vec;
	return(*this);
}

void pairSort(std::pair<int, int> &p) 
{
    if (p.first < p.second) {
        std::swap(p.first, p.second);
    }
}


void iterateVectors(std::vector<int> vec)
{
	for (std::vector<int>::iterator it= vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
}


std::vector<size_t> generateJacobthal(size_t n)
{
	std::vector<size_t> jacob;
    jacob.push_back(0);
    if (n == 0) return jacob;
    jacob.push_back(1);
    if (n == 1) return jacob;

    while (jacob.back() < n) 
	{
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return jacob;
}

void modLstInsert(std::list<int>& low_values, const std::list<int>& high_values, std::list<int> vec)
{
	std::vector<size_t> jacob;
    std::list<int> merged;
    merged = high_values;
	if (!vec.empty()) 
	{
		low_values.push_back(vec.back());
		vec.pop_back();
	}
	jacob = generateJacobthal(low_values.size());
	for (size_t i = 1; i < jacob.size(); i++)
	{
        for (size_t j = jacob[i]; j > jacob[i - 1]; j--) 
		{
            if (j <= low_values.size()) 
			{
				std::list<int>::iterator it = low_values.begin();
				std::advance(it, j - 1);
                std::list<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), *it);
                merged.insert(pos, *it);
            }
        }
    }
	low_values = merged;
}

void modVecInsert(std::vector<int>& low_values, const std::vector<int>& high_values, std::vector<int> vec)
{
	std::vector<size_t> jacob;
    std::vector<int> merged;
    merged = high_values;
	if (!vec.empty()) 
	{
		low_values.push_back(vec.back());
		vec.pop_back();
	}
	jacob = generateJacobthal(low_values.size());
	for (size_t i = 1; i < jacob.size(); i++)
	{
        for (size_t j = jacob[i]; j > jacob[i - 1]; j--) 
		{
            if (j <= low_values.size()) 
			{
                std::vector<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), low_values[j - 1]);
                merged.insert(pos, low_values[j - 1]);
            }
        }
    }
	low_values = merged;
}


void PmergeMe::mergeVec(std::vector<int>& vec) 
{
    if (vec.size() <= 1) return;

	std::vector<int> leftover;
    std::vector<std::pair<int, int> > pairs;
	 for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            std::pair<int, int> p = std::make_pair(vec[i], vec[i + 1]);
            pairSort(p);
            pairs.push_back(p);
        } else 
		{
			leftover.clear();
        	leftover.push_back(vec[i]);
        }
    }
    std::vector<int> low_values;
    std::vector<int> high_values;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) 
	{
        low_values.push_back(it->second);
        high_values.push_back(it->first);
	}
    mergeVec(high_values);
    modVecInsert(low_values, high_values, leftover);
	
	vec.clear();
    vec = low_values;
}

void PmergeMe::mergeLst(std::list<int>& lst) 
{
    if (lst.size() <= 1) return;

	std::list<int> leftover;
	
    std::list<std::pair<int, int> > pairs;
	
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) 
	{
		std::list<int>::iterator curr = it;
		std::list<int>::iterator next = it;
		++next;

		if (next != lst.end()) 
		{
			if (*curr > *next) 
			{
				std::pair<int, int> p = std::make_pair(*curr, *next);
				pairs.push_back(p);
			}
			else 
			{
				std::pair<int, int> p = std::make_pair(*next, *curr);
				pairs.push_back(p);
			}
        it = next;
   		}
		else 
		{
		
			leftover.clear();
			leftover.push_back(*curr);
		}

    }
    std::list<int> low_values;
    std::list<int> high_values;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) 
	{
        low_values.push_back(it->second);
        high_values.push_back(it->first);
	}
    mergeLst(high_values);
    modLstInsert(low_values, high_values, leftover);
	
	lst.clear();
    lst = low_values;
}

std::list<int> PmergeMe::containLst(int argc, char **array)
{
	for (int i = 1; i < argc; i++)
	{
		this->_list.push_back(std::atoi(array[i]));
		if (this->_list.back() < 0)
			throw "No negative numbers allowed";
	}
	return(this->_list);
}

std::vector<int> PmergeMe::containVec(int argc, char **array)
{
	for (int i = 1; i < argc ; i++)
	{
		this->_vec.push_back(std::atoi(array[i]));
		if (this->_vec.back() < 0)
			throw Errors();
	}
	return(this->_vec);
}

const char *PmergeMe::Errors::what() const throw()
{
	return("No negative numbers allowed");
}

