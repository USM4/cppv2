/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:08:37 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/07 20:05:25 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Intern.hpp"

Intern::Intern()
{
    
}

Intern::Intern(Intern &copy)
{
    *this = copy;
}

Intern& Intern::operator=(const Intern &copy)
{
    (void) copy;
    return *this;
}

const char* Intern::FormDoesntExist::what() const throw()
{
    return("Form doesn't exist");
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    int i;
    for (i = 0 ; i < 3; i++)
        if (form == forms[i])
            break ;
    AForm *formto_execute = NULL;
    // printf("i = %d\n", i);
    switch (i)
    {
        case 0:
            formto_execute = new ShrubberyCreationForm(target);
            std::cout<< "Intern creates " << form<< std::endl;
            break;
        case 1:
            formto_execute = new PresidentialPardonForm(target);
            std::cout<< "Intern creates " << form<< std::endl;
            break;
        case 2:
            formto_execute = new RobotomyRequestForm(target);
            std::cout<< "Intern creates " << form<< std::endl;
            break;
        default:
            throw FormDoesntExist();
    }

    return (formto_execute);
}

Intern::~Intern()
{
    
}