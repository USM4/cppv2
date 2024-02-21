/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:40:37 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/22 00:57:15 by oredoine         ###   ########.fr       */
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
#include <deque>

class PmergeMe
{
    private:
        int malongo;
        // int malongo_deque;
        std::vector<int> container;
        std::deque<int> deque;
        std::vector<std::pair<int, int> > pairs;
        std::deque<std::pair<int, int> > pairs_deque;
    public:
        PmergeMe();
        void addToContainer(std::string str);
        void fillContainer(std::string str);
        void vector_algo();
        bool checkIsDigit(std::string str);
        void indexingSub(std::vector<std::pair<int, int> >& sub_indexing, std::vector<int> subvec);
        void generateJacobs(std::vector<int>& jacob, int subsize);
        void print_container();
        int getLast();
        void print_pairs();
        void get_last_comb(std::vector<int> &last_comb, std::vector<int> jacob, size_t subsize);
        // void addToContainer_deque(std::string str);
        // void fillContainer_deque(std::string str);
        // void vector_algo_deque();
        // bool checkIsDigit_deque(std::string str);
        // void indexingSub_deque(std::vector<std::pair<int, int> >& sub_indexing, std::vector<int> subvec);
        // void generateJacobs_deque(std::vector<int>& jacob, int subsize);
        // void print_container_deque();
        // int getLast_deque();
        // void print_pairs_deque();
        // void get_last_comb_deque(std::vector<int> &last_comb, std::vector<int> jacob, size_t subsize);
        ~PmergeMe();
};


#endif