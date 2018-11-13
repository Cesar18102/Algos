#include "BinaryTree.h"

TNode::TNode(int item)				
{
	data = item;				
    left = NULL;
	right = NULL;			
	height = 1;
}

TNode::TNode()
{
	data = 0;
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
	std::cout << p->data << ", ";
	preorder_rec(p->left);
	preorder_rec(p->right);
}

void BinaryTree::preorder()
{
	if(root == NULL)
		std::cout << "Tree is empty. Preorder sequence is empty." << std::endl;
	else
	{
		std::cout << "Preorder sequence: "; 
		preorder_rec(root);
		std::cout << std::endl;
	}
}

void BinaryTree::inorder_rec(TNode *p)
{
	if(p == NULL)
		return;
	inorder_rec(p->left);
	std::cout << p->data << ", ";
	inorder_rec(p->right);
}

void BinaryTree::inorder()
{
	if(root == NULL)
		std::cout << "Tree is empty. Inorder sequence is empty." << std::endl;
	else
	{
		std::cout << "Inorder sequence: "; 
		inorder_rec(root);
		std::cout << std::endl;
	}
}

void BinaryTree::back_inorder_rec(TNode *p)
{
	if(p == NULL)
		return;
	back_inorder_rec(p->right);
	std::cout << p->data << ", ";
	back_inorder_rec(p->left);
}

void BinaryTree::back_inorder()
{
	if(root == NULL)
		std::cout << "Tree is empty. Back inorder sequence is empty." << std::endl;
	else
	{
		std::cout << "Back inorder sequence: "; 
		back_inorder_rec(root);
		std::cout << std::endl;
	}
}

void BinaryTree::postorder_rec(TNode *p)
{
	if(p == NULL)
		return;
	postorder_rec(p->left);
	postorder_rec(p->right);
	std::cout << p->data << ", ";
}

void BinaryTree::postorder()
{
	if(root == NULL)
		std::cout << "Tree is empty. Postorder sequence is empty." << std::endl;
	else
	{
		std::cout << "Postorder sequence: "; 
		postorder_rec(root);
		std::cout << std::endl;
	}
}
