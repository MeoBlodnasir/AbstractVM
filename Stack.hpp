#ifndef STACK_HPP_
# define STACK_HPP_
#include <iostream>
#include <list>
#include "IOperand.hpp"
#include "Factory.hpp"

class Stack {
	private:
		std::list<const IOperand*> _stack;
		Factory _facto;
		std::map<std::string, void (Stack::*)()> _tab;
	public:
		void execute(const std::string& value);
		Stack();
		Stack(const Stack & src);
		Stack & operator=(const Stack & rhs);
		virtual ~Stack();
		void	push(const std::string&);
		void	ass(const std::string&);
		void 	add(void);
		void 	sub(void);
		void 	mul(void);
		void 	div(void);
		void 	mod(void);
		void 	pop(void);
		void 	dump(void);
		void 	print(void);

};

#endif
