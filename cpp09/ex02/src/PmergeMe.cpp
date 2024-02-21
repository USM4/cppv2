/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:37:29 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/22 00:55:52 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

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


void PmergeMe::vector_algo()
{
    try
    {
        if (this->container.size() < 2)
            throw "need more elements";
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
        print_container_main(main);
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



PmergeMe::~PmergeMe()
{
}
