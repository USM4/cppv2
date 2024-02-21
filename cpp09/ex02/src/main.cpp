/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:35:12 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/20 22:20:08 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac , char **av)
{
    try
    {
        if (ac < 2)
        {
            std::cerr<< "Invalid number of arguments ."<< std::endl;
            return(1);
        }
        PmergeMe obj;
        for (int i = 1; i < ac; ++i)
            obj.mainFunc(av[i]);
        obj.print_container();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}