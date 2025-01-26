/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:56:30 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/14 00:31:09 by oredoine         ###   ########.fr       */
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
        size_t Arrsize;
    public:
        Array();
        Array(size_t n);
        Array& operator=(const Array& copy);
        Array(const Array<T>& copy);
        T& operator[](size_t index);
        size_t size();
        ~Array();
};


#include "Array.tpp"
#endif