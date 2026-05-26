/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:31:03 by aternero          #+#    #+#             */
/*   Updated: 2026/04/12 13:39:16 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

void	print_tree(std::ostream &os)
{
	os << "	                                               .\n";
	os << "                                   .         ;  \n";
	os << "      .              .              ;%     ;;   \n";
	os << "        ,           ,                :;%  %;   \n";
	os << "         :         ;                   :;%;'     .,   \n";
	os << ",.         %;     %;            ;        %;'    ,;\n";
	os << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	os << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
	os << "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
	os << "     `%;.     ;%;     %;'         `;%%;.%;'\n";
	os << "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
	os << "         `:%;.  :;bd%;          %;@%;'\n";
	os << "           `@%:.  :;%.         ;@@%;'   \n";
	os << "             `@%.  `;@%.      ;@@%;         \n";
	os << "               `@%%. `@%%    ;@@%;        \n";
	os << "                 ;@%. :@%%  %@@%;       \n";
	os << "                   %@bd%%%bd%%:;     \n";
	os << "                     #@%%%%%:;;\n";
	os << "                     %@@%%%::;\n";
	os << "                     %@@@%(o);  . '         \n";
	os << "                     %@@@o%;:(.,'         \n";
	os << "                 `.. %@@@o%::;         \n";
	os << "                    `)@@@o%::;         \n";
	os << "                     %@@(o)::;        \n";
	os << "                    .%@@@@%::;         \n";
	os << "                    ;%@@@@%::;.          \n";
	os << "                   ;%@@@@%%:;;;. \n";
	os << "               ...;%@@@@@%%:;;;;,..    \n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Target")
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145,137), target(target)
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
	;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (target);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

const char	*ShrubberyCreationForm::OutputFile::what() const throw()
{
	const char	*ret = "Error:\n\tCould not create output file";
	return (ret);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw (AForm::NotSignedToExecute());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::InvalidGradeToExecute());
	std::string		targetShrubbery = target + "_shrubbery";
	std::ofstream	outputFile(targetShrubbery.c_str());
	if (!outputFile.is_open())
		throw (OutputFile());
	std::cout << "Created a file " << this->getTarget() << " in the working directory" << std::endl;
	print_tree(outputFile);
	outputFile.close();
	std::cout << "File processed successfully! Output file: " << targetShrubbery << std::endl;
}
