#include "VM.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"




VM::VM() {
	_tab[INT8] = &VM::createInt8;
	_tab[INT16] = &VM::createInt16;
	_tab[INT32] = &VM::createInt32;
	_tab[FLOAT] = &VM::createFloat;
	_tab[DOUBLE] = &VM::createDouble;
}

IOperand *VM::createInt8(const std::string & value) {
	return (new Int8(value));
}

IOperand *VM::createInt16(const std::string & value) {
	return (new Int16(value));
}
IOperand *VM::createInt32(const std::string & value) {
	return (new Int32(value));
}
IOperand *VM::createFloat(const std::string & value) {
	return (new Float(value));
}
IOperand *VM::createDouble(const std::string & value) {
	return (new Double(value));
}

