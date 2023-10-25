#include "ex00.hpp"

int main()
{
	Worker *workerA = new Worker();
	Worker *workerB = new Worker();
	Shovel *shovel = new Shovel();
	shovel->use();
	Hammer	*hammer = new Hammer();
	hammer->use();
	std::cout << "-----" << std::endl << std::endl;

	
	std::cout << "Give a shovel without owner" << std::endl;
	shovel->giveTool(workerA);
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Give a shovel to a worker with a owner" << std::endl;
	shovel->giveTool(workerB);
	std::cout << "-----" << std::endl << std::endl;
	
	std::cout << "Give a hammer to an owner with others tools" << std::endl;
	hammer->giveTool(workerB);
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Take back a hammer" << std::endl;
	shovel->returnTool();
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Delete the owner of a shovel (the shovel will not be deleted)" << std::endl;
	delete workerB; 
	std::cout << "-----" << std::endl << std::endl;
}
