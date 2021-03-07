#ifndef __PERSON_H
#define __PERSON_H

class Person
{
private:
	const char* name;
	int id;
	static int compares;
public:
	Person(const char* name, int id);
	Person();
	~Person();
	Person(const Person &other);
	int getId() const;
	const char* getName() const;
	const Person& operator=(const Person& other);
	static void initCompares();
	static int getCompares();
	bool operator< (const Person& other) const;
	bool operator> (const Person& other) const;
	bool operator>= (const Person& other) const;
	bool operator<= (const Person& other) const;
	static Person* createPersonArray(int num); 
};

#endif // !__PERSON_H

