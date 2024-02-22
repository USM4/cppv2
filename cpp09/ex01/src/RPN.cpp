/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:18:50 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/22 14:51:44 by oredoine         ###   ########.fr       */
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

bool isOperator(std::string c)
{
    if (c != "+" && c != "-" && c != "/" && c != "*")
        return (false);
    return (true);
}

int    CheckIsValidNumber(std::string &str)
{
    std::stringstream ss(str);
    int num;
    ss >> num;
    if(ss.fail() || !ss.eof())
        throw std::runtime_error("Error: bad input or overflow");
    else if (num >= 10)
        throw std::runtime_error("Error: bad input should less than 10");
    return (num);
}


RPN::RPN(const RPN &copy)
{
    *this = copy;    
}

RPN& RPN::operator=(const RPN &copy)
{
    this->result = copy.result;
    return *this;
}

void RPN::ReversePolishNotation(std::string str)
{
    
    std::stack<int> st;
    for (size_t i = 0; i < str.length(); i++)
    {
        std::string operands = "+-/* ";
        
        if(operands.find(str[i]) == std::string::npos && !isdigit(str[i]))
            throw std::runtime_error("Invalid input");
            
    }
    std::stringstream stream(str);
    std::string input;
    
    while (stream >> input)
    {
        if (!isOperator(input))
            st.push(CheckIsValidNumber(input));
        else
        {
            if (st.size() < 2)
                throw std::runtime_error("Invalid expressions given");
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (input == "+")
                st.push(a + b);
            else if (input == "-")
                st.push(a - b);
            else if (input == "*")
                st.push(a * b);
            else
            {
                if(b == 0)
                    throw std::runtime_error("Can't divide by zero");
                st.push(a / b);
            }
        }
    }
    if (st.size() != 1)
        throw std::runtime_error("Invalid expressions given");
    this->result = st.top();
}

int RPN::getResult()
{
    return this->result;
}
