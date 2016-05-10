#ifndef INT32_H_
# define INT32_H_

#include "IOperand.hpp"
#include "VM.hpp"



class Int32: public IOperand {
	public:
		Int32(std::string const &  value);
		~Int32() {}
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
