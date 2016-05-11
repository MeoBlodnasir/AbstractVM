#include "Int8.hpp"
#include "Int32.hpp"
#include "Int16.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Exception.hpp"
#include <cfloat>

int main() {
	try {
	Factory *f = new Factory();
	Int8 *i = (Int8 *)f->createOperand(INT8, "3");
	Int8 *v = (Int8 *)f->createOperand(INT8, "4");
	Int8 *res = (Int8 *)(*i + *v);
	std::cout << i->getValue() << std::endl;
	std::cout << v->getValue() << std::endl;
	std::cout << res->getValue() << std::endl;
	}
	catch(Exception const &error) {
			std::cerr << "Error : " << error.what() << std::endl;

	} catch (const std::exception& e) {
			std::cerr << "Another Error : " << e.what() << std::endl;
	}
}
