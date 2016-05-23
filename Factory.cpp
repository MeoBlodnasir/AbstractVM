/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:57:22 by aduban            #+#    #+#             */
/*   Updated: 2016/05/19 17:57:24 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Operand.hpp"

Factory::Factory() {
	_tab[INT8] = &Factory::createInt8;
	_tab[INT16] = &Factory::createInt16;
	_tab[INT32] = &Factory::createInt32;
	_tab[FLOAT] = &Factory::createFloat;
	_tab[DOUBLE] = &Factory::createDouble;
}

IOperand *Factory::createOperand(eOperandType const &type, const std::string & value) {
	return	(this->*_tab[type])(value);
}

IOperand *Factory::createInt8(const std::string & value) {
	return (new Operand(value, INT8));
}

IOperand *Factory::createInt16(const std::string & value) {
	return (new Operand(value, INT16));
}

IOperand *Factory::createInt32(const std::string & value) {
	return (new Operand(value, INT32));
}

IOperand *Factory::createFloat(const std::string & value) {
	return (new Operand(value, FLOAT));
}

IOperand *Factory::createDouble(const std::string & value) {
	return (new Operand(value, DOUBLE));
}
