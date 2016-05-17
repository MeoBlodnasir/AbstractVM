#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include <cfloat>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <boost/regex.hpp> 
#include "Stack.hpp" 


void	handle_push_assert(const std::vector<std::string> &strs, Stack &stack) {
	std::cout << strs[0] << std::endl;
	if (strs[0].compare("push") == 0) {
		stack.push(strs[1]);
	} else if (strs[0].compare("assert") == 0) {
		stack.ass(strs[1]);
	} else {
		throw(Exception("Invalid command: " + strs[0]));
	}	
}

void	handle_single(const std::string &msg, Stack &stack) {

}

void	handle_instruction(const std::string &msg, Stack &stack) {
	boost::trim(msg);
	std::vector<std::string> strs;
	boost::split(strs,msg,boost::is_any_of(" "));
	if (msg[0] == ';') {
		return ;
	} else if (strs.size() == 1) {
		handle_single(msg, stack);
	} else if (strs.size() == 2) {
		handle_push_assert(strs, stack);
	} else  {
		throw (Exception("Multiple spaces of more than 2 keywords" +  msg));
	}

}

int main(int ac, char **av) {
	Stack stack;
	std::cout << "AbstractVM" << std::endl;
	try {
		if (ac == 1) {
			while (1) {
				std::string msg;
				getline(std::cin, msg);
				if (msg == "exit") {
					break ;
				}
				handle_instruction(msg, stack);
			}
		}

	}

	catch(Exception const &error) {
		std::cerr << "Caught error: " << error.what() << std::endl;

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
