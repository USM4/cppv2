/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:22:56 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/06 22:12:15 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    target = "home";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) , target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy)
{
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy)
{
    if(this != &copy)
        this->target = copy.target;
    return(*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

const char* ShrubberyCreationForm::NotOpenned::what() const throw()
{
    return("Problem in file opening");
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if(!getSign() || (executor.getGrade() > getExec()))
            throw AForm::FailedtoExec();
    else
    {
        std::string extension = "_shrubbery";
        std::ofstream outputFile((getTarget() + extension));
        if(!outputFile.is_open())
            throw NotOpenned();
        outputFile << "        *" << std::endl;
        outputFile << "       ***" << std::endl;
        outputFile << "      *****" << std::endl;
        outputFile << "     *******" << std::endl;
        outputFile << "    *********" << std::endl;
        outputFile << "   ***********" << std::endl;
        outputFile << "  *************" << std::endl;
        outputFile << " ***************" << std::endl;
        outputFile << "        |" << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
