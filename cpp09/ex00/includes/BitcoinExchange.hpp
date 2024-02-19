/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:52:06 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/19 18:07:16 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

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

class BitcoinExchange
{    
    private :
        std::map<std::string, double> myDbMap;
        double value;
    public:
        BitcoinExchange();
        void bitcoin(std::string str);
        void fillDatabase();
        ~BitcoinExchange();
        void BitcoinOperation(std::string date);
        void ParseSingleLine(std::string line);

};

#endif