/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:00:27 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/06 16:06:38 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("DefName"), grade(12), exec(1)
{
    grade_bounds();
    sign = false;
}

AForm::AForm(std::string name, int grade, int exec): name(name), grade(grade), exec(exec) 
{
    grade_bounds();
    sign = false;
    
}

AForm::AForm(AForm &copy) : name("CopName"), sign(false),grade(15), exec(1)
{
    *this  = copy;
}

AForm& AForm::operator=(const AForm &copy)
{
    if(this != &copy)
        this->sign = copy.sign;
    return(*this);
}

void AForm::grade_bounds()
{
    if (grade > 150)
        throw GradeTooLowException();
    else if(grade < 1)
        throw GradeTooHighException();
}

std::string AForm::getName() const
{
    return this->name;
}

int AForm::getGrade() const
{
    return this->grade;
}

bool AForm::getSign() const
{
    return this->sign;
}

int AForm::getExec() const
{
    return(this->exec);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("too High grade in the Aform");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("too Low grade in the Aform");
}

bool    AForm::beSigned(Bureaucrat const &  bureaucrat)
{
    if(bureaucrat.getGrade() > grade)
        throw GradeTooLowException();
    else if(bureaucrat.getGrade() <= grade)
        sign = true;
    return(sign);
}

const char* AForm::FailedtoExec::what() const throw()
{
    return("Can't execute the form need to be grader ");
}

std::ostream& operator<<(std::ostream& os, AForm const *objref)
{
    os << "AForm : "<< objref->getName() << " , " << " AForm Grade : "<< objref->getGrade()<< " Sign : " << objref->getSign() << std::endl;
    return os;
}

AForm::~AForm()
{
}