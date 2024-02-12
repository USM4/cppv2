/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:04:46 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/12 02:26:00 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename X>
X max(X x, X y)
{
    return (x > y ? x : y);
}

template <typename X>
X min(X x, X y)
{
    return (x < y ? x : y);
}

template <typename X>
void    swap(X& x , X& y)
{
    X tmp = x;
    x = y;
    y = tmp;
}

#endif

