/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:25:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/18 21:35:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <cerrno>
#include <iostream>
#include <cmath>
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

const char *ScalarConverter::IntegerOverflow::what() const throw() {
	return ("interger overflow");
}

const char *ScalarConverter::FloatOverflow::what() const throw() {
	return ("float overflow");
}

const char *ScalarConverter::DoubleOverflow::what() const throw() {
	return ("double overflow");
}

const char *ScalarConverter::InvalidType::what() const throw() {
	return ("invalid type");
}

/* ************************************************************************** */

bool	ScalarConverter::isCharLiteral(const std::string &str) {
	if (str[0] != '\'' || !isprint(str[1]) || str[2] != '\'' || str[3]) 
		return false;

	const char c = str[1];

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

bool	ScalarConverter::isIntLiteral(const std::string &str) {
	char *endPtr = NULL;
	errno = 0;
	const long parse = strtol(str.c_str(), &endPtr, 10);
	if (*endPtr)
		return false;
	if (errno == ERANGE
		|| parse < std::numeric_limits<int>::min()
		|| parse > std::numeric_limits<int>::max())
		throw IntegerOverflow();

	const int i = static_cast<int>(parse);

	if (i < std::numeric_limits<char>::min()
		|| i > std::numeric_limits<char>::max()) {
			std::cout << "char: impossible\n";
	} else if (i < ' ' || i > '~') {
		std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: \'" << static_cast<char>(i) << "\'\n";
	}

	std::cout << "int: " << i << "\n";
	std:: cout << "float: " << std::fixed << static_cast<float>(i) << "f\n";
	std:: cout << "double: " << std::fixed << static_cast<double>(i) << std::endl;
	return true;
}

bool	ScalarConverter::isFloatLiteral(const std::string &str) {
	char	*endPtr = NULL;
	errno = 0;
	const double parse = strtod(str.c_str(), &endPtr);
	if (*endPtr != 'f' || std::isnan(parse))
		return false;
	if (!std::isinf(parse)
		&& (errno == ERANGE
		|| parse < -std::numeric_limits<float>::max()
		|| parse > std::numeric_limits<float>::max()))
		throw FloatOverflow();

	const float f = static_cast<float>(parse);

	if (f < std::numeric_limits<char>::min()
		|| f > std::numeric_limits<char>::max()) {
			std::cout << "char: impossible\n";
	} else if (f < ' ' || f > '~') {
		std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: \'" << static_cast<char>(f) << "\'\n";
	}

	if (f < std::numeric_limits<int>::min()
		|| f > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(f) << "\n";
	}

	std:: cout << "float: " << std::fixed << f << "f\n";
	std:: cout << "double: " << std::fixed << static_cast<double>(f) << std::endl;
	return true;
}

bool	ScalarConverter::isDoubleLiteral(const std::string &str) {
	char	*endPtr = NULL;
	errno = 0;
	const double parse = strtod(str.c_str(), &endPtr);
	if (*endPtr)
		return false;
	if (errno == ERANGE)
		throw DoubleOverflow();

	if (parse < std::numeric_limits<char>::min()
		|| parse > std::numeric_limits<char>::max()
		|| std::isnan(parse)) {
			std::cout << "char: impossible\n";
	} else if (parse < ' ' || parse > '~') {
		std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: \'" << static_cast<char>(parse) << "\'\n";
	}

	if (parse < std::numeric_limits<int>::min()
		|| parse > std::numeric_limits<int>::max()
		|| std::isnan(parse)) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(parse) << "\n";
	}

	if ( !std::isinf(parse)
		&& (parse < -std::numeric_limits<float>::max()
		|| parse > std::numeric_limits<float>::max())) {
		std::cout << "float: impossible\n";
	} else {
		std::cout << "float: " << std::fixed << static_cast<float>(parse) << "f\n";
	}

	std:: cout << "double: " << std::fixed << parse << std::endl;
	return true;
}

void	ScalarConverter::convert(const std::string &str) {

	if (str.length() && (ScalarConverter::isCharLiteral(str)
		|| ScalarConverter::isIntLiteral(str)
		|| ScalarConverter::isFloatLiteral(str)
		|| ScalarConverter::isDoubleLiteral(str)))
			return ;
	throw InvalidType();
}
