/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:05:50 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/15 04:27:02 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

Span::Span(size_t N) : N(N)
{
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span& Span::operator=(const Span &copy)
{
    if(this != &copy)
        this->N =copy.N;
    return(*this);
}

void Span::addNumber(size_t number)
{
    if(this->container.size() < N)
        this->container.push_back(number);
    else    
        throw std::exception();
}

void Span::shortestSpan()
{
    
}

int Span::longestSpan()
{
    std::vector<int> sorted = container;
    if (sorted.size() < 2)
        throw std::exception();
    std::sort(sorted.begin(), sorted.end());
    return(sorted.back() - sorted.front());
}

Span::~Span()
{
}