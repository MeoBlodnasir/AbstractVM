#include "Int32.hpp"
#include <iostream>

Int32::Int32(std::string const & value) {}

IOperand const * Int32::operator+(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int32::operator-(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int32::operator*(IOperand const & rhs) const{
	return NULL;
}

IOperand const * Int32::operator/ (IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int32::operator%(IOperand const & rhs) const {
	return NULL;
}

int 		Int32::getPrecision(void) const {
	return 0;

}

eOperandType	Int32::getType(void) const {
	return INT32;

}

std::string const & Int32::toString(void) const {
	std::string *s = new std::string("foo");
	return (*s);
}
