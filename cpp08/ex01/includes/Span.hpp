/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:39:51 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/18 19:40:58 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>

class Span
{
    private:
        size_t N;
        std::vector<int> container;
    public:
        Span(size_t N);
        Span(const Span &copy);
        int shortestSpan();
        int longestSpan();
        Span& operator=(const Span &copy);
        void addNumber(size_t number);
        void addMany(size_t number);
        ~Span();
};

#endif