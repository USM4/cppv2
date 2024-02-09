/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:25:08 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/08 15:33:11 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
    Bureaucrat *bureaucrat = NULL;
    Bureaucrat *bureaucrat2 = NULL;
    Bureaucrat *bureaucrat3 = NULL;
    AForm      *form = NULL;
    AForm      *form2 = NULL;
    AForm      *form3 = NULL;

    try
    {
        bureaucrat  = new Bureaucrat("USM4 ", 1);
        form = new ShrubberyCreationForm("form");
        form->beSigned(*bureaucrat);
        form->execute(*bureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        bureaucrat2  = new Bureaucrat("USM4 ", 1);
        form2 = new RobotomyRequestForm("Robot");
        form2->beSigned(*bureaucrat2);
        form2->execute(*bureaucrat2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        bureaucrat3  = new Bureaucrat("USM4 ", 1);
        form3 = new PresidentialPardonForm("Pardon");
        form3->beSigned(*bureaucrat3);
        form3->execute(*bureaucrat3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    
    delete bureaucrat;
    delete bureaucrat2;
    delete bureaucrat3;
    delete form;
    delete form2;
    delete form3;
}