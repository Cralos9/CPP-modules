/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:04:57 by cacarval          #+#    #+#             */
/*   Updated: 2024/08/28 15:14:12 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc  < 2)
		{
			std::cerr << "Not enough args" << std::endl;
			return(0);
		}
		PmergeMe sorter;
		std::vector<int> vec;
		std::list<int> lst;
		vec = sorter.containVec(argc, argv);
		lst = sorter.containLst(argc, argv);

		std::cout << "Before: ";
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl << std::endl;

		std::clock_t start = std::clock();
		sorter.mergeVec(vec);
		std::cout << "Vector After: ";
		for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::clock_t end = std::clock();
		double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vec: "
				<< duration << " us" << std::endl << std::endl;;

		start = std::clock();
		sorter.mergeLst(lst);
		std::cout << "List After: ";
		for(std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		end = std::clock();
		duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: "
				<< duration << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}