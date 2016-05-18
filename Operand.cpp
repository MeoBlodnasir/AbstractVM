#include "Operand.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include "Exception.hpp"
#include "Factory.hpp"
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>

Operand::~Operand() {
}

Operand::Operand(const Operand & src) {
	*this = src;
	return ;
}

Operand & Operand::operator=(const Operand & rhs) {
	this->_value = rhs.getValue();
	this->_type = rhs.getType();
	return *this;
}

Operand::Operand(std::string const & value, eOperandType type) {
	switch (type) {
		case INT8:
			try {
				int8_t v = boost::numeric_cast<int8_t>(boost::lexical_cast<int>(value));
				_value = boost::numeric_cast<long double>(v);
				_type = type;
			}
			catch (const std::exception& e) {
				throw (Exception("Failed to convert value to Int8\n"));
			}
			break ;
		case INT16:
			try { 
				int16_t v = boost::lexical_cast<int16_t>(value);
				_value = boost::lexical_cast<long double>(v);
				_type = type;
			}
			catch (const std::exception& e) {
				throw (Exception("Failed to convert value to Int16\n"));
			}
			break ;
		case INT32:
			try {
				int32_t v = boost::lexical_cast<int32_t>(value);
				_value = boost::lexical_cast<long double>(v);
				_type = type;
			}
			catch (const std::exception& e) {
				throw (Exception("Failed to convert value to Int32\n"));
			}
			break ;
		case FLOAT:
			try {
				float v = boost::lexical_cast<float>(value);
				_value = boost::lexical_cast<long double>(v);
				_type = type;
			}
			catch (const std::exception& e) {
				throw (Exception("Failed to convert value to Float\n"));
			}
			break ;
		case DOUBLE:
			try {
				double v = boost::lexical_cast<double>(value);
				_value = boost::lexical_cast<long double>(v);
				_type = type;
			}
			catch (const std::exception& e) {
				throw (Exception("Failed to convert value to Double\n"));
			}
			break ;
		default:
			throw (Exception("Type not recognised\n"));
			break ;
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
	if (rhs.getValue() == 0) { throw (Exception("Modulus by 0\n")); }
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
