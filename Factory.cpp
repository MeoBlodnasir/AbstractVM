#include "Factory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"




Factory::Factory() {
	_tab[INT8] = &Factory::createInt8;
	_tab[INT16] = &Factory::createInt16;
	_tab[INT32] = &Factory::createInt32;
	_tab[FLOAT] = &Factory::createFloat;
	_tab[DOUBLE] = &Factory::createDouble;
}

IOperand *Factory::createOperand(eOperandType const &type, const std::string & value) {
	(this->*_tab[type])(value);
}

IOperand *Factory::createInt8(const std::string & value) {
	return (new Int8(value));
}

IOperand *Factory::createInt16(const std::string & value) {
	return (new Int16(value));
}

IOperand *Factory::createInt32(const std::string & value) {
	return (new Int32(value));
}

IOperand *Factory::createFloat(const std::string & value) {
	return (new Float(value));
}

IOperand *Factory::createDouble(const std::string & value) {
	return (new Double(value));
}

