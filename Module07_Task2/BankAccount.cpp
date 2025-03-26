#include "BankAccount.h"

BankAccount::BankAccount()
{
	m_accountNumber = "123456789";
	m_balance = 11;
}

BankAccount::BankAccount(std::string accountNumber, double balance)
{
	m_accountNumber = accountNumber;
	m_balance = balance;
}

BankAccount::~BankAccount()
{
	std::cout << "The object was destroyed" << std::endl;
}

std::string BankAccount::getAccountNumber()
{
	return m_accountNumber;
}

double BankAccount::getBalance()
{
	return m_balance;
}
