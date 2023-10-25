#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "ex00.hpp"
class Tool;

class Hammer: public Tool
{
	private:
		int _numberOfUses;

	public:
		Hammer(): _numberOfUses(0) { VERBOSE };
		~Hammer() { VERBOSE };

		void use() { VERBOSE };
};

#endif

