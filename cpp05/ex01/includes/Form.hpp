/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:05:20 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/05 16:44:42 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
    private:
        const       std::string name;
        bool        sign;
        const int   grade;
        const int   exec;
    public:
        Form();
        Form(std::string name, int grade, int exec);
        Form(Form &copy);
        std::string getName() const;
        int         getGrade() const;
        bool        getSign() const;
        int         getExec() const;
        void        grade_bounds();
        Form& operator=(const Form &copy);
        ~Form();
        class GradeTooHighException : public  std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public  std::exception
        {
            public:
                const char* what() const throw();
        };
        bool        beSigned(Bureaucrat& bureaucrat);
};

extern std::ostream& operator<<(std::ostream& os, Form const *objref);

#endif