#include "ex00.hpp"

	Workshop::~Workshop()
{  VERBOSE
	while (!this->_workers.empty())	
		(*this->_workers.begin())->leaveWorkshop(this);
}

void	Workshop::executeWorkDay()
{ VERBOSE
	std::set<Worker*>::iterator it;
	for (it = this->_workers.begin(); it !=  this->_workers.end(); it++)
		(*it)->work();
}
