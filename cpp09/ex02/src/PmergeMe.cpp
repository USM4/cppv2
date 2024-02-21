/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:37:29 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/21 01:25:48 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
    this->malongo = 0;
}

bool checkIsDigit(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        // if(str[i] == ' ')
        //     continue ;
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::addToContainer(std::string str)
{
    std::stringstream stream(str);
    double a;
    stream >> a;
    if(a < 0)
        throw std::runtime_error("Error : Program cannot take a negative number");
    else if (a > std::numeric_limits<int>::max())
        throw std::runtime_error ("Error : Program cannot take a large number");
    else
        this->container.push_back(a);
}

void PmergeMe::mainFunc(std::string str)
{
    if (!checkIsDigit(str))
        throw std::runtime_error("Error : Invalid input , not a digit");
    else
        addToContainer(str);
}

void PmergeMe::print_container()
{
    std::vector<int>::iterator it = this->container.begin();
    for (; it != container.end(); ++it)
        std::cout << *it << " ";
}

PmergeMe::~PmergeMe()
{
}