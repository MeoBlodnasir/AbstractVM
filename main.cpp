#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include <cfloat>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <boost/regex.hpp> 

std::list<IOperand*> stack;

void	push_num(std::string str) {
	const boost::regex reg("^Int8\\(\\d+(\\.\\d+)?\\)$");
	boost::cmatch what;
	if (boost::regex_match(str.c_str(), what, reg)) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "NOT OK" << std::endl;
	}
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
