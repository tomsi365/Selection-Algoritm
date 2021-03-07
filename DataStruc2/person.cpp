#pragma warning(disable:4996)
#include "person.h"
#include <string.h>
#include <iostream>
#include "general.h"
using namespace std;

int Person::compares = 0;

//Constructor .
Person::Person(const char* name, int id) : name(strdup(name)), id(id){}
//Constructor .
Person::Person() : name(nullptr), id(0) {}

//Copy Constructor
Person::Person(const Person& other) : id(other.id), name(strdup(other.name)) {}

//Destructor .
Person::~Person() 
{
	if (name != nullptr)
	{
		delete[] name;
	}
	//cout << id << " " << "deleted" << endl;//temp;
}

//returns Person's id .
int Person::getId() const
{
	return id;
}

//returns Person's name .
const char* Person::getName() const
{
	return name;
}

//placement operator .
const Person& Person::operator=(const Person& other) 
{
	if (this != &other) 
	{
		id = other.id;
		if(!name)
			delete[] name;
		name = strdup(other.name);
	}
	return *this;
}

//initializes num of compares that have been done between every Person object .
void Person::initCompares() 
{
	Person::compares = 0;
}

//return num of compares that have been done between every Person object .
int Person::getCompares() 
{
	return Person::compares;
}

//is small operator .
bool Person::operator<(const Person& other) const
{
	Person::compares++;
	return this->id < other.id;
}

//is big operator .
bool Person::operator>(const Person& other) const
{
	Person::compares++;
	return this->id > other.id;
}

//is big or equal
bool Person::operator>=(const Person& other) const
{
	Person::compares++;
	return this->id >= other.id;
}

//is small or equal
bool Person::operator<=(const Person& other) const
{
	Person::compares++;
	return this->id <= other.id;
}

// builds persons array from input
Person* Person::createPersonArray(int num)
{
	int i;
	char* temp;
	char** strArray = new char*[num];
	int* strNumArray = new int[num];
	Person* persons = new Person[num];
	for (i = 0; i < num; i++)
	{
		strArray[i] = General::getString();

		temp = strtok(strArray[i], " ");
		strNumArray[i] = atoi(temp);
		temp = strtok(NULL, "");
		persons[i] = Person(temp, strNumArray[i]);
	}
	delete strNumArray;
	for (i = 0; i < num; i++)
	{
		delete[] strArray[i];
	}
	delete strArray;

	return persons;
}