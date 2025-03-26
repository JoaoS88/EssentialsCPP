#include <iostream>
#include "Position.h"

int main()
{
	// create and set objects P1 and P2
	Position P1(1, 1), P2(2, 2);

	// output values of objects P1 and P2 
	std::cout << "P1: ";
	P1.outputPosition();
	std::cout << std::endl;
	std::cout << "P2: ";
	P2.outputPosition();
	std::cout << std::endl;

	// test overloaded + operator
	std::cout << "Testing overloaded + operator:" << std::endl;
	Position Result = P1 + P2;
	std::cout << "P1 + P2 = ";
	Result.outputPosition();
	std::cout << std::endl;

	// test overloaded = operator
	Position P3(0, 0), P4(10, 10);
	std::cout << std::endl;
	std::cout << "Testing overloaded = operator:" << std::endl;
	std::cout << "P3: ";
	P3.outputPosition();
	std::cout << std::endl;
	std::cout << "P4: ";
	P4.outputPosition();
	std::cout << std::endl;
	std::cout << "Making P3 = P4..." << std::endl;
	P3 = P4;
	std::cout << "P3 Result: ";
	P3.outputPosition();
	std::cout << " ; P3 Expected Result: ";
	P4.outputPosition();
	std::cout << std::endl;



	return 0;
}