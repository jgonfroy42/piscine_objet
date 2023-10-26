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
	hammer->returnTool();
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Register to workershops" << std::endl;
	workerA->registerToWorkshop(workshopA);
	workerA->registerToWorkshop(workshopB);
	workerB->registerToWorkshop(workshopA);
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Execute day work" << std::endl;
	workshopA->executeWorkDay();
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Leave a workshop" << std::endl;
	workerA->leaveWorkshop(workshopA);
	workerA->leaveWorkshop(workshopB);
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "User bad input" << std::endl;
	try {
		hammer->giveTool(NULL);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		workerA->leaveWorkshop(NULL);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Delete the owner of a tool (the tool will not be deleted)" << std::endl;
	delete workerB; 
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Delete a tool" << std::endl;
	delete shovel;
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Give a tool and delete it" << std::endl;
	hammer->giveTool(workerA);
	delete hammer;
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Delete a workshop without worker" << std::endl;
	delete workshopB;
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "Join a workshop and delete it" << std::endl;
	workerA->registerToWorkshop(workshopA);
	delete workshopA;
	std::cout << "-----" << std::endl << std::endl;


}
