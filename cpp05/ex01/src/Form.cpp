/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:06:37 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/03 01:16:49 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("DefName"), grade(12)
{
    sign = false;
    flag = 0;
}

Form::Form(std::string name, int grade): name(name), grade(grade)
{
    sign = false;
    flag = 0;
}

Form::Form(Form &copy) : name("CopName"), sign(false),grade(15), flag(0)
{
    *this  = copy;
}

Form& Form::operator=(const Form &copy)
{
    if(this != &copy)
    {
        this->sign = copy.sign;
        this->flag = copy.flag;
    }
    return(*this);
}

int Form::grade_bounds() const
{
    if (grade > 150)
        throw GradeTooLowException();
    else if(grade < 1)
        throw GradeTooHighException();
    return(grade);
}

std::string Form::getName() const
{
    return this->name;
}

int Form::getGrade() const
{
    return this->grade;    
}

bool Form::getSign() const
{
    return this->sign;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("too High grade in the form");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("too Low grade in the form");
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > grade)
    {
        flag = 1;
        throw GradeTooLowException();
    }
    else if((bureaucrat.getGrade() <= grade) && grade_bounds())
    {
        puts("dkhli");
        sign = true;
    }
}

std::string Form::getReason()
{
    if(flag)
        return("Grade was too low");
    return("Grade not between the bounds");
}

std::ostream& operator<<(std::ostream& os, Form const *objref)
{
    os << "Form : "<< objref->getName() << " , " << " Form Grade : "<< objref->getGrade()<< " Sign : " << objref->getSign() << std::endl;
    return os;
}

Form::~Form()
{
}