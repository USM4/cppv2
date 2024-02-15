/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:48:12 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/15 04:30:18 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
    try
    {
        Span span(10000);
        for (size_t i = 0; i < 10000; i++)
            span.addNumber(i);
        if(span.longestSpan())
            std::cout<< "longest :" << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Something went wrong" << std::endl;
    }
    
}