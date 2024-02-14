/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:16:52 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/14 00:40:31 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : Arrsize(0)
{
    arr = new T[Arrsize];
}

template<typename T>
Array<T>::Array(size_t n) : Arrsize(n)
{
    arr = new T[Arrsize];
}

template<typename T>
Array<T>::Array(const Array<T> &copy): Arrsize(copy.Arrsize)
{
    arr = new T[Arrsize];
    for(size_t i = 0; i <= Arrsize ; i++)
        this->arr[i] = copy.arr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy)
{ 
    if(this != &copy)
    {
        delete [] arr;
        arr = new T[copy.Arrsize];
        this->Arrsize = copy.Arrsize;
        for(size_t i = 0; i <= Arrsize ; i++)
            this->arr[i] = copy.arr[i];
    }
    return *this;
}

template<typename T>
Array<T>::~Array( )
{
    delete [] arr;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
    if(index < 0 || index > Arrsize)
        throw std::out_of_range("out of bounds");
    return arr[index];
}

template<typename T>
size_t Array<T>::size()
{
    return(Arrsize);
}
