#pragma once
#include "binarytree.h"
class BinarySearchTree : public BinaryTree
{
	public: BinarySearchTree() : BinaryTree() { }
			bool search(int item);	
			void addNode(int item);	
			void deleteNode(int item);

	protected:	bool search_rec(int item, TNode *p);
				TNode* addNode_rec(int item, TNode *p);
				TNode* deleteNode_rec(int item, TNode *p);
				TNode* delete_NodeFound(TNode *p);
};

