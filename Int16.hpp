#ifndef INT16_H_
# define INT16_H_

#include "IOperand.hpp"
#include "VM.hpp"



class Int16: public IOperand {
	public:
		Int16(std::string const &  value);
		~Int16() {}
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
