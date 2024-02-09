/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:50:14 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/10 00:48:06 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int check_is_integer(std::string num)
{
    size_t i = 0;
    if(num[i] == '-' || num[i] == '+')
        i++;
    for(; i < num.length(); i++)
        if(!std::isdigit(num[i]))
            return(1);
    return(0);
}

int check_is_char(std::string num)
{
    if(!(std::isalpha(num[0]) ) || num.length() != 1)
            return 1;
    return(0);
}

int check_is_float(std::string num)
{
    size_t index = 0;
    int     count_dots = 0;
    int     f = 0;

    if(num[index] == '-' || num[index] == '+')
        index++;
    while(index < num.length() )
    {
        if (num[index] == 'f')
            f++;
        else if(num[index] == '.')
            count_dots++;
        else if (!std::isdigit(num[index]))
            return 1;
        index++;
    }
    if(f != 1 || count_dots != 1 || num[num.length() - 1] != 'f')
        return 1;
    return 0;
}

int check_is_double(std::string num)
{
    size_t index = 0;
    int     count_dots = 0;

    if(num[index] == '-' || num[index] == '+')
        index++;
    while(index < num.length() )
    {
        if(num[index] == '.')
            count_dots++;
        else if (!std::isdigit(num[index]))
            return 1;
        index++;
    }
    if(count_dots != 1 || !std::isdigit(num[num.length() - 1]))
        return 1;
    return 0;
}




void  ScalarConverter::convert(std::string number)
{
    if(!check_is_integer(number))
        printf("HADA INTEGER\n");
    if(!check_is_char(number))
        printf("HADA char\n");
    if(!check_is_float(number))
        printf("HADA float\n");
    else if(!check_is_double(number))
        printf("HADA double\n");
        
}


ScalarConverter::~ScalarConverter()
{
    
}