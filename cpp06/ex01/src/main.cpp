/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:57:58 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/12 22:34:12 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data = {10};

    uintptr_t serializer = Serializer::serialize(&data);
    Data* deserializer = Serializer::deserialize(serializer);
    std::cout << "deSerialized: "<< deserializer->val << std::endl;
    std::cout << "old value: "<< data.val << std::endl;

}
