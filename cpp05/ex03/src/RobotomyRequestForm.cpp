/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:16:32 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/07 19:09:22 by oredoine         ###   ########.fr       */
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
std::string RobotomyRequestForm::getTarget()
{
    return target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!getSign() || (executor.getGrade() > getExec()))
            throw AForm::FailedtoExec();
    else
    {
        std::cout << "driiiiiilling noooooooises !!!!!!!!"<< std::endl;
        std::string messages[] = {
        " has been robotomized successfully ",
        " Robotomy failed!"};
		srand(static_cast<unsigned int>(time(0)));
		unsigned int r = rand();
        // std::cout << r << std::endl;
        if(r % 2 == 0)
            std::cout<< target << messages[0] << std::endl;
        else
            std::cout<< messages[1] << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}