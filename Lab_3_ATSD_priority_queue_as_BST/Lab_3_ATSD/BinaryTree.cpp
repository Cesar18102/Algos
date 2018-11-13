#include "BinaryTree.h"
#include "Item.h"

TNode::TNode(int data, int priority)				
{
	this->data = Item(data, priority);				
    left = NULL;
	right = NULL;			
	height = 1;
}

TNode::TNode()
{
	data = Item();
	left = NULL;
	right = NULL;
}

BinaryTree::BinaryTree(void)
{
	root = NULL;
}

bool BinaryTree::isEmpty()
{
	return root == NULL;
}

bool BinaryTree::isFull()
{
	return false;
}

void BinaryTree::preorder_rec(TNode *p)
{
	if(p == NULL)
		return;
	std::cout << "Value: " << p->data.Value << ", Priority: " << p->data.Priority << "\n";
	preorder_rec(p->left);
	preorder_rec(p->right);
}

void BinaryTree::preorder()
{
	if(root == NULL)
		std::cout << "Tree is empty. Preorder sequence is empty." << std::endl;
	else
	{
		std::cout << "Preorder sequence: \n"; 
		preorder_rec(root);
		std::cout << std::endl;
	}
}

void BinaryTree::inorder_rec(TNode *p)
{
	if(p == NULL)
		return;
	inorder_rec(p->left);
	std::cout << "Value: " << p->data.Value << ", Priority: " << p->data.Priority << "\n";
	inorder_rec(p->right);
}

void BinaryTree::inorder()
{
	if(root == NULL)
		std::cout << "Tree is empty. Inorder sequence is empty." << std::endl;
	else
	{
		std::cout << "Inorder sequence: \n"; 
		inorder_rec(root);
		std::cout << std::endl;
	}
}

void BinaryTree::postorder_rec(TNode *p)
{
	if(p == NULL)
		return;
	postorder_rec(p->left);
	postorder_rec(p->right);
	std::cout << "Value: " << p->data.Value << ", Priority: " << p->data.Priority << "\n";
}

void BinaryTree::postorder()
{
	if(root == NULL)
		std::cout << "Tree is empty. Postorder sequence is empty." << std::endl;
	else
	{
		std::cout << "Postorder sequence: \n"; 
		postorder_rec(root);
		std::cout << std::endl;
	}
}
