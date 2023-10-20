#include <iostream>
#include <vector>

struct Account
{
	private:
		int id;
		int value;


		Account() : id(-1), value(0) {}

		Account(int _id): id(_id), value(0) {}

		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
		{
			p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
			return (p_os);
		}
	
	public:
		void	incValue(int amount)
		{
			this->value += amount;
		}

		void decValue(int amount)
		{
			this->value -= amount;
		}

};

struct Bank
{
	private: 
		int liquidity;
		std::map<int, Account *> clientAccounts;
		unsigned int nextId = 0;

		Bank() : liquidity(0) {}

		int createAccount():
		{
			Account tmp = new Account(nextId);
			clientAccounts[nextId] = tmp;
			nextId++;	
			return nextId - 1;	
		}	

		void deleteAccount(int id)
		{
			clientAcccounts.erase(id);
		}

		void addMoney(int id, int amount)
		{
			Account* tmp = clientAccounts[id];
			
			tmp->incValue(amount);
			this->liquidity += amount * 0.05;
		}

		void getMoney(int id, int amount)
		{
			Account* tmp = clientAccounts[id];
			
			tmp->decValue(amount);
		}

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
		{
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank.liquidity << std::endl;
			for (auto &clientAccount : p_bank.clientAccounts)
				p_os << *clientAccount << std::endl;
			return (p_os);
		}
};

int main()
{
	Account accountA = Account();
	accountA.id = 0;
	accountA.value = 100;

	Account accountB = Account();
	accountB.id = 1;
	accountB.value = 100;

	Bank bank = Bank();
	bank.liquidity = 999;
	bank.clientAccounts.push_back(&accountA);
	bank.clientAccounts.push_back(&accountB);

	bank.liquidity -= 200;
	accountA.value += 400;

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
