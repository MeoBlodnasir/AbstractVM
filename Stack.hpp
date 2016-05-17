#include <iostream>
#include <list>
#include "IOperand.hpp"
#include "Factory.hpp"

class Stack {
	private:
		std::list<IOperand*> _stack;
		Factory _facto;
	public:
		Stack();
		~Stack() {};
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
