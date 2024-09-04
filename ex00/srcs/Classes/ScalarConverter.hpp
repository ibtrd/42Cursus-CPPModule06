 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:25:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/02 22:22:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &);
		
		~ScalarConverter(void);
		
		ScalarConverter	&operator=(const ScalarConverter &);

		static bool	isCharLiteral(const std::string &);
		static bool	isIntLiteral(const std::string &);
		static bool	isFloatLiteral(const std::string &);
		static bool isDoubleLiteral(const std::string &);

	public:
		static void	convert(const std::string &);

		class IntegerOverflow : public std::exception {
			const char *what() const throw();
		};

		class FloatOverflow : public std::exception {
			const char *what() const throw();
		};

		class DoubleOverflow : public std::exception {
			const char *what() const throw();
		};

		class InvalidType : public std::exception {
			const char *what() const throw();
		};
};

#endif /* ******************************************************************* */
