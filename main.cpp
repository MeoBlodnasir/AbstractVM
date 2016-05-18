#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include <cfloat>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <boost/regex.hpp> 
#include "Stack.hpp" 


void	handle_push_assert(const std::vector<std::string> &strs, Stack &stack) {
	if (strs[0].compare("push") == 0) {
		stack.push(strs[1]);
	} else if (strs[0].compare("assert") == 0) {
		stack.ass(strs[1]);
	} else {
		throw(Exception("Invalid command: " + strs[0]));
	}	
}

void	handle_instruction(std::string &msg, Stack &stack) {
	msg = msg.substr(0, msg.find(";") -1);
	std::vector<std::string> strs;
	boost::split(strs,msg,boost::is_any_of(" "));
	if (msg[0] == ';') {
		return ;
	} else if (strs.size() == 1) {
		stack.execute(msg);
	} else if (strs.size() == 2) {
		handle_push_assert(strs, stack);
	} else  {
		throw (Exception("Multiple spaces or more than 2 keywords" +  msg));
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
				boost::trim(msg);
				if (msg == "exit" || msg == ";;") {
					break ;
				}
				handle_instruction(msg, stack);
			}
		} else if (ac == 2) {
			std::ifstream file;
			std::string line;
			file.open(av[1]);
			if (file.is_open()) {
				while (getline(file, line)) {
					boost::trim(line);
					if (line == "exit") {
						file.close();
						return 0;
					}
					handle_instruction(line, stack);
				}
			} else {
				std::cout << "Unable to opem file" << std::endl;
			}
			throw(Exception("No exit instruction"));
		}

	}

	catch(Exception const &error) {
		std::cerr << "error: " << error.what() << std::endl;

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
