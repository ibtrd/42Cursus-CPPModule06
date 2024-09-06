/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/06 21:57:13 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {

	int rand = std::rand() % 3;

	if (rand == 1)
		return new A();
	if (rand == 2)
		return new B();
	return new C();
}

void	identify(Base *p) {

	if (dynamic_cast<A*>(p))
		std::cout << "*p points to A type object" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "*p points to B type object" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "*p points to C type object" << std::endl;
}

void	identify(Base &p) {
	try {
		Base &ref = dynamic_cast<A&>(p);
		std::cout << "&p points to A type object" << std::endl;
		return ;
		(void)ref;
	} catch (std::exception &e) {}
	try {
		Base &ref = dynamic_cast<B&>(p);
		std::cout << "&p points to B type object" << std::endl;
		return ;
		(void)ref;
	} catch (std::exception &e) {}
	try {
		Base &ref = dynamic_cast<C&>(p);
		std::cout << "&p points to C type object" << std::endl;
		(void)ref;
	} catch (std::exception &e) {}
}

int main(void) {
	std::srand(std::time(NULL));
	{
		Base *x = new A();
		identify(x);
		identify(*x);
		delete x;
		x = new B();
		identify(x);
		identify(*x);
		delete x;
		x = new C();
		identify(x);
		identify(*x);
		delete x;
	}
	std::cout << "\n";
	{
		for (int i = 0; i < 10; i++) {
			Base *gen = generate();
			identify(gen);
			identify(*gen);
			delete gen;
			std::cout << "\n";
		}
	}
}
