/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:53:30 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/21 22:39:54 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
}

BitcoinExchange::~BitcoinExchange()
{
}

int checkFileExtension(std::string file)
{
    size_t dotpos = file.find(".");
    std::string extension;
    if(dotpos != std::string::npos)
        extension = file.substr(dotpos + 1);
    if (extension != "txt")
        return 0;
    return 1;
}

double    CheckIsValidNumber(std::string &str)
{
    std::stringstream ss(str);
    double num;
    ss >> num;
    if(ss.fail() || !ss.eof())
        throw std::runtime_error("Error: bad input not a digit");
    return (num);
}

double ParseBitcoinValue(std::string value)
{ 
    double val = CheckIsValidNumber(value);
    if(value.empty())
        throw std::runtime_error("Error: bad input empty value .");
    if (val < 0)
        throw std::runtime_error("Error: not a positive number.");
    if(val > std::numeric_limits<int>::max())
        throw std::runtime_error("Error: too large a number.");
    return val;
}

double  CheckIsValidYear(std::string year)
{
    double annee = CheckIsValidNumber(year);
    if(annee < 2009 || annee > 2022)
        throw std::runtime_error("Error : Bad input annee");
    return annee;
}
double  CheckIsValidMonth(std::string month)
{
    double mois = CheckIsValidNumber(month);
    if(mois < 1 ||  mois > 12)
        throw std::runtime_error("Error : Bad input mois");
    return mois;
}
double CheckIsValidDay(std::string day)
{
    double jour = CheckIsValidNumber(day);
    if(jour < 1 || jour > 31)
        throw std::runtime_error("Error : Bad input jour");
    return jour;
}

void    BitcoinExchange::BitcoinOperation(std::string date)
{
    std::map<std::string, double>::iterator iter = this->myDbMap.begin();
    std::map<std::string, double>::iterator key = this->myDbMap.lower_bound(date);
    if(key->first != iter->first &&  key->first != date)
        key--;
    // std::cout<< "value from the input : "<< this->value << "value from db : "<< key->second << std::endl;
    this->value *= key->second;
}

void BitcoinExchange::ParseSingleLine(std::string line)
{
    std::stringstream ss(line);
    std::string date;
    std::string value;
    std::getline(ss, date,'|');
    std::getline(ss, value);
    try
    {
        std::stringstream check(date);
        std::string year;
        std::string month;
        std::string day;
        std::getline(check, year,  '-');
        std::getline(check, month,  '-');
        std::getline(check, day, ' ');
        if(year.length() != 4 || year[0] == '0')
            throw std::runtime_error("Error : Bad input YEAR");
        double annee = CheckIsValidYear(year);
        if(month.length() != 2 || (month[0] == '0' && month[1] == '0'))
            throw std::runtime_error("Error : Bad input MONTH");
        double mois = CheckIsValidMonth(month);
        if(day.length() != 2 || (day[0] == '0' && day[1] == '0'))
            throw std::runtime_error("Error : Bad input DAY");
         double jour = CheckIsValidDay(day);
        if (mois == 2 && jour > 29)
            throw std::runtime_error("Error : Bad input : february is limited");
        std::cout << annee << "-";
        if (mois < 10)
            std::cout << "0";
        std::cout << mois << "-" ;
        if (jour < 10)
            std::cout << "0";
        std::cout << jour << " ";

        double val = ParseBitcoinValue(value);
        this->value = val;
        BitcoinOperation(date);
        std::cout << "=> "<< val << " = " << this->value<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void BitcoinExchange::bitcoin(std::string str)
{
    if(!checkFileExtension(str))
    {
        std::cerr<< "invalid input file"<< std::endl;
        return;
    }
    std::ifstream inputfile(str);
    if (!inputfile)
    {
        std::cerr<< "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(inputfile, line);
    if(line != "date | value")
        throw std::runtime_error("first line in your input file should be like this: data | value");
    while (std::getline(inputfile, line))
    {
        ParseSingleLine(line);
    }
}



 

void BitcoinExchange::fillDatabase()
{
    std::ifstream database("data.csv");
    if (!database)
    {
        std::cerr<< "Error: could not open dbfile." << std::endl;
        return;
    }
    std::string line;
    std::string date;
    std::string value;
    double val;
    std::getline(database, line);
    while (std::getline(database, line))
    {
        size_t coma = line.find(",");
        date = line.substr(0, coma);
        value = line.substr(coma + 1, line.length());
        std::stringstream ins (value);
        ins >> val;
        this->myDbMap[date] = val;
    }
    // std::map<std::string, double>::iterator it;
    // for (it = this->myDbMap.begin(); it != this->myDbMap.end(); ++it)
    // std::cout << "Date: " << it->first<< std::endl << "Value: " << it->second << std::endl;
}

