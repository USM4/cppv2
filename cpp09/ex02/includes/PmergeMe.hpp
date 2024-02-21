/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:40:37 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/20 22:19:46 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


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

class PmergeMe
{
    private:
        int malongo;
        std::vector<int> container;
    public:
        PmergeMe();
        void addToContainer(std::string str);
        void mainFunc(std::string str);
        void print_container();
        ~PmergeMe();
};


#endif