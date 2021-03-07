#ifndef __GENERAL_H
#define __GENERAL_H
class Person;

class General 
{
public :
	static char* getString();
	static void error(const char* str);
	static void swapPersons(Person persons[], int a, int b);
	static Person* copyPersons(Person persons[], int n);
};

class BSTreeNode;
class BStree;
class Person;

typedef Person Type;
typedef int KeyType;




#endif