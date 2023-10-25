#include "ex00.hpp"

int main()
{
	Worker *workerA = new Worker();
	Worker *workerB = new Worker();
	Shovel *shovel = new Shovel();
	shovel->use();
	std::cout << "-----" << std::endl << std::endl;

	
	std::cout << "Give a shovel without owner" << std::endl;
	shovel->giveTool(workerA);
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Give a shovel to a worker with a owner" << std::endl;
	shovel->giveTool(workerB);
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Delete the owner of a shovel" << std::endl;
	delete workerB; 
	std::cout << "-----" << std::endl << std::endl;
}
