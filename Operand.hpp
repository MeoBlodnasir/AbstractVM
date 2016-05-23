/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:58:03 by aduban            #+#    #+#             */
/*   Updated: 2016/05/19 17:58:22 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H_
# define OPERAND_H_

#include "IOperand.hpp"

class Operand: public IOperand {
	public:
		Operand(std::string const &  value, eOperandType type);
		Operand();
		virtual ~Operand(); 
		Operand(const Operand & src);
		Operand & operator=(const Operand & rhs);
		IOperand const * operator+(IOperand const & rhs) const ; 
		IOperand const * operator-(IOperand const & rhs)const ;
		IOperand const * operator*(IOperand const & rhs)const ;
		IOperand const * operator/(IOperand const & rhs)const ;
		IOperand const * operator%(IOperand const & rhs)const ;
		int 		getPrecision(void) const ;
		eOperandType	getType(void) const ;
		std::string const & toString(void) const;
		long double getValue(void) const;
	private:
		long double _value;
		eOperandType _type;
};
#endif
