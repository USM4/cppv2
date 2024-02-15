/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:56:55 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/15 03:43:51 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main()
{
    try
    {
        Array<int> emptyArray;
        std::cout << "Empty Array Size: " << emptyArray.size() << std::endl;
        Array<int> newArray(5);
        std::cout << "New Array Size: " << newArray.size() << std::endl;
        Array<int> copiedArray(newArray);
        std::cout << "Copied Array Size: " << copiedArray.size() << std::endl;
        Array<int> assignedArray = newArray;
        std::cout << "Assigned Array Size: " << assignedArray.size() << std::endl;
        for (unsigned int i = 0; i < newArray.size(); ++i) 
        {
            newArray[10] = i * 2;
            std::cout << "Element " << i << ": " << newArray[i] << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

}
