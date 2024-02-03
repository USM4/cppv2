/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:25:08 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/03 01:17:17 by oredoine         ###   ########.fr       */
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
        bureaucrat = new Bureaucrat("oussama", 4);
        form = new Form("redoine", 2);
        bureaucrat->increment_grade();
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
    bureaucrat->signForm(*form);
    delete bureaucrat;
    delete form;
}