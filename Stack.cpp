#include "Stack.hpp"
#include "Exception.hpp"
#include <boost/regex.hpp> 

Stack::Stack() {
}

std::string get_value(std::string str) {
	std::string number;
	number = str.substr(str.find("(") + 1, str.find(")") - str.find("(") - 1);
	return number;
}
void	Stack::push(const std::string& str) {

	long double val;
	std::map<eOperandType, boost::regex> tab = {
		{INT8, 	boost::regex("^Int8\\(\\d+(\\.\\d+)?\\)$")}, 
		{INT16, 	boost::regex("^Int16\\(\\d+(\\.\\d+)?\\)$")}, 
		{INT32, 	boost::regex("^Int32\\(\\d+(\\.\\d+)?\\)$")}, 
		{FLOAT, 	boost::regex("^Float\\(\\d+(\\.\\d+)?\\)$")}, 
		{DOUBLE, 	boost::regex("^Double\\(\\d+(\\.\\d+)?\\)$")}, 
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
		throw(Exception("Not enough elements in the stack\n" ));
	}


}
