
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

#include "Intern.hpp"

int main()
{
    AForm      *form = NULL;
    AForm      *form1 = NULL;
    AForm      *form2 = NULL;
    Bureaucrat *bureaucrat = NULL;

    try
    {
        Intern someRandomIntern;
        bureaucrat  = new Bureaucrat("USM4 ",1);
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        form1 = someRandomIntern.makeForm("presidential pardon", "Tom");
        form2 = someRandomIntern.makeForm("shrubbery creation", "flen");
        form->beSigned(*bureaucrat);
        form->execute(*bureaucrat);
        form1->beSigned(*bureaucrat);
        form1->execute(*bureaucrat);
        form2->beSigned(*bureaucrat);
        form2->execute(*bureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete bureaucrat;
    delete form;
    delete form1;
    delete form2;
}