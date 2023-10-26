#include "ex00.hpp"

int main()
{
	Worker	*workerA = new Worker();
	Worker	*workerB = new Worker();
	Shovel	*shovel = new Shovel();
	Hammer	*hammer = new Hammer();
	Workshop	*workshopA = new Workshop();
	Workshop	*workshopB = new Workshop();
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

	std::cout << "Register to workershops" << std::endl;
	workerA->registerToWorkshop(workshopA);
	workerA->registerToWorkshop(workshopB);
	workerB->registerToWorkshop(workshopA);
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Leave a workshop" << std::endl;
	workerA->leaveWorkshop(workshopA);
	workerA->leaveWorkshop(workshopB);


	std::cout << "Delete the owner of a shovel (the shovel will not be deleted)" << std::endl;
	delete workerB; 
	std::cout << "-----" << std::endl << std::endl;
}
