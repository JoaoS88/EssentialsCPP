#pragma once
#include <iostream>

// class bank account responsible for objects with account numer and a balance
class BankAccount
{
	private:

		std::string m_accountNumber;
		double m_balance;

	public:

		BankAccount();
		BankAccount(std::string accountNumber, double balance);

		~BankAccount();

		std::string getAccountNumber();
		double getBalance();

};