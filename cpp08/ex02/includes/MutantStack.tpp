/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:49:04 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/17 19:48:57 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy)
{
    *this = copy;
}

template <typename T>
MutantStack<T>&  MutantStack<T>::operator=(const MutantStack<T> &copy)
{
    (void)copy;
    return(*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return  this->c.end();
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}