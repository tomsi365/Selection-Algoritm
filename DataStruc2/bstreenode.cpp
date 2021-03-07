// methods for dynamic tree node.
#include <iostream>
#include "bstreenode.h"
#include "person.h"
using namespace std;

// constructor
BSTreeNode::BSTreeNode()
{
	left = right = nullptr;
	data = nullptr;
	leftSubSize = 0;
}

// constructor
BSTreeNode::BSTreeNode(KeyType key, Type* data, BSTreeNode* left, BSTreeNode* right)
{
	this->left = left;
	this->right = right;
	this->key = key;
	this->data = data;
	this->leftSubSize = 0;
}

// destructor
BSTreeNode::~BSTreeNode()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

// traverse the tree inorder
void BSTreeNode::Inorder(BSTreeNode* next)
{
	if (next->left == nullptr && next->right == nullptr)
		{
		cout << next->key << " ";
		return;
		}

	if (next->left != nullptr)
		Inorder(next->left);

	cout << next->key << " ";

	if (next->right != nullptr)
		Inorder(next->right);

}

// returns key of Node
int BSTreeNode::getKey() const 
{
	return key;
}

// returns Person
Type* BSTreeNode::getData()
{
	return this->data;
}