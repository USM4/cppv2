/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:14:18 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/15 18:47:34 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void toUppercCase(T& str) 
{
    for (size_t i = 0; i < str.length(); ++i)
        str[i] = std::toupper(str[i]);
}

int main() 
{
    std::string arr[] = {"oussama", "redoine", "oredoine"};
    int len = sizeof(arr) / sizeof(arr[0]);
    std::cout << "*********** Before imps ***********"<< std::endl;
    for(int i = 0; i < len ;i++)
        std::cout << arr[i]<< std::endl;
    iter(arr, len, toUppercCase<std::string>);
    std::cout<< "*********** After imps ***********"<< std::endl;
    for(int i = 0; i < len ;i++)
        std::cout<< arr[i]<< std::endl;
}
