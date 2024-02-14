/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:56:55 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/14 00:40:41 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main()
{
       try {
        // Default constructor
        Array<int> emptyArray;
        std::cout << "Empty Array Size: " << emptyArray.size() << std::endl;
        // Constructor with size parameter
        Array<int> newArray(5);
        std::cout << "New Array Size: " << newArray.size() << std::endl;
        // Copy constructor
        Array<int> copiedArray(newArray);
        std::cout << "Copied Array Size: " << copiedArray.size() << std::endl;
        // Assignment operator
        Array<int> assignedArray = newArray;
        std::cout << "Assigned Array Size: " << assignedArray.size() << std::endl;
        // Accessing elements
        for (unsigned int i = 0; i < newArray.size(); ++i) {
            newArray[i] = i * 2;
            std::cout << "Element " << i << ": " << newArray[i] << std::endl;
        }

        // Out of bounds access (should throw an exception)
        // Uncomment the next line to test exception handling
        // int value = newArray[10];
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}

// #include "Array.hpp"
// #include <iostream>
// #include <ctime>
// #include <cstdlib>

// #define MAX_VAL 10
// int main()
// {
//     Array<int> numbers(MAX_VAL);
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand() / (RAND_MAX / 30);
//         numbers[i] = value;
//     }
//     std::cout << "Array contains:" << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         std::cout << numbers[i] << std::endl;
//     }
//     {
//         Array<int> numbers_cpy(MAX_VAL);

//         numbers_cpy = numbers;
//         std::cout << "Array contains:" << std::endl;
//         for (int i = 0; i < MAX_VAL; i++)
//         {
//             std::cout << numbers_cpy[i] << std::endl;
//         }
//     }
//     {
//         Array<int> numbers_cpy(numbers);

//         std::cout << "Array contains:" << std::endl;
//         for (int i = 0; i < MAX_VAL; i++)
//         {
//             std::cout << numbers_cpy[i] << std::endl;
//         }
//     }
//     std::cout << "Trying to access out of range index" << std::endl;
//     try
//     {
//         const int index = rand() % MAX_VAL;
//         std::cout << "Index: " << index << std::endl;
//         std::cout << "Value: " << numbers[index] << std::endl;
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
