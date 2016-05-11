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
	Double *i = (Double *)f->createOperand(DOUBLE, "1.0e9999999");
	std::cout << i->getType() << std::endl;
	}
	catch(Exception const &error) {
			std::cerr << "Error : " << error.what() << std::endl;

	} catch (const std::exception& e) {
			std::cerr << "Another Error : " << e.what() << std::endl;
	}
}
