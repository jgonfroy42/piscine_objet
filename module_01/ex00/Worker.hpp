#ifndef WORKER_HPP
#define WORKER_HPP

#include "ex00.hpp"

class Tool;
class Workshop;

class Worker
{
	friend class Tool;

	private:
		Position coordonnee;
		Statistic stat;
		std::set<Tool*>	_tools;
		std::set<Workshop*>	_workshops;

	
		void addTool(Tool *tool) { VERBOSE this->_tools.insert(tool); };
		void removeTool(Tool *tool)
		{ VERBOSE
			if (!this->_tools.erase(tool))
				throw std::invalid_argument ("This tool doesn't exist");
		};


	public:	
		Worker() { VERBOSE };
		~Worker() { VERBOSE };

		void registerToWorkshop(Workshop *workshop)
		{ VERBOSE
			if (!workshop)
				throw std::invalid_argument("This workshop is not valid");
			if (!(this->_workshops.insert(workshop)).second)
				throw std::invalid_argument("The worker already register to this workshop");
			workshop->addWorker(this);
		};
		
		void leaveWorshop(Workshop *workshop)
		{
			if (!this->_workshops.erase(workshop))
				throw std::invalid_argument ("This workshop does not exist");
			workshop->removeWorker(this);
		};

/*		void work()
		{ VERBOSE
			for (set<Tool*>::iterator it = this->_tools.begin(); it != this->_tools.end(); it++)
				*it->use();
		};
*/
};

#endif
