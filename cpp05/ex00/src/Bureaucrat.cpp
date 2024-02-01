/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:38:41 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/01 13:58:16 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

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
        this->grade = copy.grade;
    return(*this);
}

std::string Bureaucrat::getName()
{
    return(name);
}

int Bureaucrat::getGrade()
{
    return(grade);
}

Bureaucrat::~Bureaucrat()
{
}