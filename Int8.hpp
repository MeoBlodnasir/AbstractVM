#ifndef INT8_H_
# define INT8_H_

#include "IOperand.hpp"
#include "VM.hpp"



class Int8: public IOperand {
	public:
		Int8(std::string const &  value);
		~Int8() {}
		IOperand const * operator+(IOperand const & rhs) const ; 
		IOperand const * operator-(IOperand const & rhs)const ;
		IOperand const * operator*(IOperand const & rhs)const ;
		IOperand const * operator/(IOperand const & rhs)const ;
		IOperand const * operator%(IOperand const & rhs)const ;
		int 		getPrecision(void) const ;
		eOperandType	getType(void) const ;
		std::string const & toString(void) const;
};

#endif
