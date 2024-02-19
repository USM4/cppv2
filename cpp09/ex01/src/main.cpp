/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:10:07 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/19 22:09:51 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

int main(int ac,char **av)
{
    if(ac != 2)
    {
        std::cerr<<"Wrong number of arguments ."<< std::endl;
        return 1;
    }
    ReversePolishNotation(av[1]);
}