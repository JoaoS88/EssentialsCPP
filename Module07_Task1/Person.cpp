#include "Person.h"
#include <iostream>

Person::Person(std::string name, int age)
{
	m_name = name;
	m_age = age;
}

Person::Person()
{
	// Default
	m_name = "John Doe";
	m_age = 100;
}

Person::~Person()
{
	std::cout << "Object Destroyed!";
}

std::string Person::getName()
{
	return m_name;
}

int Person::getAge()
{
	return m_age;
}

void Person::setName(std::string name)
{
	m_name = name;
}

void Person::setAge(int age)
{
	m_age = age;
}
