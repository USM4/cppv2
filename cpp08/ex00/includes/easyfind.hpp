/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:06:47 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/14 17:38:40 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

#include "easyfind.tpp"

template<typename T>
int easyfind(T container, int num)
{
    for(size_t i; i < container.length(); i++)
        if(container[i] == num)
            return i;
        else
            throw "Not Found";
    return 0; 
}


#endif