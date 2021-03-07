#include "bstree.h"
#include "bstreenode.h"
#include "person.h"
#include <iostream>

// constructor
BStree::BStree()
{
	root = nullptr;
	numComp = 0;
}

// destructor
BStree::~BStree()
{
	delete root;
	root = nullptr;
}

// insert Node into Tree
void BStree::Insert(KeyType k, Type* d)
{
	BSTreeNode* temp = root; // current node in tree
	BSTreeNode* parent = nullptr; // parent of temp
	BSTreeNode* newnode; // new allocated node

	while (temp != nullptr) // find parent of newnode
	{
		parent = temp;
		if (k < temp->key)
		{
			this->numComp++;
			temp->leftSubSize++; // add to left sub tree
			temp = temp->left;
		}
		else
		{
			this->numComp++;
			temp = temp->right;
		}
	}
	newnode = new BSTreeNode(k, d, nullptr, nullptr);
	if (parent == nullptr)
		root = newnode;
	else if (k < parent->key)
	{
		this->numComp++;
		parent->left = newnode; // insert as left child
	}
	else
	{
		this->numComp++;
		parent->right = newnode; // insert as right child
	}
}

// Delete node from BST
void BStree::Delete(KeyType k)
{
	BSTreeNode* temp = root; // current node in tree
	BSTreeNode* parent = nullptr; // parent of temp

	if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		return;
	}

	while (temp !=nullptr && temp->key != k) // find parent of deleted node
	{
		parent = temp;
		if (k < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	
	if (!temp) // not found 
		return;

	else // found node to delete
	{
		if (temp->left != nullptr && temp->right != nullptr) // two children
		{
			// find max 
			KeyType max = Max(temp->left); 
			BSTreeNode* tempHolder = Find(max);
			BSTreeNode* parentHolder = FindParent(tempHolder->key);
			BSTreeNode* tempParent = FindParent(temp->key);
			if (tempHolder->left != nullptr)
				parentHolder->right = tempHolder->left;

			if (tempParent->left == temp)
				tempParent->left = tempHolder;
			else if (tempParent->right == temp)
				tempParent->right = tempHolder;
			if(tempHolder != temp->left)
				tempHolder->left = temp->left;
			tempHolder->right = temp->right;
			temp->left = temp->right = nullptr;
			delete temp;

		}
		else if (temp->left == nullptr && temp->right == nullptr) // no children
		{
			if(parent->left == temp)
				parent->left = nullptr;
			else if(parent->right == temp)
				parent->right = nullptr;

			delete temp;
		}
		else // 1 child
		{
			BSTreeNode* tempChild;
			if (temp->left != nullptr) // left child
			{
				tempChild = temp->left;
				if(parent->left == temp)
					parent->left = tempChild;
				if(parent->right == temp)
					parent->right = tempChild;
			}
			else if (temp->right != nullptr) // right child
			{
				tempChild = temp->right;
				if (parent->left == temp)
					parent->left = tempChild;
				if (parent->right == temp)
					parent->right = tempChild;
			}
			temp->right = nullptr;
			temp->left = nullptr;
			delete temp;
		}
	}
}

// find node on BST
BSTreeNode* BStree::Find(KeyType k) const
{
	BSTreeNode* temp = root;
	while (temp != nullptr)
	{
		if (k == temp->key)
			return temp;
		else if (k < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return nullptr;
}

// make BST empty
void BStree::makeEmpty()
{
	if(root)
		delete this->root;
	root = nullptr;
	numComp = 0;
}

// check if BST is empty
bool BStree::isEmpty() const
{
	return (root == nullptr);
}

// traverse the tree inorder
void BStree::PrintTree() const 
{
	if (root)
		root->Inorder(root);
}

// find Max key in BS subTree
KeyType BStree::Max(BSTreeNode* root) const 
{
	KeyType A=0, B=0;
	if (root->left == nullptr && root->right == nullptr)
	{
		return root->key;
	}

	if (root->left != nullptr)
		A = Max(root->left);

	if (root->key > A)
		A = root->key;

	if (root->right != nullptr)
		B = Max(root->right);

	if (A > B)
		return A;
	else
		return B;

}

// find parent of a node by key
BSTreeNode* BStree::FindParent(KeyType key) const
{
	BSTreeNode* temp = root; // current node in tree
	BSTreeNode* parent = nullptr; // parent of temp

	while (temp != nullptr && temp->key != key) // find parent of node
	{
		parent = temp;
		if (key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if (!temp)
		return nullptr;

	return parent;
}


// find k Value in size on BST
BSTreeNode* BStree::FindKValue(int k) const
{
	BSTreeNode* temp = root;
	while (temp != nullptr)
	{
		if (k == temp->leftSubSize+1)
			return temp;
		else if (k <= temp->leftSubSize)
			temp = temp->left;
		else
		{
			k = k - (temp->leftSubSize + 1);
			temp = temp->right;
		}
	}
	return nullptr;
}

int BStree::getNumComp() const
{
	return this->numComp;
}