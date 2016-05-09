#include "IOperand.hpp"

IOperand const * createInt8(std::string const & value)
{
	return NULL;
}
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))


IOperand const * IOperand::createOperand(IOperand::eOperandType type, std::string const value) const {
	typedef  IOperand const * (IOperand::*FctnPtr)(std::string const & value) const;

	//	IOperand const * (IOperand::*tab[5])(std::string const & value) const =
	//
	FctnPtr a[] = { 
		&IOperand::createInt8, 
		&IOperand::createInt16, 
		&IOperand::createInt32,
		&IOperand::createFloat,
		&IOperand::createDouble
	};
	return (*(a[0]))(value);
}

