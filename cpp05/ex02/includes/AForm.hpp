/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:05:20 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/05 00:01:13 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const       std::string name;
        bool        sign;
        const int   grade;
        const int   exec;
    public:
        AForm();
        AForm(std::string name, int grade, int exec);
        AForm(AForm &copy);
        std::string getName() const;
        int         getGrade() const;
        bool        getSign() const;
        int         getExec() const;
        void        grade_bounds();
        AForm& operator=(const AForm &copy);
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
        void        beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        ~AForm();
};

extern std::ostream& operator<<(std::ostream& os, AForm const *objref);

#endif