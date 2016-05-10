#include "Double.hpp"
#include <iostream>

Double::Double(std::string const & value) {}

IOperand const * Double::operator+(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Double::operator-(IOperand const & rhs) const {
	return NULL;
}

IOperand const * Double::operator*(IOperand const & rhs) const{
	return NULL;
}

IOperand const * Double::operator/ (IOperand const & rhs) const {
	return NULL;
}

IOperand const * Double::operator%(IOperand const & rhs) const {
	return NULL;
}

int 		Double::getPrecision(void) const {
	return 0;

}

eOperandType	Double::getType(void) const {
	return DOUBLE;

}

std::string const & Double::toString(void) const {
	std::string *s = new std::string("foo");
	return (*s);
}
