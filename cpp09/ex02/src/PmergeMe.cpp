/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:37:29 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/22 14:38:01 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    this->malongo = copy.malongo;
    this->malongo_deque = copy.malongo_deque;
    this->vector_bef = copy.vector_bef;
    this->vector_aft = copy.vector_aft;
    this->deque_bef = copy.deque_bef;
    this->deque_aft = copy.deque_aft;
    this->container = copy.container;
    this->deque = copy.deque;
    this->pairs = copy.pairs;
    this->pairs_deque = copy.pairs_deque;
    return *this;
}

bool PmergeMe::checkIsDigit(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
            return false;
    return true;
}

void print_container_main(std::vector<int> ct)
{
    std::vector<int>::iterator it = ct.begin();
    for (; it != ct.end(); ++it)
        std::cout << *it << " ";
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

void PmergeMe::fillContainer(std::string str)
{
    if (!checkIsDigit(str))
        throw std::runtime_error("Error : Invalid input , not a digit");
    addToContainer(str);    
}

void PmergeMe::indexingSub(std::vector<std::pair<int, int> >& sub_indexing, std::vector<int> subvec)
{
    for(size_t i = 0; i < subvec.size(); i++)
        sub_indexing.push_back(std::make_pair(i + 1, subvec[i]));
}

void PmergeMe::generateJacobs(std::vector<int>& jacob, int subsize)
{
    int n = 0;
    while(1)
    {
        if (n == 0)
            jacob.push_back(0);
        else if(n == 1)
            jacob.push_back(1);
        else
            jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
        if(jacob[n] >= subsize)
            break ;
        n++;
    }
}


void PmergeMe::get_last_comb(std::vector<int> &last_comb, std::vector<int> jacob, size_t subsize)
{
    size_t delimiter  = jacob[3];
    size_t count2  = 3;
    size_t i = 1;
    while (delimiter < subsize)
    {
        while (i < delimiter)
        {
            last_comb.push_back(delimiter);
            delimiter--;
        }
        i = jacob[count2];
        delimiter = jacob[++count2];
    }
}

void print_bef_nd_aft(std::vector<int> container, std::vector<int> main)
{
    std::vector<int>::iterator iter;
    std::cout << "Before: ";
    for (iter = container.begin(); iter != container.end(); iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;
    std::cout << "After:  ";
    for (iter = main.begin(); iter != main.end(); iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;
}

void PmergeMe::vector_algo()
{
    try
    {
        timeval str;
        gettimeofday(&str, NULL);
        this->vector_bef = str.tv_sec * 1000000LL + str.tv_usec;
        if (this->container.size() < 2)
        {
            std::cout << "more numbers please" << std::endl;
            exit (0);
        }
        size_t i = 0;
        if (container.size() % 2 != 0)
        {
            malongo = container.front();
            i++;
        }
        for(; i < container.size() ; i += 2)
            this->pairs.push_back(std::make_pair(this->container[i], this->container[i + 1]));
        std::vector<std::pair<int, int> >::iterator it = this->pairs.begin();
        for (; it != this->pairs.end(); ++it)
            if(it->second > it->first)
                std::swap(it->first, it->second);
        it = this->pairs.begin();
        for (; it != this->pairs.end(); ++it)
            std::sort(pairs.begin(), pairs.end());
        std::vector<int> main;
        std::vector<int>::iterator iter1;
        std::vector<int>::iterator to_insert;
        std::vector<std::pair<int, int> >::iterator iter2;
        std::vector<int> sub;
        std::vector<int> last_comb;
        std::vector<std::pair<int, int> >::iterator iterate_pairs;
        for(iterate_pairs = this->pairs.begin(); iterate_pairs != this->pairs.end(); iterate_pairs++)
        {
            main.push_back(iterate_pairs->first);
            sub.push_back(iterate_pairs->second);
        }
        main.insert(main.begin(), *(sub.begin()));
        std::vector<std::pair<int, int> > sub_position;
        indexingSub(sub_position, sub);
        std::vector<int> jacob;
        generateJacobs(jacob, this->container.size());
        get_last_comb(last_comb, jacob, this->container.size());
        // print_container_main(last_comb);
        for (iter1 = last_comb.begin() ; iter1 != last_comb.end() ; iter1++)
        {
            for (iter2 = sub_position.begin(); iter2 != sub_position.end(); iter2++)
            {
                if ((*iter2).first == *iter1)
                {
                    to_insert =  std::lower_bound(main.begin(), main.end(), (*iter2).second);
                    main.insert(to_insert, (*iter2).second);
                }
            }
        }
        if (container.size() % 2)
        {
            to_insert =  std::lower_bound(main.begin(), main.end(), malongo);
            main.insert(to_insert, malongo);
        }
        gettimeofday(&str, NULL);
        this->vector_aft = str.tv_sec * 1000000LL + str.tv_usec;
        print_bef_nd_aft(container, main);
    }
    catch(const char *str)
    {
        std::cerr << str << std::endl;
    }
    
}

void PmergeMe::print_pairs()
{
    std::vector<std::pair<int, int> >::iterator it = this->pairs.begin();
    for (; it != this->pairs.end(); ++it)
        std::cout << "(" << it->first << ", " << it->second << ") ";
}

int PmergeMe::getLast()
{
    return malongo;
}

void PmergeMe::print_container()
{
    std::vector<int>::iterator it = this->container.begin();
    for (; it != container.end(); ++it)
        std::cout << *it << " ";
    
}

bool PmergeMe::checkIsDigit_deque(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
            return false;
    return true;
}

void PmergeMe::addToContainer_deque(std::string str)
{
    std::stringstream stream(str);
    double a;
    stream >> a;
    if(a < 0)
        throw std::runtime_error("Error : Program cannot take a negative number");
    else if (a > std::numeric_limits<int>::max())
        throw std::runtime_error ("Error : Program cannot take a large number");
    else
        this->deque.push_back(a);
}

void PmergeMe::fillContainer_deque(std::string str)
{
    if (!checkIsDigit_deque(str))
        throw std::runtime_error("Error : Invalid input , not a digit");
    addToContainer_deque(str);    
}

void PmergeMe::indexingSub_deque(std::deque<std::pair<int, int> >& sub_indexing, std::deque<int> subvec)
{
    for(size_t i = 0; i < subvec.size(); i++)
        sub_indexing.push_back(std::make_pair(i + 1, subvec[i]));
}

void PmergeMe::generateJacobs_deque(std::deque<int>& jacob, int subsize)
{
    int n = 0;
    while(1)
    {
        if (n == 0)
            jacob.push_back(0);
        else if(n == 1)
            jacob.push_back(1);
        else
            jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
        if(jacob[n] >= subsize)
            break ;
        n++;
    }
}


void PmergeMe::get_last_comb_deque(std::deque<int> &last_comb, std::deque<int> jacob, size_t subsize)
{
    size_t delimiter  = jacob[3];
    size_t count2  = 3;
    size_t i = 1;
    while (delimiter < subsize)
    {
        while (i < delimiter)
        {
            last_comb.push_back(delimiter);
            delimiter--;
        }
        i = jacob[count2];
        delimiter = jacob[++count2];
    }
}

void PmergeMe::print_deque_main(std::deque<int> ct)
{
    std::deque<int>::iterator it = ct.begin();
    for (; it != ct.end(); ++it)
        std::cout << *it << " ";
    
}

void PmergeMe::algo_deque()
{
    try
    {
        timeval str;
        gettimeofday(&str, NULL);
        this->deque_bef = str.tv_sec * 1000000LL + str.tv_usec;
        if (this->deque.size() < 2)
            throw "need more elements";
        size_t i = 0;
        if (deque.size() % 2 != 0)
        {
            malongo_deque = deque.front();
            i++;
        }
        for(; i < deque.size() ; i += 2)
            this->pairs_deque.push_back(std::make_pair(this->deque[i], this->deque[i + 1]));
        std::deque<std::pair<int, int> >::iterator it = this->pairs_deque.begin();
        for (; it != this->pairs_deque.end(); ++it)
            if(it->second > it->first)
                std::swap(it->first, it->second);
        it = this->pairs_deque.begin();
        for (; it != this->pairs_deque.end(); ++it)
            std::sort(pairs_deque.begin(), pairs_deque.end());
        std::deque<int> main;
        std::deque<int>::iterator iter1;
        std::deque<int>::iterator to_insert;
        std::deque<std::pair<int, int> >::iterator iter2;
        std::deque<int> sub;
        std::deque<int> last_comb;
        std::deque<std::pair<int, int> >::iterator iterate_pairs;
        for(iterate_pairs = this->pairs_deque.begin(); iterate_pairs != this->pairs_deque.end(); iterate_pairs++)
        {
            main.push_back(iterate_pairs->first);
            sub.push_back(iterate_pairs->second);
        }
        main.insert(main.begin(), *(sub.begin()));
        std::deque<std::pair<int, int> > sub_position;
        indexingSub_deque(sub_position, sub);
        std::deque<int> jacob;
        generateJacobs_deque(jacob, this->deque.size());
        get_last_comb_deque(last_comb, jacob, this->deque.size());

        for (iter1 = last_comb.begin() ; iter1 != last_comb.end() ; iter1++)
        {
            for (iter2 = sub_position.begin(); iter2 != sub_position.end(); iter2++)
            {
                if ((*iter2).first == *iter1)
                {
                    to_insert =  std::lower_bound(main.begin(), main.end(), (*iter2).second);
                    main.insert(to_insert, (*iter2).second);
                }
            }
        }
        if (deque.size() % 2)
        {
            to_insert =  std::lower_bound(main.begin(), main.end(), malongo_deque);
            main.insert(to_insert, malongo_deque);
        }
        gettimeofday(&str, NULL);
        this->deque_aft = str.tv_sec * 1000000LL + str.tv_usec;
    }
    catch(const char *str)
    {
        std::cerr << str << std::endl;
    }
    
}

int PmergeMe::getLast_deque()
{
    return malongo;
}


void PmergeMe::print_times()
{
    std::cout << "Time to process a range of " << this->container.size() << " elements with std::vector : " << vector_aft - vector_bef << "us" << std::endl;
    std::cout << "Time to process a range of " << this->container.size() << " elements with std::deque : " << deque_aft - deque_bef << "us" << std::endl;
}

PmergeMe::~PmergeMe()
{
}