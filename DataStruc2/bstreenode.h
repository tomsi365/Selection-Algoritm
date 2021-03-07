#ifndef __TREENODE_H
#define __TREENODE_H

#include "general.h"

class BSTreeNode
{
private:
	KeyType key;
	Type* data;
	BSTreeNode *left, *right;
	int leftSubSize;
	// private methods
	void Inorder(BSTreeNode* next);
	int getKey() const;
public:
	BSTreeNode();
	BSTreeNode(KeyType key, Type* data, BSTreeNode*, BSTreeNode*);
	~BSTreeNode();
	Type* getData();
	friend class BStree;
};



#endif