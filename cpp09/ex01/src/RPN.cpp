/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:18:50 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/20 05:16:22 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    result = 0;
}

RPN::~RPN()
{
}


bool isOperator(char c)
{
    return (c == '-' || c == '+' || c == '*' || c == '/');
}


void RPN::ReversePolishNotation(std::string str)
{
    
    std::stack<int> st;

    for (size_t i = 0; i < str.length(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            st.push(str[i] - 48);
        }
        else if (isOperator(str[i]))
        {
            if (st.size() < 2)
                throw std::runtime_error("Invalid expressions given");
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (str[i] == '+')
                st.push(a + b);
            else if (str[i] == '-')
                st.push(a - b);
            else if (str[i] == '*')
                st.push(a * b);
            else
            {
                if(b == 0)
                    throw std::runtime_error("Can't divide by zero");
                st.push(a / b);
            }
        }
        else if (str[i] == ' ')
            continue ;
        else
            throw std::runtime_error("Invalid character in the expression");
    }
    if (st.size() != 1)
        throw std::runtime_error("Invalid expressions given");

    this->result = st.top();
}

int RPN::getResult()
{
    return this->result;
}
