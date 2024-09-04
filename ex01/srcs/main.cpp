/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/04 22:28:56 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(int ac, char **av)
{
	Data	data;

	data.i = ac;
	data.str = av[ac - 1];

	std::cout << "Data address: " << &data << " | i = " << data.i << " | str = " << data.str << "\n\n";

	uintptr_t	serialized = Serializer::serialize(&data);
	std::cout << "Serialization result: " << serialized << "\n";
	Data	*ptr = Serializer::deserialize(serialized);
	std::cout << "Deserialization result: " << ptr << "\n\n";

	std::cout << "ptr address: " << ptr << "| i = " << ptr->i << " | str = " << ptr->str << std::endl;
	return 0;
}
