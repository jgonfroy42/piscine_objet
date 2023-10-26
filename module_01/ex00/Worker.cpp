#include "ex00.hpp"

	Worker::~Worker()
{ VERBOSE

/*segfault
	std::set<Tool*>::iterator it;
	for (it = this->_tools.begin(); it !=  this->_tools.end(); it++)
		(*it)->returnTool();

	std::set<Workshop*>::iterator it2;
	for (it2 = this->_workshops.begin(); it2 !=  this->_workshops.end(); it2++)
		this->leaveWorkshop(*it2);
*/

	while (!this->_tools.empty())
		(*this->_tools.begin())->returnTool();
	while (!this->_workshops.empty())
		this->leaveWorkshop(*this->_workshops.begin());
}


void	Worker::work()
{ VERBOSE
	std::set<Tool*>::iterator it;
	for (it = this->_tools.begin(); it !=  this->_tools.end(); it++)
		(*it)->use();
}
