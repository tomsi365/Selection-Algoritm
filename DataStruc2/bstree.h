#ifndef __BTREE_H
#define __BTREE_H

#include "general.h"

class BStree
{
private:
	BSTreeNode* root;
	int numComp;
public:
	BStree();
	~BStree();
	bool isEmpty() const;
	void Insert(KeyType k, Type* d);
	BSTreeNode* Find(KeyType k) const;
	void Delete(KeyType k); 
	void makeEmpty();
	void PrintTree() const;
	KeyType Max(BSTreeNode* root) const;
	BSTreeNode* FindParent(KeyType key) const;
	BSTreeNode* FindKValue(int kValue) const;
	int getNumComp() const;
};



#endif
