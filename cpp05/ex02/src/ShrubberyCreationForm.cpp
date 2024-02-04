/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:22:56 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/04 18:57:43 by oredoine         ###   ########.fr       */
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

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    std::cout<< executor.getName() << "executed suxis" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
