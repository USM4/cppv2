/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:56:30 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/13 02:02:55 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>
#include<exception>

template<typename T>

class Array
{
    private:
        T* arr;
        unsigned int Arrsize;
    public:
        Array( );
        Array(unsigned int n);
        Array& operator=(const Array& copy);
        Array(Array<T&> copy);
        T& operator[](unsigned int index);
        ~Array();
};

#endif