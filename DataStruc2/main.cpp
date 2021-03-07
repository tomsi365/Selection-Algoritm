#pragma warning(disable:4996)
#include <iostream>
#include <time.h>
#include "person.h"
#include "general.h"
#include "bstreenode.h"
#include "bstree.h"
#include "heap.h"
using namespace std;

int Selection(Person persons[], int left, int right, int k, int &NumComp);
const Person& RandSelection(Person persons[], int n, int k, int &NumComp);
const Person& BST(Person persons[],  int n, int k, int& NumComp);
int Partition(Person persons[], int left, int right, int &NumComp);
const Person& selectHeap(Person persons[], int n, int k, int &NumComp);

void f1();
void f2();
void f3();
int main_final();

int main()
{
	main_final();
	system("pause");
	return 0;
}

// final main to be implemented instead of main
int main_final()
{
	srand((unsigned)time(nullptr));

	int num, kSelection, numComp=0;
	cin >> num;
	Person* persons = Person::createPersonArray(num);
	Person* persons_1 = General::copyPersons(persons, num);
	Person* persons_2 = General::copyPersons(persons, num);
	cin >> kSelection;
	Person A;
	
	A = RandSelection(persons, num, kSelection, numComp);
	cout << "\n" << A.getId() << " " << A.getName() << "\n\n"
		<< "Rand Selection: " << numComp << "\n\n";
	
	A = selectHeap(persons_1, num, kSelection, numComp);
	//cout << "\n" << A.getId() << " " << A.getName() << "\n\n";
	cout << "selectHeap: " << numComp << "\n\n";
	
	A = BST(persons_2, num, kSelection, numComp);
	//cout << "\n" << A.getId() << " " << A.getName() << "\n\n";
	cout << "BST: " << numComp << "\n\n";

	delete[] persons;
	delete[] persons_1;
	delete[] persons_2;

	system("pause");
	return 0;
}

//test .
void f3() 
{
	Person persons[15];
	persons[0] = Person("vweuv", 1);
	persons[1] = Person("vwesdcuv", 100);
	persons[2] = Person("vwasateuv", 2);
	persons[3] = Person("vweyyruv", 99);
	persons[4] = Person("vweuqesxsxv", 3);
	persons[5] = Person("vweuqesxsxv", 98);
	persons[6] = Person("vweuqesxsxv", 4);
	persons[7] = Person("vweyyruv", 97);
	persons[8] = Person("vweyyruv", 5);
	persons[9] = Person("vweyyruv", 96);
	persons[10] = Person("vweyyruv", 6);
	persons[11] = Person("vweyyruv", 95);
	persons[12] = Person("vweyyruv", 7);
	persons[13] = Person("vweyyruv", 94);
	persons[14] = Person("vweyyruv", 8);
	MinimumHeap* h = new MinimumHeap(persons, 15);
	h->printHeap();

	Person p=h->DeleteMin();
	cout << p.getId() << " " << p.getName() << endl;
	h->printHeap();

	p = h->DeleteMin();
	cout << p.getId() << " " << p.getName() << endl;
	h->printHeap();

	delete h;

	h = new MinimumHeap(5);
	h->insert(persons[0]);
	h->insert(persons[1]);
	h->insert(persons[2]);
	h->insert(persons[3]);
	h->insert(persons[4]);
	h->printHeap();

	p = h->DeleteMin();
	cout << p.getId() << " " << p.getName() << endl;
	h->printHeap();

	delete h;

	
}

//test .
void f2() 
{
	Person persons[3];
	persons[0] =Person("vweuv", 88);
	persons[1] =Person("vwesdcuv", 56);
	persons[2] =Person("vwasateuv", 126);

	Person::initCompares();

	cout << (persons[0] > persons[1]) << endl;
	cout << (persons[1] > persons[2]) << endl;
	cout << Person::getCompares() << endl;
}

//test .
void f1() 
{
	int n = 5;

	for (int i = 0;i < 100;i++)
	{
		Person persons[15];
		persons[0] = Person("vweuv", 1);
		persons[1] = Person("vwesdcuv", 100);
		persons[2] = Person("vwasateuv", 2);
		persons[3] = Person("vweyyruv", 99);
		persons[4] = Person("vweuqesxsxv", 3);
		persons[5] = Person("vweuqesxsxv", 98);
		persons[6] = Person("vweuqesxsxv", 4);
		persons[7] = Person("vweyyruv", 97);
		persons[8] = Person("vweyyruv", 5);
		persons[9] = Person("vweyyruv", 96);
		persons[10] = Person("vweyyruv", 6);
		persons[11] = Person("vweyyruv", 95);
		persons[12] = Person("vweyyruv", 7);
		persons[13] = Person("vweyyruv", 94);
		persons[14] = Person("vweyyruv", 8);
		int x = 0;
		Person p = RandSelection(persons, 15, 10, x);
		cout << p.getId() << " " << p.getName() << " " << x << endl;
	}
}

//[Function 1] returns the k-value item at array .
const Person& RandSelection(Person persons[], int n, int k, int &NumComp)
{
	Person::initCompares();
	int index = Selection(persons, 0, n - 1, k - 1, NumComp);
	NumComp = Person::getCompares();
	return persons[index];
}

//[Function 2] returns the k-value item at array .
const Person& selectHeap(Person persons[], int n, int k, int &NumComp)
{
	Person::initCompares();
	MinimumHeap heap = MinimumHeap(persons, n);

	for (int i = 1;i <= k-1;i++)
	{
		heap.DeleteMin();
	}
	NumComp = Person::getCompares();
	return heap.Min();
}

//[Function 3] returns the k-value item at array .
const Person& BST(Person persons[], int n, int k, int& NumComp)
{
	Person::initCompares();
	BStree* T = new BStree(); // build binary search tree
	T->makeEmpty();
	for (int i = 0; i < n; i++)
	{
		T->Insert(persons[i].getId(), &persons[i]);
	}
	NumComp = T->getNumComp();
	BSTreeNode* kValueNode = T->FindKValue(k);
	Person* kValue = kValueNode->getData();
	delete T; // free binary search tree
	return *kValue;
}

//Selection algoritm , recursive function , returns the k-value item at array .
int Selection(Person persons[], int left, int right, int k, int &NumComp)
{
	int pivot = Partition(persons, left, right, NumComp);
	if (k == pivot)
	{
		return pivot;
	}
	else
	{
		if (k > pivot)
		{
			return Selection(persons, pivot + 1, right, k, NumComp);
		}
		else
		{
			return Selection(persons, left, pivot - 1, k, NumComp);
		}
	}

}

//Partition algoritm , returns random pivot index .
int Partition(Person persons[], int left, int right, int &NumComp)
{
	int pivot = left + (rand() % (right - left + 1));
	General::swapPersons(persons, left, pivot);
	bool flag = true;
	while (left != right)
	{
		if (flag)
		{
			if (persons[left] > persons[right]) 
			{
				General::swapPersons(persons, left, right);
				left++;
				flag = !flag;
			}
			else
			{
				right--;
			}
		}
		else
		{
			if (persons[left] > persons[right]) 
			{
				General::swapPersons(persons, left, right);
				right--;
				flag = !flag;
			}
			else
			{
				left++;
			}
		}

	}
	return left;
}

