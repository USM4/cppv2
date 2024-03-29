/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:28:49 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/13 18:59:35 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template<typename T, typename Function>
void iter(T *arr, size_t len, Function f)
{
    size_t i = 0;
    while (i < len)
        f(arr[i++]);
}

#endif