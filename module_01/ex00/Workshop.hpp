#ifndef Workshop_HPP
#define Workshop_HPP

#include "ex00.hpp"

class Worker;

class Workshop
{
	friend class Worker;

	public:
		Workshop() { VERBOSE };
		~Workshop(); 
		
		void executeWorkDay();

	private:
		std::set<Worker *> _workers;

		void addWorker(Worker *worker)
		{ VERBOSE
			this->_workers.insert(worker);
		};
		
		void removeWorker(Worker *worker)
		{ VERBOSE
			this->_workers.erase(worker);
		};

};

#endif

