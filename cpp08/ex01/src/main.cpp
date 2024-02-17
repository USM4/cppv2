/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:48:12 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/17 20:10:32 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
    try
    {
        Span span(10000);
        span.addNumber(1000);
        span.addNumber(2000);
        span.addNumber(4000);
        span.addNumber(3000);
        // sp.addMany(1000);
        if(span.longestSpan())
            std::cout<< "longest :" << span.longestSpan() << std::endl;
        if(span.shortestSpan())
            std::cout<< "shortest :" << span.shortestSpan() << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Something went wrong" << std::endl;
    }
    
}