/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:58:30 by aduban            #+#    #+#             */
/*   Updated: 2016/05/20 15:31:57 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.hpp"
#include <boost/lexical_cast.hpp>
#include "Exception.hpp"
#include <boost/regex.hpp> 

Stack::Stack() {
	_tab["add"] = &Stack::add;
	_tab["sub"] = &Stack::sub;
	_tab["mul"] = &Stack::mul;
	_tab["div"] = &Stack::div;
	_tab["mod"] = &Stack::mod;
	_tab["pop"] = &Stack::pop;
	_tab["dump"] = &Stack::dump;
	_tab["print"] = &Stack::print;
}

Stack::~Stack() {
}

Stack::Stack(const Stack & src) {
	*this = src;
	return ;
}

Stack & Stack::operator=(const Stack & rhs) {
	(void)rhs;
	return *this;
}

std::string get_value(std::string str) {
	std::string number;
	number = str.substr(str.find("(") + 1, str.find(")") - str.find("(") - 1);
	return number;
}

void	Stack::execute(const std::string & value) {
	if (_tab.count(value) != 1) {
		throw(Exception("Command " + value +" not found"));
	}
	(this->*_tab[value])();
}

void	Stack::push(const std::string& str) {
	std::map<eOperandType, boost::regex> tab = {
		{INT8, 	boost::regex("^int8\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{INT16, 	boost::regex("^int16\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{INT32, 	boost::regex("^int32\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{FLOAT, 	boost::regex("^float\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{DOUBLE, 	boost::regex("^double\\(-?\\d+(\\.\\d+)?\\)$")}, 
	};
	boost::cmatch what;
	for(auto iterator = tab.begin(); iterator != tab.end(); iterator++) {
		if (boost::regex_match(str.c_str(), what, iterator->second)) {
			_stack.push_front(_facto.createOperand(iterator->first, get_value(str)));
			return ;
		}
	}
	throw(Exception("Invalid push command."));
}

void	Stack::ass(const std::string &str) {
	if (_stack.size() == 0) {
		throw(Exception("Not enough elements in the stack to assert\n" ));
	}
	std::map<eOperandType, boost::regex> tab = {
		{INT8, 	boost::regex("^int8\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{INT16, 	boost::regex("^int16\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{INT32, 	boost::regex("^int32\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{FLOAT, 	boost::regex("^float\\(-?\\d+(\\.\\d+)?\\)$")}, 
		{DOUBLE, 	boost::regex("^double\\(-?\\d+(\\.\\d+)?\\)$")}, 
	};
	boost::cmatch what;
	for (auto iterator = tab.begin(); iterator != tab.end(); iterator++) {
		if (boost::regex_match(str.c_str(), what, iterator->second)) {
			IOperand* io = _facto.createOperand(iterator->first, get_value(str));
			if ((io->getType() == _stack.front()->getType()) && (io->getValue() == _stack.front()->getValue())) {
				delete io;
				return ;
			} else {
			//	std::cout << io->getType() << " VS " << _stack.front()->getType() << std::endl; 
			//	std::cout << io->getValue() << " VS " << _stack.front()->getValue() << std::endl; 
				delete io;
				throw(Exception("Assert failed."));
			}
			return ;
		}
	}
	throw(Exception("Invalid assert command."));
}

void	Stack::add(void) {
	if (_stack.size() < 2) {
		throw(Exception("Not enough elements in the stack to add\n" ));
	}
	auto i = _stack.begin();
	auto j = i;
	j++;
	const IOperand *ret = *(*j) + *(*i);
	_stack.pop_front();
	_stack.pop_front();
	_stack.push_front(ret);
}



void	Stack::sub(void) {
	if (_stack.size() < 2) {
		throw(Exception("Not enough elements in the stack to substract\n" ));
	}
	auto i = _stack.begin();
	auto j = i;
	j++;
	const IOperand *ret = *(*j) - *(*i);
	_stack.pop_front();
	_stack.pop_front();
	_stack.push_front(ret);
}
void	Stack::mul(void) {
	if (_stack.size() < 2) {
		throw(Exception("Not enough elements in the stack to multiply\n" ));
	}
	auto i = _stack.begin();
	auto j = i;
	j++;
	const IOperand *ret = *(*i) * *(*j);
	_stack.pop_front();
	_stack.pop_front();
	_stack.push_front(ret);
}
void	Stack::div(void) {
	if (_stack.size() < 2) {
		throw(Exception("Not enough elements in the stack to divide\n" ));
	}
	auto i = _stack.begin();
	auto j = i;
	j++;
	const IOperand *ret = *(*j) / *(*i);
	_stack.pop_front();
	_stack.pop_front();
	_stack.push_front(ret);
}
void	Stack::mod(void) {
	if (_stack.size() < 2) {
		throw(Exception("Not enough elements in the stack to modulus\n" ));
	}
	auto i = _stack.begin();
	auto j = i;
	j++;
	const IOperand *ret = *(*j) % *(*i);
	_stack.pop_front();
	_stack.pop_front();
	_stack.push_front(ret);
}
void	Stack::pop(void) {
	if (_stack.size() < 1) {
		throw(Exception("Not enough elements in the stack to pop\n" ));
	}
	_stack.pop_front();
}
void	Stack::dump(void) {
	for (auto i = _stack.begin(); i != _stack.end(); i++) {
		std::cout << (*i)->getValue() << std::endl;
	}
}
void	Stack::print(void) {
	if (_stack.size() == 0) {
		throw (Exception("empty stack"));
	}
	if (_stack.front()->getValue() < 0) {
		throw (Exception("Error while converting value to char"));
	}
		if (floor(_stack.front()->getValue()) != _stack.front()->getValue()) {
		throw (Exception("Error while converting value to char"));
		}
	int8_t t;
	try { t = boost::numeric_cast<int8_t>(_stack.front()->getValue());
	}
	catch (const std::exception & e) {
		throw (Exception("Error while converting value to char"));
	}
	std::cout << t << std::endl;
}
