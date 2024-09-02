/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:25:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/02 22:50:36 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <cerrno>
#include <iostream>
#include "ScalarConverter.hpp"

/* CONSTRUCTORS ************************************************************* */

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter::~ScalarConverter(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other) {
	if (this == &other)
		return (*this);
	// Copy instructions
	return (*this);
}

/* EXCEPTIONS *************************************************************** */

const char *ScalarConverter::IntegerOverflow::what() const throw()
{
	return ("Interger overflow");
}

/* ************************************************************************** */

bool	ScalarConverter::isCharLiteral(const char *str) {

	if (str[0] != '\'' || !isprint(str[1]) || str[2] != '\'' || str[3]) 
		return false;

	const char c = *(str + 1);

	if (isprint(c)) {
		std::cout << "char: \'" << c << "\'\n";
	} else {
		std::cout << "char: impossible\n";
	}
	std::cout << "int: " << std::fixed << static_cast<int>(c) << "\n";
	std:: cout << "float: " << std::fixed << static_cast<float>(c) << "f\n";
	std:: cout << "double: " << std::fixed << static_cast<double>(c) << std::endl;
	return true;
}

bool	ScalarConverter::isIntLiteral(const char *str) {
	char *endPtr;

	errno = 0;
	long parse = strtol(str, &endPtr, 10);
	if (*endPtr)
		return false;
	if (errno == ERANGE
		|| parse < std::numeric_limits<int>::min()
		|| parse > std::numeric_limits<int>::max())
		throw IntegerOverflow();

	int n = static_cast<int>(parse);
	if ( n < ' '
		|| n > '~'
		|| n > std::numeric_limits<char>::min()
		|| n < std::numeric_limits<char>::max()) {
		std::cout << "char: impossible\n";
	} else {
		std::cout << "char: \'" << static_cast<char>(n) << "\'\n";
	}
	std::cout << "int: " << std::fixed << n << "\n";
	std:: cout << "float: " << std::fixed << static_cast<float>(n) << "f\n";
	std:: cout << "double: " << std::fixed << static_cast<double>(n) << std::endl;
	return true;
}

void	ScalarConverter::convert(const char *str) {
	if (ScalarConverter::isCharLiteral(str))
		return ;
	if (ScalarConverter::isIntLiteral(str))
		return ;
}
