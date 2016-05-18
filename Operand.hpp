#ifndef INT8_H_
# define INT8_H_

#include "IOperand.hpp"

class Operand: public IOperand {
	public:
		Operand(std::string const &  value, eOperandType type);
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
