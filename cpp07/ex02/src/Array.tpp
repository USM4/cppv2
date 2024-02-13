/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:16:52 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/13 01:58:30 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array() : Arrsize(0), arr(NULL)
{
}

Array::Array(unsigned int n) : Arrsize(n)
{
    arr = new T[Arrsize];
}

Array::Array(const Array &copy): Arrsize(copy->Arrsize)
{
    arr = new T[Arrsize];
    for(int i = 0; i <= Arrsize ; i++)
        this->arr[i] = copy->arr[i];
}

Array& Array::operator=(const Array& copy)
{ 
    if(this != &copy)
    {
        delete [] arr;
        this->Arrsize = copy->Arrsize;
        for(unsigned int i = 0; i <= Arrsize ; i++)
            this->arr[i] = copy->arr[i];
    }
    return *this;
}

Array::Array( )
{
        delete [] arr;
}

T& Array::operator[](const int index)
{
    if(index < Arrsize || index > Arrsize)
        throw std::out_of_range("out of bounds");
    return arr[index];
}