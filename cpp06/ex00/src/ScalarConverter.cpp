/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:50:14 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/14 19:32:56 by oredoine         ###   ########.fr       */
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
    if(count_dots != 1)
        return 1;
    return 0;
}

int IsHadot(std::string str)
{
    for(size_t i = 0; i <= str.length() ; i++)
    {
        if(str[i] == '.')
            return 1;
    }
    return 0;
}

void printChar(char charValue)
{
    if(charValue < 32 || charValue > 126)
        std::cout<< "char: " << "Non displayable" << std::endl;
    else
        std::cout<< "char: " << charValue << std::endl;
}

void convert_printInt(long double num)
{
    int a;
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
    {
        std::cout<< "int : impossible casting would result in overflow or underflow" << std::endl;
    }
    else
    {
       a = static_cast<int>(num);
        std::cerr<< "int : " << a <<  std::endl;
    }
}


void convert_printFloat(long double num)
{
    double a;
    if (num > MAXFLOAT)
    {
        std::cout<< "float : impossible casting would result in overflow or underflow" << std::endl;
        return ;
    }
    else 
    { 
        a = static_cast<float>(num);
        std::cout<< std::fixed << "float : " << std::setprecision(2) << a << "f" << std::endl;
    }
}

void convert_printDouble(long double num)
{
    double a;
    if (num > std::numeric_limits<double>::max())
            std::cerr<< "double : impossible casting would result in overflow or underflow" << std::endl;
    else
    {
        a = static_cast<double>(num);
        std::cout<< std::fixed <<"double :" << std::setprecision(2) << a  << std::endl;
    }
}

void convert_printChar(char num)
{
    float floatValue = static_cast<float>(num);
    int intValue = static_cast<int>(num);
    double DoubleValue = static_cast<double>(num);
    printChar(num);
    std::cout<< "int :"<< intValue << std::endl;
    std::cout<< std::fixed << "float : " << std::setprecision(2) << floatValue << "f" << std::endl;
    std::cout<< std::fixed <<"double :" << std::setprecision(2) << DoubleValue  << std::endl;
}

void  ScalarConverter::convert(std::string number)
{
    long double a;
    std::string tmp;
    if(number.empty())
    {   
        std::cout<< "Empty argument" << std::endl;
        return ;
    }
    if (number[number.size() -1] == 'f')
        tmp = number.substr(0, number.size() - 1);
    else
        tmp = number;
    std::stringstream s(tmp);
    s >> a;
    if(!check_is_char(number))
        convert_printChar(number[0]);
    else if (!check_is_integer(number) || !check_is_float(number) || !check_is_double(number))
    {
        printChar(a);
        convert_printInt(a);
        convert_printFloat(a);
        convert_printDouble(a);
    } 
    else if(number == "nan" || number == "nanf")
    {
        std::cout<<"char: "<<"impossible"<< std::endl;
        std::cout<< "int: " << "impossible" << std::endl;
        std::cout<< "float: " << "nanf" << std::endl;
        std::cout<< "double: " << "nan" << std::endl;
    }
    else if(number == "-inf" || number == "-inff")
    {
        std::cout<<"char: "<<"impossible"<< std::endl;
        std::cout<< "int: " << "impossible" << std::endl;
        std::cout<< "float: " << "-inff" << std::endl;
        std::cout<< "double: " << "-inf" << std::endl;
    }
    else if (number == "+inf" || number == "+inff")
    {
        std::cout<<"char: "<<"impossible"<< std::endl;
        std::cout<< "int: " << "impossible" << std::endl;
        std::cout<< "float: " << "+inff" << std::endl;
        std::cout<< "double: " << "+inf" << std::endl;
    }
    else
        std::cout << "Data type not recognized" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    
}