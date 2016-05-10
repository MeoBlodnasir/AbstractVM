#include "Int16.hpp"
#include <iostream>

Int16::Int16(std::string const & value) {}

IOperand const * Int16::operator+(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int16::operator-(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int16::operator*(IOperand const & rhs) const{
	return NULL;
}

IOperand const * Int16::operator/ (IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int16::operator%(IOperand const & rhs) const {
	return NULL;
}

int 		Int16::getPrecision(void) const {
	return 0;

}

eOperandType	Int16::getType(void) const {
	return INT16;

}

std::string const & Int16::toString(void) const {
	std::string *s = new std::string("foo");
	return (*s);
}
