/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:48:12 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/16 00:53:14 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
    try
    {
        // Span span(10000);
        //     span.addMany(1000100);
        // if(span.longestSpan())
        //     std::cout<< "longest :" << span.longestSpan() << std::endl;
        // if(span.shortestSpan())
        //     std::cout<< "shortest :" << span.shortestSpan() << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(-17);
        sp.addNumber(9);
        sp.addNumber(9);
        sp.addNumber(9);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Something went wrong" << std::endl;
    }
    
}