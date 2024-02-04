/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:25:08 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/05 00:09:32 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    Bureaucrat *bureaucrat = NULL;
    AForm      *form = NULL;

    try
    {
        bureaucrat  = new Bureaucrat("USM4 ", 26);
        form = new PresidentialPardonForm("cluster ");
        // form = new ShrubberyCreationForm("cluster ");
        form->execute(*bureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    delete bureaucrat;
    // delete form;
}