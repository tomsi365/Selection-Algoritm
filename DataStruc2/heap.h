#ifndef __HEAP_H
#define __HEAP_H

class Person;

class MinimumHeap
{
private:
	Person* data;
	int maxSize;
	int heapSize;
	int allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	MinimumHeap(int max);
	MinimumHeap(Person A[], int n);
	~MinimumHeap();
	const Person& Min(void);
	Person DeleteMin(void);
	void insert(Person item);

	void printHeap();//temp

};
#endif