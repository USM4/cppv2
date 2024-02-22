/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:59:44 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/22 14:49:41 by oredoine         ###   ########.fr       */
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
    private: 
        int result;
    public:
        RPN();
        RPN(const RPN &copy);
        RPN& operator=(const RPN &copy);
        ~RPN();
        void ReversePolishNotation(std::string str);
        int getResult();
};



#endif