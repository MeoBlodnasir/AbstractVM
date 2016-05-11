#include "Double.hpp"
#include <iostream>
#include <cfloat>
#include "Exception.hpp"

Double::Double(std::string const & value) {
	long double val;
	val = std::stold(value, NULL);
	if (val > DBL_MAX) {
		throw (Exception("Overflow on creation of Double\n"));
	} else if ( val < DBL_MIN) {
		throw (Exception("Underflow on creation of Double\n"));
	}
}

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

long double	Double::getValue(void) const {
	return this->_value;
}
