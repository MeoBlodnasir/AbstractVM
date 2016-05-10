#ifndef FLOAT_H_
# define FLOAT_H_

#include "IOperand.hpp"
#include "VM.hpp"



class Float: public IOperand {
	public:
		Float(std::string const &  value);
		~Float() {}
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
