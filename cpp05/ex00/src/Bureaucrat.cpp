/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:38:41 by oredoine          #+#    #+#             */
/*   Updated: 2024/01/22 22:40:33 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) , grade(grade)
{
}
Bureaucrat::Bureaucrat()
{
}
Bureaucrat::Bureaucrat(Bureaucrat &copy)
{
    *this = copy;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        // this->name = copy.name;
        this->grade = copy.grade;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
}