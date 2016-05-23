/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:57:06 by aduban            #+#    #+#             */
/*   Updated: 2016/05/19 17:57:11 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

Exception::Exception(std::string const &msg) throw()
{
  this->_msg = msg;
}

Exception::~Exception() throw()
{

}

Exception::Exception() {
}

const char	*Exception::what() const throw()
{
  return (this->_msg.c_str());
}

Exception& Exception::operator=(const Exception& rhs) {
	(void)rhs;
	return *this;
}
