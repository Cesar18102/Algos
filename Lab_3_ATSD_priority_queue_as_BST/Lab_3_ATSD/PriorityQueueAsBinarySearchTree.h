#pragma once
#include "binarytree.h"
#include "Item.h"

class PriorityQueueAsBinarySearchTree : public BinaryTree
{
	public: PriorityQueueAsBinarySearchTree() : BinaryTree() { }
			bool search(Item item);	
			void addNode(Item item);	
			void deleteNode(Item item);
			Item dequeueMax();
			TNode* findMax();

	protected:	bool search_rec(Item item, TNode *p);
				TNode* addNode_rec(Item item, TNode *p);
				TNode* deleteNode_rec(Item item, TNode *p);
				TNode* delete_NodeFound(TNode *p);
				TNode* findMax_rec(TNode *p);
};