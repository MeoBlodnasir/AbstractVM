#include "Int8.hpp"
#include <iostream>

Int8::Int8(std::string const & value) {}

IOperand const * Int8::operator+(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int8::operator-(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int8::operator*(IOperand const & rhs) const{
	return NULL;
}

IOperand const * Int8::operator/ (IOperand const & rhs) const {
	return NULL;
}

IOperand const * Int8::operator%(IOperand const & rhs) const {
	return NULL;
}

int 		Int8::getPrecision(void) const {
	return 0;

}

eOperandType	Int8::getType(void) const {
	return INT8;

}

std::string const & Int8::toString(void) const {
	std::string *s = new std::string("foo");
	return (*s);
}
