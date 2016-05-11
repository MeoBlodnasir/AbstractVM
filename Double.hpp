#ifndef DOUBLE_H_
# define DOUBLE_H_

#include "IOperand.hpp"
#include "Factory.hpp"



class Double: public IOperand {
	public:
		Double(std::string const &  value);
		~Double() {}
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
};

#endif
