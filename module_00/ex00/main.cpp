#include "ex00.hpp"

int main()
{
	Bank bank = Bank();
	int my_id = bank.createAccount();

	std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
	std::cout << "Account value : " << bank.getValueAccount(my_id) << std::endl;

	std::cout << std::endl << "-----" << std::endl;

	bank.addMoney(my_id, 1000);
	std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
	std::cout << "Account value : " << bank.getValueAccount(my_id) << std::endl;
	
	std::cout << std::endl << "-----" << std::endl;

	bank.getMoney(my_id, 50);
	std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
	std::cout << "Account value : " << bank.getValueAccount(my_id) << std::endl;

	std::cout << std::endl << "-----" << std::endl;
	
	try {
		bank.getLoan(my_id, 40);
		std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
		std::cout << "Account value : " << bank.getValueAccount(my_id) << std::endl;

		std::cout << std::endl << "-----" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << std::endl << "-----" << std::endl;

	}

	try {
		bank.getLoan(my_id, 5000);
		std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
		std::cout << "Account value : " << bank.getValueAccount(my_id) << std::endl;
		std::cout << std::endl << "-----" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << std::endl << "-----" << std::endl;
	}

	try {
		std::cout << "Get account by id : " << bank[0] << std::endl;
		std::cout << std::endl << "-----" << std::endl;
	}	
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << std::endl << "-----" << std::endl;
	}

	try {
		std::cout << "Get account by id : " << bank[1] << std::endl;
		std::cout << std::endl << "-----" << std::endl;
	}	
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << std::endl << "-----" << std::endl;
	}

	try {
		bank.deleteAccount(0);
		std::cout << std::endl << "-----" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << std::endl << "-----" << std::endl;
	}

	try {
		bank.deleteAccount(0);
		std::cout << std::endl << "-----" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << std::endl << "-----" << std::endl;
}

	return (0);
}
