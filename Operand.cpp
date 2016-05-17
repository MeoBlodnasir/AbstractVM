#include "Operand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include "Exception.hpp"
#include "Factory.hpp"
#include <boost/lexical_cast.hpp>
/*
Operand::Operand(std::string const & value, eOperandType type) {
	long double val;
	try { val = std::stold(value, NULL);}
	catch (const std::exception& e) { 
		throw (Exception("Over/Underflow on assignment operation\n"));
	}
	if (val > SCHAR_MAX) {
		throw (Exception("Overflow on creation of Operand\n"));
	} else if ( val < SCHAR_MIN ) {
		throw (Exception("Underflow on creation of Operand\n"));
	}
	_value = val;
	_type = type;
}
*/

Operand::Operand(std::string const & value, eOperandType type) {
	switch (type) {
		case INT8:
			try { char v = boost::lexical_cast<char>(value); }
			catch (const std::exception& e) {
				throw (Exception("Failed to convert value de Int8\n"));
			}
	}
}

IOperand const * Operand::operator+(IOperand const & rhs) const {
	long double res;
	Factory f;
	std::stringstream stream;
	try { res = this->getValue() + rhs.getValue(); } 
	catch (const std::exception& e) { 
		throw (Exception("Over/Underflow on ADD operation\n"));
	}
	int type = this->getType() < rhs.getType() ? rhs.getType() : this->getType();
	stream << res;
	return f.createOperand((eOperandType)type, stream.str()); 
}

IOperand const * Operand::operator-(IOperand const & rhs) const {
	long double res;
	Factory f;
	std::stringstream stream;
	try { res = this->getValue() - rhs.getValue(); } 
	catch (const std::exception& e) { 
		throw (Exception("Over/Underflow on SUB operation\n"));
	}
	int type = this->getType() < rhs.getType() ? rhs.getType() : this->getType();
	stream << res;
	return f.createOperand((eOperandType)type, stream.str()); 
}

IOperand const * Operand::operator*(IOperand const & rhs) const{
	long double res;
	Factory f;
	std::stringstream stream;
	try { res = this->getValue() * rhs.getValue(); } 
	catch (const std::exception& e) { 
		throw (Exception("Over/Underflow on MUL operation\n"));
	}
	int type = this->getType() < rhs.getType() ? rhs.getType() : this->getType();
	stream << res;
	return f.createOperand((eOperandType)type, stream.str()); 
}

IOperand const * Operand::operator/(IOperand const & rhs) const {
	long double res;
	Factory f;
	std::stringstream stream;
	if (rhs.getValue() == 0) { throw (Exception("Division by 0\n")); }
	try { res = this->getValue() / rhs.getValue(); } 
	catch (const std::exception& e) { 
		throw (Exception("Over/Underflow on DIV operation\n"));
	}
	int type = this->getType() < rhs.getType() ? rhs.getType() : this->getType();
	stream << res;
	return f.createOperand((eOperandType)type, stream.str()); 
}

IOperand const * Operand::operator%(IOperand const & rhs) const {
	long double res;
	Factory f;
	std::stringstream stream;
	int a;
	int b;
	if (rhs.getValue() == 0) { throw (Exception("Division by 0\n")); }
	try {
		a = boost::lexical_cast<int>(this->getValue());
		b = boost::lexical_cast<int>(this->getValue());
	}
	catch (const std::exception& e) { 
		throw (Exception("Modulus only applies to ints\n"));
	}
	try { res = a % b; } 
	catch (const std::exception& e) { 
		throw (Exception("MOD operation failed\n"));
	}
	int type = this->getType() < rhs.getType() ? rhs.getType() : this->getType();
	stream << res;
	return f.createOperand((eOperandType)type, stream.str()); 
}

int 		Operand::getPrecision(void) const {
	return static_cast<int>(_type);
}

eOperandType	Operand::getType(void) const {
	return _type;
}

std::string const & Operand::toString(void) const {
	std::string *s = new std::string("Number type: %d, value: %d\n", getType(), getPrecision());
	return (*s);
}

long double	Operand::getValue(void) const {
	return this->_value;
}
