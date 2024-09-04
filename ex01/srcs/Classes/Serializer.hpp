/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:16:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/04 21:52:21 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <Data.hpp>

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &);

		~Serializer(void);

		Serializer	&operator=(const Serializer &);

	public:
		static uintptr_t	serialize(Data *);
		static Data*		deserialize(uintptr_t);
};

#endif /* ******************************************************************* */
