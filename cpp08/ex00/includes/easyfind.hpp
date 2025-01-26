/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:06:47 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/15 01:35:15 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>  
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>

template<typename T>
int easyfind(T container, int num)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), num);
        if (iter != container.end())
            return (1);
        else
            throw std::exception();
}

#endif