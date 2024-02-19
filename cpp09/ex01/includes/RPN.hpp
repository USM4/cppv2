/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:59:44 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/19 19:20:24 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <stack>
#include <map>
#include <exception>
#include <limits>

class RPN
{
    public:
        RPN();
        ~RPN();
        void ReversePolishNotation(std::string str);
};



#endif