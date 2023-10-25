#ifndef WORKER_HPP
#define WORKER_HPP

#include "ex00.hpp"

class Tool;

class Worker
{
	friend class Tool;

	private:
		Position coordonnee;
		Statistic stat;
		std::set<Tool*>	_tools;

	
		void addTool(Tool *tool) { VERBOSE this->_tools.insert(tool); };
		void removeTool(Tool *tool) { VERBOSE this->_tools.erase(tool); };

	public:	
		Worker() { VERBOSE };
		~Worker() { VERBOSE };

		returnTool(Tool *tool)
		{ VERBOSE
			if (!this->_tools.erase(tool))
				throw //texiste pas frere
		}
		
};

#endif
