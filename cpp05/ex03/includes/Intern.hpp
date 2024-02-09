/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:06:47 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/07 16:43:37 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
    public:
        Intern();
        Intern(Intern &copy);
        Intern& operator=(const Intern &copy);
        AForm* makeForm(std::string form, std::string target);
        class FormDoesntExist : public std::exception
        {
            public:
                const char* what() const throw();
        };
        ~Intern();
};



#endif