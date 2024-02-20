/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:10:07 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/20 04:50:22 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

int main(int ac,char **av)
{
    try
    {
        if(ac != 2)
        {
            std::cerr<<"Wrong number of arguments ."<< std::endl;
            return 1;
        }
        RPN s;
        s.ReversePolishNotation(av[1]);
        std::cout << "Result : " << s.getResult()<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}