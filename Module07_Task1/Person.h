#pragma once
#include <iostream>

class Person
{
	
	private: 
		//member Variables
		std::string m_name;
		int m_age;

	public: 
		// member Functions
		Person(std::string name, int age); // Parameterised Constructor

		Person();						   // Default Constructor

		~Person();						   // Default Destructor

		// getters:
		std::string getName();					   // get the name of object
		int getAge();					   // get the age of object

		// setters:
		void setName(std::string m_name);    // set name of object
		void setAge(int m_age);			   // set age of object

};