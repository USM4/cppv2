/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:25:08 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/02 17:42:10 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A;
        Bureaucrat bureacrat(A);
        bureacrat.increment_grade();
        bureacrat.decrement_grade();
        bureacrat.increment_grade();
        std::cout << bureacrat;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}