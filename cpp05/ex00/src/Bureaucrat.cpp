/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:38:41 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/01 21:17:23 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name , int grade) : name(name) , grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
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

void Bureaucrat::decrement_grade()
{
    if(grade + 1 > 150)
        return ;
    grade++;
}

void Bureaucrat::increment_grade()
{
    if(grade - 1 < 1)
        return ;
    grade++;
}

char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("to High grade");
}

const char* Bureaucrat::GradeTooHighException::what const throw()
{
    return("to Low grade");
}

Bureaucrat::~Bureaucrat()
{
}