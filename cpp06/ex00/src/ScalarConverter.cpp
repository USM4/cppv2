/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:50:14 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/12 18:09:54 by oredoine         ###   ########.fr       */
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

void printDouble(double doubleValue, int num)
{
    if(!static_cast<double>(num - doubleValue))
        std::cout<< "double: " << doubleValue << ".0" << std::endl;
    else
        std::cout<< "double: " << doubleValue << std::endl;
}

void printFloat(float floatValue, int intValue)
{
    if(!static_cast<float>(intValue - floatValue))
        std::cout<< "float: " << floatValue << ".0f" << std::endl;
    else
        std::cout<< "float: " << floatValue << "f" << std::endl;
}

void convert_printInt(long double num)
{
    float floatValue = static_cast<float>(num);
    double doubleValue = static_cast<double>(num);
    char charValue = static_cast<char>(num);
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
    {
        std::cerr<< "int : Casting would result in overflow or underflow" << std::endl;
        printChar(charValue);
        std::cout<< "float: " << floatValue << ".0f" << std::endl;
        std::cout<< "Double: " << doubleValue << ".0"<< std::endl;
    }
    else
    {        
        printChar(charValue);
        std::cout<< "int: " << num << std::endl;
        std::cout<< "float: " << floatValue << ".0f" << std::endl;
        std::cout<< "Double: " << doubleValue << ".0"<< std::endl;
    }
}


void convert_printFloat(float num)
{
    if (num >= std::numeric_limits<float>::max() && num <= std::numeric_limits<float>::min())
    {
        std::cerr<< "Casting would result in overflow or underflow" << std::endl;
        return ;
    }
    int intValue = static_cast<int>(num);
    double doubleValue = static_cast<double>(num);
    char charValue = static_cast<char>(num);

    printChar(charValue);
    std::cout<< "int: " << intValue << std::endl;
    printFloat(num, intValue);
    printDouble(doubleValue, intValue);
}
void convert_printDouble(double num)
{
    if (num >= std::numeric_limits<double>::max() && num <= std::numeric_limits<double>::min())
    {
        std::cerr<< "Casting would result in overflow or underflow" << std::endl;
        return ;         
    }
    float floatValue = static_cast<float>(num);
    int intValue = static_cast<int>(num);
    char charValue = static_cast<char>(num);
    printChar(charValue);
    std::cout<< "int: " << intValue << std::endl;
    printFloat(floatValue, intValue);
    printDouble(num, intValue);

}

void convert_printChar(char num)
{
    float floatValue = static_cast<float>(num);
    int intValue = static_cast<int>(num);
    double DoubleValue = static_cast<double>(num);
    printChar(num);
    std::cout<< "int :"<< intValue << std::endl;
    printFloat(floatValue, intValue);
    printDouble(DoubleValue, intValue);
}

void  ScalarConverter::convert(std::string number)
{
    std::stringstream s(number);
    long double a;
    s >> a;
    if(!check_is_integer(number))
        convert_printInt(a);
    else if(!check_is_float(number))
        convert_printFloat(std::atof(number.c_str()));
    else if(!check_is_double(number))
        convert_printDouble( std::atof(number.c_str()));
    else if(!check_is_char(number))
        convert_printChar(number[0]);
    else if(number == "-inf" || number == "+inf" ||  number == "nan")
    {
        std::cout<<"char: "<<"impossible"<< std::endl;
        std::cout<< "int: " << "impossible" << std::endl;
        std::cout<< "float: " << "nanf" << std::endl;
        std::cout<< "double: " << "nan" << std::endl;
    }
    else if (number == "-inff" || number == "+inff" || number == "nanf")
    {
        std::cout<<"char: "<<"impossible"<< std::endl;
        std::cout<< "int: " << "impossible" << std::endl;
        std::cout<< "float: " << "nanf" << std::endl;
        std::cout<< "double: " << "nan" << std::endl;
    }
    else
        std::cout << "Data type not recognized" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    
}