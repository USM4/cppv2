/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:06:37 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/08 15:21:41 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("DefName"), grade(12), exec(1)
{
    grade_bounds();
    sign = false;
}

Form::Form(std::string name, int grade, int exec): name(name), grade(grade), exec(exec) 
{
    grade_bounds();
    sign = false;
}

Form::Form(Form &copy) : name("CopName"), sign(false),grade(15), exec(1)
{
    *this  = copy;
}

Form& Form::operator=(const Form &copy)
{
    if(this != &copy)
        this->sign = copy.sign;
    return(*this);
}

void Form::grade_bounds()
{
    if (grade > 150)
        throw GradeTooLowException();
    else if(grade < 1)
        throw GradeTooHighException();
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

int Form::getExec() const
{
    return(this->exec);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("too High grade in the form");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("too Low grade in the form");
}

bool    Form::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > grade)
        throw GradeTooLowException();
    else if(bureaucrat.getGrade() <= grade)
        sign = true;
    return sign;
}


std::ostream& operator<<(std::ostream& os, Form const *objref)
{
    os << "Form : "<< objref->getName() << " , " << " Form Grade : "<< objref->getGrade()<< " Sign : " << objref->getSign() << std::endl;
    return os;
}

Form::~Form()
{
}