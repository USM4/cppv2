/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:57:58 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/14 15:40:23 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
        if(ac == 2)
            ScalarConverter::convert(av[1]);
        else
            std::cerr<< "Just one number required to this program" << std::endl;
    
}