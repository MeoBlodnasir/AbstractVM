#ifndef INT8_H_
# define INT8_H_

#include "IOperand.hpp"

class Operand: public IOperand {
	public:
		Operand(std::string const &  value, eOperandType type);
		~Operand() {}
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
