#include "Float.hpp"
#include <iostream>
#include <cfloat>
#include "Exception.hpp"

Float::Float(std::string const & value) {
	long double val;
	val = std::stold(value, NULL);
	if (val > FLT_MAX) {
		throw (Exception("Overflow on creation of Float\n"));
	} else if ( val < FLT_MIN) {
		throw (Exception("Underflow on creation of Float\n"));
	}
}

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

long double Float::getValue(void) const {
	return this->_value;
}
