#include "person.h"
#include <iostream>
//personªº¨ç¦¡

person::person(char const* nm, int ae)
{
	char* temp = new char[strlen(nm) + 1]();
	for (int i = 0; i < strlen(nm); i++)
		temp[i] = nm[i];
	if (name != nullptr)
		delete[] name;
	name = temp;
	age = ae;
}

// copy constructor
person::person(person& m)
{
	char* temp = new char[strlen(m.name) + 1]();
	for (int i = 0; i < strlen(m.name); i++)
		temp[i] = m.name[i];
	if (name != nullptr)
		delete[] name;
	name = temp;
	age = m.age;
}

// destructor
person::~person()
{
	if (name != nullptr)
		delete[] name;
}

// assignment operator
person& person::operator=(person& m)
{
	char* temp = new char[strlen(m.name) + 1]();
	for (int i = 0; i < strlen(m.name); i++)
		temp[i] = m.name[i];
	if (name != nullptr)
		delete[] name;
	name = temp;
	age = m.age;
	return *this;
}

// member functions
void person::setName(char const* nm)
{
	char* temp = new char[strlen(nm) + 1]();
	for (int i = 0; i < strlen(nm); i++)
		temp[i] = nm[i];
	if (name != nullptr)
		delete[] name;
	name = temp;
}

void person::setAge(int ae)
{
	age = ae;
}

string person::getName()
{
	if (name != nullptr)
		return name;
}

int person::getAge()
{
	return age;
}
