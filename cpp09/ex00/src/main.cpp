/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:28:44 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/19 18:25:48 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if(ac != 2)
        {
            std::cerr<< "Wrong Number of arguments"<< std::endl;
            return 1;
        }
        BitcoinExchange obj;
        obj.fillDatabase();
        obj.bitcoin(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}