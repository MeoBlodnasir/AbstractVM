#include "Int32.hpp"
#include <iostream>
#include <climits>
#include "Exception.hpp"

Int32::Int32(std::string const & value) {
	long double val;
	val = std::stold(value, NULL);
	if (val > INT_MAX) {
		throw (Exception("Overflow on creation of Int32\n"));
	} else if ( val < INT_MIN) {
		throw (Exception("Underflow on creation of Int32\n"));
	}
}

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

long double	Int32::getValue(void) const {
	return this->_value;
}
