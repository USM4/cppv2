/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:28:49 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/12 04:50:23 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template<typename T, typename Function>
void iter(T *arr, int len, Function f)
{
    int i = 0;
    while(i < len)
        f(arr[i++]);
}

#endif