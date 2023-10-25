#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "ex00.hpp"
class Tool;

class Shovel: public Tool
{
	private:
		int _numberOfUses;

	public:
		Shovel(): _numberOfUses(0) { VERBOSE };
		~Shovel() { VERBOSE };

		void use()
		{ VERBOSE
			_numberofUses++;
			std::cout << "I am a dwarf and I'm digging a hole" << std::endl;
			std::cout << "Diggy diggy hole, diggy diggy hole" << std::endl;
		};
};

#endif

