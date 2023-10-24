#ifndef DIVIDEANDRULE_HPP
#define DIVIDEANDRULE_HPP

class FundsInsufficient : public std::exception {
	public:
    		FundsInsufficient(const std::string& msg) throw() : message(msg) {}
    		virtual ~FundsInsufficient() throw() {}

    		const char* what() const throw() { return message.c_str(); }

	private:
    	std::string message;
};

struct Bank
{
	struct Account
	{
		friend struct Bank;

		private:
			const int id;
			int value;

			Account() : id(-1), value(0) {}
			Account(int _id): id(_id), value(0) {}

			friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
			{
				p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
				return (p_os);
			}

			void setValue(int _value)
			{
				if (_value < 0)
					throw std::invalid_argument("Account value cannot be negative");
				this->value = _value;
			};

		public:
			int getId() const { return this->id; };
			int getValue() const { return this->value; };	
	};

	private: 
		int liquidity;
		std::map<int, Account *> clientAccounts;
		unsigned int nextId;

		bool isIdValid(int id)
		{
			if (this->clientAccounts.find(id) == this->clientAccounts.end())
				return false;
			return true;
		}


	public:
		Bank() : liquidity(0), nextId(0) {}

		int	createAccount()
		{
			Account	*tmp = new Account(nextId);
			clientAccounts[nextId] = tmp;
			nextId++;	
			return nextId - 1;	
		}	

		int getLiquidity () const { return this->liquidity; };
		std::map<int, Account*> getClientAccounts () const { return this->clientAccounts; };
		const Account *getAccount(int id) const { return clientAccounts.at(id); };
		int getValueAccount (int id) const { return (clientAccounts.at(id))->value; };


		void deleteAccount(int id)
		{
			if (!this->isIdValid(id))
				throw std::invalid_argument("This id does not exist");
			clientAccounts.erase(id);
			std::cout <<  "The account " << id << " has been deleted." << std::endl;
		}
	

		void addMoney(int id, int amount)
		{
			try { 
				Account *tmp = clientAccounts.at(id);

				tmp->setValue(tmp->getValue() + amount);
				this->liquidity += amount * 0.05;
		
				std::cout << amount << " has been add to the account " << id << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				throw std::invalid_argument("This id does not exist");
			}
		}

		void getMoney(int id, int amount)
		{
			try
			{
				Account *tmp = clientAccounts.at(id);

				if (amount > tmp->value)
					throw FundsInsufficient("You do not have enough liquidity");
				tmp->setValue(tmp->getValue() - amount);
				std::cout << amount << " has been withdraw to the account " << id << std::endl;
			}
			catch(const std::exception& e)
			{
				throw std::invalid_argument("This id does not exist");
			}
		}

		void getLoan(int id, int amount)
		{
			Account* tmp = clientAccounts.at(id);
		
			if (amount > this->liquidity)
				throw FundsInsufficient("The bank cannot loan you this amount of money");
			
			tmp->setValue(tmp->getValue() + amount);
			this->liquidity -= amount;
			std::cout << amount << " has been loan to the account " << id << std::endl;
		}

		Bank::Account &operator [] (int id)
		{
			try
			{
				clientAccounts.at(id);
				return *(this->clientAccounts.at(id));
			}
			catch (const std::exception& e)
			{
				throw std::invalid_argument("This id does not exist");
			}
		}
	
	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	{
		std::map<int, Bank::Account*>::const_iterator it;
			
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (it = p_bank.clientAccounts.begin(); it!= p_bank.clientAccounts.end(); it++)
			p_os << it->second << std::endl;
		return (p_os);
	}
};

#endif
