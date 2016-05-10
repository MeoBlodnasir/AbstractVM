#include "Float.hpp"
#include <iostream>

Float::Float(std::string const & value) {}

IOperand const * Float::operator+(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Float::operator-(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Float::operator*(IOperand const & rhs) const{
	return NULL;
}

IOperand const * Float::operator/ (IOperand const & rhs) const {
	return NULL;
}

IOperand const * Float::operator%(IOperand const & rhs) const {
	return NULL;
}

int 		Float::getPrecision(void) const {
	return 0;

}

eOperandType	Float::getType(void) const {
	return FLOAT;

}

std::string const & Float::toString(void) const {
	std::string *s = new std::string("foo");
	return (*s);
}
