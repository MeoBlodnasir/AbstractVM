#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include <cfloat>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <boost/regex.hpp> 

std::list<IOperand*> stack;
Factory facto;


std::string get_value(std::string str) {
	std::string number;
	number = str.substr(str.find("(") + 1, str.find(")") - str.find("(") - 1);
	return number;
}

void	push_num(std::string str) {
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
			stack.push_front(facto.createOperand(iterator->first, get_value(str)));
			return ;
		}
	}
	throw(Exception("Invalid push command."));
}

void	assert_num(std::string str) {

}

void	handle_push_assert(std::vector<std::string> strs) {
	std::cout << strs[0] << std::endl;
	if (strs[0].compare("push") == 0) {
		push_num(strs[1]);
	} else if (strs[0].compare("assert") == 0) {
		assert_num(strs[1]);
	} else {
		throw(Exception("Invalid command: " + strs[0]));
	}	
}

void	handle_single(std::string msg) {

}

void	handle_instruction(std::string msg) {
	boost::trim(msg);
	std::vector<std::string> strs;
	boost::split(strs,msg,boost::is_any_of(" "));
	if (msg[0] == ';') {
		return ;
	} else if (strs.size() == 1) {
		handle_single(msg);
	} else if (strs.size() == 2) {
		handle_push_assert(strs);
	} else  {
		throw (Exception("Multiple spaces of more than 2 keywords" +  msg));
	}

}

int main(int ac, char **av) {
	std::cout << "AbstractVM" << std::endl;
	//try {
	if (ac == 1) {
		while (1) {
			std::string msg;
			getline(std::cin, msg);
			if (msg == "exit") {
				break ;
			}
			handle_instruction(msg);
		}
	}

	//	}

	/*	catch(Exception const &error) {
		std::cerr << "Good Error: " << error.what() << std::endl;

		} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		}*/
}
