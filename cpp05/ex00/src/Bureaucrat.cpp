/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:38:41 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/02 17:47:45 by oredoine         ###   ########.fr       */
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

Bureaucrat::Bureaucrat() : name("DefName") , grade(15)
{
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : name("CopName")
{
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
        this->grade = copy.grade;
    return(*this);
}

std::string Bureaucrat::getName() const
{
    return(name);
}

int Bureaucrat::getGrade() const
{
    return(grade);
}

void Bureaucrat::decrement_grade()
{
    if(grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

void Bureaucrat::increment_grade()
{
    if(grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("too High grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("too Low grade");
}


std::ostream& operator<<(std::ostream& os, Bureaucrat const& objref)
{
    os << objref.getName() << " , bureaucrat grade " << objref.getGrade() << std::endl;
    return os;
}


Bureaucrat::~Bureaucrat()
{
}