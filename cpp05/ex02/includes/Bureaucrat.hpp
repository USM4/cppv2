/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:27:37 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/04 18:56:36 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
class AForm;
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string           name;
        int                         grade;
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        int getGrade() const;
        std::string getName()const;
        void increment_grade();
        void decrement_grade();
        void signForm(AForm& obj);
        ~Bureaucrat();
};

extern std::ostream& operator<<(std::ostream& os, Bureaucrat const *objref);

#endif
