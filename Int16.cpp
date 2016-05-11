#include "Int16.hpp"
#include <iostream>
#include <climits>
#include "Exception.hpp"

Int16::Int16(std::string const & value) {
	long double val;
	try {
	val = std::stold(value, NULL);
	} catch(const std::exception& e) {
			std::cout << "Error : " << e.what() << std::endl;
	}
	if (val > SHRT_MAX) {
		throw (Exception("Overflow on creation of Int16\n"));
	} else if ( val < SHRT_MIN) {
		throw (Exception("Underflow on creation of Int16\n"));
	}
}

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

long double	Int16::getValue(void) const {
	return this->_value;
}
