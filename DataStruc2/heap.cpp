#include "heap.h"
#include "person.h"
#include "general.h"
#include <iostream>
#include <math.h>
using namespace std;

//returns left child .
int MinimumHeap::Left(int node) 
{
	return ((2 * node) + 1);
}

//returns right child .
int MinimumHeap::Right(int node) 
{
	return ((2 * node) + 2);
}

//returns parent .
int MinimumHeap::Parent(int node) 
{
	return (node - 1) / 2;
}

//Fixes the heap that has node as root .
void MinimumHeap::FixHeap(int node) 
{
	int index;
	int left;
	int right;
	int min = node ;

	do 
	{
		index = min;
		left = Left(min);
		right = Right(min);
		
		if (left < heapSize)
		{
			if (data[left] < data[min])
			{
				min = left;
			}
		}
		if (right < heapSize)
		{
			if (data[right] < data[min])
			{
				min = right;
			}
		}

		General::swapPersons(data, index, min);
	} 
	while (index != min);

}

//Constructor .
MinimumHeap::MinimumHeap(int max) 
{
	data = new Person[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

//Constructor .
MinimumHeap::MinimumHeap(Person A[],int n)
{
	maxSize = n;
	heapSize = n;
	data = A;
	allocated = 0;
	for (int i = (n / 2) - 1;i >= 0;i--) 
	{
		FixHeap(i);
	}
}

//Destructor .
MinimumHeap::~MinimumHeap() 
{
	if (allocated == 1) 
	{
		delete[] data;
	}
	data = nullptr;
}

//inserts Person to the heap .
void MinimumHeap::insert(Person item) 
{
	if (heapSize == maxSize) 
	{
		General::error("Error : Heap is full");
	}
	int index = heapSize;
	data[index] = item;
	while( (index > 0) && (data[index] < data[Parent(index)]))
	{
		General::swapPersons(data, index, Parent(index));
		index = Parent(index);
	}
	heapSize++;
}

//returns and deletes minimal person .
Person MinimumHeap::DeleteMin(void)
{
	if (heapSize == 0)
	{
		General::error("Error : Heap is empty");
	}
	Person min = data[0];
	data[0] = data[heapSize - 1];
	heapSize--;
	FixHeap(0);
	return min;
}

//returns minimal person (by reference) .
const Person& MinimumHeap::Min(void)
{
	return data[0];
}

//temp
void MinimumHeap::printHeap() 
{
	int num = 1;
	int c = 1;
	for (int i = 0;i < heapSize;i++) 
	{
		
		cout << data[i].getId() << " " << data[i].getName() << "||";
		
		if ((i+1) == num)
		{
			cout << endl;
			//cout << num << endl;
			num =num+(pow(2,c));
			c++;
		}
		
		
	}
	cout << endl;
}
