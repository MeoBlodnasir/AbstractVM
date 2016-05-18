#include "Exception.hpp"

Exception::Exception(std::string const &msg) throw()
{
  this->_msg = msg;
}

Exception::~Exception() throw()
{

}

const char	*Exception::what() const throw()
{
  return (this->_msg.c_str());
}

Exception& Exception::operator=(const Exception& rhs) {
	(void)rhs;
	return *this;
}
