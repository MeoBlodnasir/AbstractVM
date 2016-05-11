#include "Int8.hpp"
#include <string>
#include <iostream>
#include <climits>
#include "Exception.hpp"

Int8::Int8(std::string const & value) {
	double val;
	val = std::stold(value, NULL);
	if (val > SCHAR_MAX) {
		throw (Exception("Overflow on creation of Int8\n"));
	} else if ( val < SCHAR_MIN ) {
		throw (Exception("Underflow on creation of Int8\n"));
	}
}

IOperand const * Int8::operator+(IOperand const & rhs) const {
	long double res;
	res = this->getValue() + rhs.getValue();
	int type = this->getType() < rhs.getType() ? rhs.getType() : this->getType();
	switch (type) {
		case INT8:
			return NULL;
	}
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
	return INT8;
}

eOperandType	Int8::getType(void) const {
	return INT8;
}

std::string const & Int8::toString(void) const {
	std::string *s = new std::string("Number type: %d, value: %d\n", getType(), getPrecision());
	return (*s);
}

long double	Int8::getValue(void) const {
	return this->_value;
}
