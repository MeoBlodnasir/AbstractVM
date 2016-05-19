#ifndef IOPERAND_H_
# define IOPERAND_H_

#include <iostream>

enum                    eOperandType
{
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
};

class IOperand {
	public:
		virtual int 		getPrecision(void) const = 0;
		virtual eOperandType	getType(void) const = 0;

		virtual IOperand const * operator+(IOperand const & rhs) const = 0;
		virtual IOperand const * operator-(IOperand const & rhs) const = 0;
		virtual IOperand const * operator*(IOperand const & rhs) const = 0;
		virtual IOperand const * operator/(IOperand const & rhs) const = 0;
		virtual IOperand const * operator%(IOperand const & rhs) const = 0;

		virtual std::string const & toString(void) const = 0;

		virtual ~IOperand(void) {}
		virtual	long double getValue(void) const = 0;
};

#endif
