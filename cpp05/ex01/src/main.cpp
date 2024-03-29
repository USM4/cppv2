/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:25:08 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/08 15:23:15 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat *bureaucrat = NULL;
    Form *form = NULL;
    try
    {
        bureaucrat = new Bureaucrat("USM4", 15);
        form = new Form("the form", 14, 20);
        bureaucrat->increment_grade();
        bureaucrat->increment_grade();
        // bureaucrat->increment_grade();
        // bureaucrat->decrement_grade();
        std::cout<< bureaucrat << std::endl;
        form->beSigned(*bureaucrat);
        std::cout<< form << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    if (bureaucrat)
        bureaucrat->signForm(*form);
    delete bureaucrat;
    delete form;
}