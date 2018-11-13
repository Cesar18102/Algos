#include "BinarySearchTree.h"

bool BinarySearchTree::search_rec(int item, TNode *p)
{
	if(p == NULL)
		return false;
	if(p->data == item)
		return true;
	if(p->data > item)
		return search_rec(item, p->left);
	else
		return search_rec(item, p->right);
}

bool BinarySearchTree::search(int item)
{
	return search_rec(item, root);
}

TNode* BinarySearchTree::addNode_rec(int item, TNode *p)
{
	if(p == NULL)
		p = new TNode(item);
	else if(p->data > item)
		p->left = addNode_rec(item, p->left);
	else
		p->right = addNode_rec(item, p->right);
	return p;
}

void BinarySearchTree::addNode(int item)
{
	root = addNode_rec(item, root);
}

TNode* BinarySearchTree::delete_NodeFound(TNode *p)
{  	
	if(p->left == NULL)	
	{
		TNode* temp = p->right;
		delete p;
		return temp;
	}
	else if(p->right == NULL)
	{
		TNode* temp = p->left;
		delete p;
		return temp;
	}	
    else
    {
		TNode *p1 = p->right; //root of the right subtree of the node to delete
		while(p1->left != NULL)  //searching for leftmost node in the right subtree
			p1 = p1->left;
		p->data = p1->data; //assigning data member of the leftmost node
							//delete leftmost node in the right subtree instead of the original node
		p->right = deleteNode_rec(p->data, p->right);
		return p;
	}
}//delete_NodeFound

TNode* BinarySearchTree::deleteNode_rec(int item, TNode *p)
{	
	if(item < p->data)		
		p->left = deleteNode_rec(item, p->left);
    else if(item > p->data)
		p->right = deleteNode_rec(item, p->right);
    else 
		p = delete_NodeFound(p);
    return p;    
}//deleteNode_rec

void BinarySearchTree::deleteNode(int item)
{   	
	if(search(item))	
		root = deleteNode_rec(item, root);
	else 
		std::cout<< "Item not foud: item not deleted\n";
}//deleteNode



TNode* BinarySearchTree::findClosest(int item)
{
	return findClosest_rec(item, root);
}

TNode* BinarySearchTree::findClosest_rec(int item, TNode *p)
{
	if(p->data == item)
		return p;
	if(p->left != NULL)
		if(p->right != NULL)
			if(abs(p->left->data - item) > abs(p->data - item) && abs(p->right->data - item) > abs(p->data - item))
				return p;
			else
				return findClosest_rec(item, abs(p->left->data - item) > abs(p->right->data - item)? p->right : p->left);
		else
			if(abs(p->left->data - item) > abs(p->data - item))
				return p;
			else
				return findClosest_rec(item, p->left);
	else
		if(p->right != NULL)
			if(abs(p->right->data - item) > abs(p->data - item))
				return p;
			else
				return findClosest_rec(item, p->right);
		else
			return p;
}