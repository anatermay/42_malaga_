/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedReplacer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/02/02 14:04:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedReplace.hpp"

std::string	SedReplacer::replacedContentFile()
{
	std::string	replacedFile;
	size_t		position;

	replacedFile = this->fileName;
	if (replacedFile.find(".") == std::string::npos)
		return (replacedFile + ".replace");
	position = replacedFile.find(".");
	while (replacedFile[position])
		position++;
	replacedFile.erase(replacedFile.find("."), position - 1);
	replacedFile = replacedFile + ".replace";
	return (replacedFile);
}

SedReplacer::SedReplacer(std::string fileName, std::string findStr, std::string replaceStr)
{
	this->fileName = fileName;
	this->findStr = findStr;
	this->replaceStr = replaceStr;
	this->fileNameReplace = replacedContentFile();
}

SedReplacer::~SedReplacer()
{
	return ;
}

void	SedReplacer::replaceInFile()
{
	std::ifstream	fileContent(fileName.c_str());
	std::ofstream	outputFile(this->fileNameReplace.c_str());
	std::string		line;
	size_t			position;

	if (!fileContent.is_open())
	{
		std::cerr << "Error:\n\tCould not open file: " << fileName << std::endl;
		return ;
	}
	if (!outputFile.is_open())
	{
		std::cerr << "Error:\n\tCould not create output file: " << this->fileNameReplace << std::endl;
		return ;
	}
	while (std::getline(fileContent, line))
	{
		position = line.find(findStr);
		while (position != std::string::npos)
		{
			line.erase(position, findStr.length());
			line.insert(position, replaceStr);
			position = line.find(findStr, position + replaceStr.length());
		}
		outputFile << line << std::endl;
	}
	fileContent.close();
	outputFile.close();
	std::cout << "File processed successfully! Output file: " << this->fileNameReplace << std::endl;
}
