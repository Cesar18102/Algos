#include "BinarySearchTree.h"

bool BinarySearchTree::search_rec(Item item, TNode *p)
{
	if(p == NULL)
		return NULL;
	if(p->data.Priority == item.Priority)
		return p;
	if(p->data.Priority > item.Priority)
		return search_rec(item, p->left);
	else
		return search_rec(item, p->right);
}

bool BinarySearchTree::search(Item item)
{
	return search_rec(item, root);
}

TNode* BinarySearchTree::addNode_rec(Item item, TNode *p)
{
	if(p == NULL)
		p = new TNode(item.Value, item.Priority);
	else if(p->data.Priority > item.Priority)
		p->left = addNode_rec(item, p->left);
	else
		p->right = addNode_rec(item, p->right);
	return p;
}

void BinarySearchTree::addNode(Item item)
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

TNode* BinarySearchTree::deleteNode_rec(Item item, TNode *p)
{	
	if(item.Priority < p->data.Priority)		
		p->left = deleteNode_rec(item, p->left);
	else if(item.Priority > p->data.Priority)
		p->right = deleteNode_rec(item, p->right);
    else 
		p = delete_NodeFound(p);
    return p;    
}//deleteNode_rec

void BinarySearchTree::deleteNode(Item item)
{   	
	if(search(item))
		root = deleteNode_rec(item, root);
	else 
		std::cout<< "Item not foud: item not deleted\n";
}//deleteNode

Item BinarySearchTree::dequeueMax()
{
	TNode* temp = findMax();

	if(temp == NULL)
		return Item();

	TNode* ToAdd = new TNode(*temp);
	Item result = Item(temp->data);
	deleteNode(result);

	return result;
}

TNode* BinarySearchTree::findMax()
{
	return root == NULL? NULL : findMax_rec(root);
}

TNode* BinarySearchTree::findMax_rec(TNode *p)
{
	if(p->right == NULL)
		return p;

	return findMax_rec(p->right);
}