/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:21:04 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/06 17:01:46 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm &copy);
        std::string getTarget() const;
        
        class NotOpenned : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};



#endif