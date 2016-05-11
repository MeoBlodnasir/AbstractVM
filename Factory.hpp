#ifndef FACTORY_H_
# define FACTORY_H_

#include "IOperand.hpp"
#include <map>
#include <iostream>


class Factory {
	public:
		Factory();
		~Factory();
		IOperand *createOperand(eOperandType const &type, const std::string & value);
	private:
		std::map<eOperandType, IOperand *(Factory::*)(const std::string &)> _tab;
		IOperand	*createInt8(const std::string &value);
		IOperand	*createInt16(const std::string &value);
		IOperand	*createInt32(const std::string &value);
		IOperand	*createFloat(const std::string &value);
		IOperand	*createDouble(const std::string &value);

};

#endif
