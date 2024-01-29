/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:37:28 by cacarval          #+#    #+#             */
/*   Updated: 2024/01/24 14:09:58 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(std::string &file, std::string &s1, std::string &s2) 
{
    std::ifstream inputFile(file.c_str());
    if (inputFile.fail()) {
        std::cout << "Failed to open Input File" << std::endl;
        return;
    }

    std::string replaceName = file + ".replace";
    std::ofstream outputFile(replaceName.c_str());
    if (outputFile.fail()) {
        std::cout << "Failed to open Output File" << std::endl;
        inputFile.close();
        return;
    }

 std::string line;
    size_t pos = 0;

    while (std::getline(inputFile, line)) {
        pos = 0;
        size_t startPos = 0;

        while ((pos = line.find(s1, startPos)) != std::string::npos) {
            outputFile << line.substr(startPos, pos - startPos) << s2;
            startPos = pos + s1.length();
        }

        outputFile << line.substr(startPos) << std::endl;
    }


    inputFile.close();
    outputFile.close();
    std::cout << "Replacement complete. Check " << replaceName << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        return std::cout << "Insufficient arguments" << std::endl, 1;
    }

    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceInFile(file, s1, s2);

    return 0;
}
