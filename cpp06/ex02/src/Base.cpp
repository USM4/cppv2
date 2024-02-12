/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:09:55 by oredoine          #+#    #+#             */
/*   Updated: 2024/02/12 22:36:46 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

Base* generate(void)
{
    srand(static_cast<unsigned int>(time(0)));
    int choice = rand() % 3;
    switch (choice)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout<< "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout<< "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout<< "C" << std::endl;
    else
        std::cerr<< "unknown type to cast to" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout<< "A" << std::endl;
        (void) a;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout<< "B" << std::endl;
        (void) b;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout<< "C" << std::endl;
        (void) c;
    }
    catch(const std::exception& e)
    {
  }
}

Base::~Base()
{
    
}