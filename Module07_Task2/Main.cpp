#include "BankAccount.h"
#include <iostream>

int main()
{
    // create bankaccount1 using pointer to point to location
    BankAccount* p_MyBankAccount = new BankAccount; 
    
    // set object name and age using user input 
    // using dereferencing operator "->"
   
    // output age and name using getter functions in class
    std::cout << "BankAccount 1: " << std::endl
        << "Account Number: " << p_MyBankAccount->getAccountNumber() << std::endl
        << "Account Balance: " << p_MyBankAccount->getBalance() << std::endl;

    // delete object of bankaccount1
    delete p_MyBankAccount;
   
    // create bankaccount2 using same pointer now we point to new object
    p_MyBankAccount = new BankAccount("987654321", 99);

    // output age and name using getter functions in class
    std::cout << "BankAccount 2: " << std::endl
        << "Account Number: " << p_MyBankAccount->getAccountNumber() << std::endl
        << "Account Balance: " << p_MyBankAccount->getBalance() << std::endl;
    
    // delete object of bankaccount2
    delete p_MyBankAccount;
    // null the pointer
    p_MyBankAccount = nullptr;
    
    return 0;
}