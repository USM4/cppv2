/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:16:32 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/04 18:58:08 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    target = "home";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy)
{
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
        this->target = copy.target;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}