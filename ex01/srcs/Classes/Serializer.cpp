/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:16:54 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/04 22:52:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* CONSTRUCTORS ************************************************************* */

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &other) {
	*this = other;
}

Serializer::~Serializer(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

Serializer	&Serializer::operator=(const Serializer &other) {
	if (this == &other)
		return (*this);
	// Copy instructions
	return (*this);
}

/* ************************************************************************** */

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
