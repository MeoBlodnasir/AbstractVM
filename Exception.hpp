/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:57:16 by aduban            #+#    #+#             */
/*   Updated: 2016/05/19 17:57:19 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXCEPTION_HPP_
# define EXCEPTION_HPP_

#include <iostream>

class Exception : public std::exception
{
	private:
		std::string	_msg;
	public:
		Exception();
		Exception(std::string const &msg) throw();
		virtual ~Exception() throw();
		virtual const char *what() const throw();
		Exception& operator=(const Exception& rhs);
};

#endif
