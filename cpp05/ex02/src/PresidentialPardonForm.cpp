/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:15:31 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/05 00:13:34 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    target = "home";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy)
{
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &copy)
{
    if(this != &copy)
        this->target = copy.target;
    return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if()
    {
        if(executor.getGrade() > getExec())
            std::cout<< target << " has been pardoned by Zaphod Beeblebrox. "<<std::endl ;
    }
    else
        throw AForm::GradeTooLowException();
}



PresidentialPardonForm::~PresidentialPardonForm()
{
}
