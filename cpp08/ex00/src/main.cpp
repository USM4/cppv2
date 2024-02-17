/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:40:15 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/17 19:53:51 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> container;
        container.push_back(13);
        container.push_back(37);
        container.push_back(42);
        if (easyfind(container, 42))
            std::cout << "Found Element" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<< "Element Not Found "<< std::endl;
    }
    
}