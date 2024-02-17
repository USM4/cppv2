/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:40:19 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/17 19:31:56 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack();
        MutantStack(const MutantStack<T> &copy);
        MutantStack<T>& operator=(const MutantStack<T> &copy);
        iterator begin();
        iterator end();
        ~MutantStack();
};

#include"MutantStack.tpp"
#endif