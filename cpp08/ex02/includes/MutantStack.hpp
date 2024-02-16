/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:40:19 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/16 03:29:13 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
};

#endif