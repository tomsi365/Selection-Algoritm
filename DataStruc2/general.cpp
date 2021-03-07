#pragma warning(disable:4996)
#include "general.h"
#include "person.h"
#include <string.h>
#include <iostream>
using namespace std;

//returns String from the keyboard .
char* General::getString()
{
	char ch;
	ch = cin.get();

	if (ch == '\n')
		ch = cin.get();

	char* str = nullptr;
	int logical_size = 0;
	int physical_size = 0;
	while (ch != '\n')
	{
		logical_size++;
		if (str == nullptr)
		{
			str = new char[2];
			str[0] = ch;
			str[1] = '\0';
			physical_size = 2;
			logical_size++;
		}
		else
		{
			if (logical_size > physical_size)
			{
				physical_size *= 2;
				char* new_str = new char[physical_size];
				strcpy(new_str, str);
				delete[] str;
				str = new_str;
			}
		}
		str[logical_size - 2] = ch;
		str[logical_size - 1] = '\0';
		ch = cin.get();
	}
	return str;
}

//swaps Person pointers at array .
void General::swapPersons(Person persons[], int a, int b)
{
	Person temp;
	temp = persons[a];
	persons[a] = persons[b];
	persons[b] = temp;
}

//prints error and exits program
void General::error(const char* str)
{
	cout <<str<<endl;
	exit(1);
}

//returns copy of persons array .
Person* General::copyPersons(Person persons[], int n) 
{
	Person* new_persons = new Person[n];
	for (int i = 0;i < n;i++) 
	{
		new_persons[i] = persons[i];
	}
	return new_persons;
}