/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:05:50 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/16 03:16:50 by oredoine         ###   ########.fr       */
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
    {
        this->N =copy.N;
        this->container = copy.container;
    }
    return(*this);
}

void Span::addNumber(size_t number)
{
    if(this->container.size() < N)
        this->container.push_back(number);
    else
        throw std::exception();
}

int Span::shortestSpan()
{
    std::vector<int> sorted = container;
    int shortestsp;
    if (sorted.size() < 2)
        throw std::exception();
    int min = std::abs(sorted[1] - sorted[0]);
    for (size_t i = 0; i < sorted.size(); i++)
    {
        shortestsp = std::abs(sorted[i] - sorted[i - 1]);
        shortestsp = std::min(shortestsp, min);
    }
    return shortestsp;
}

void Span::addMany(size_t number)
{
    for (size_t i = 0; i < number; i++)
        addNumber(i);
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