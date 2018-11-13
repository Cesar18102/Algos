#pragma once
#include "binarytree.h"
#include "Item.h"

class BinarySearchTree : public BinaryTree
{
	public: BinarySearchTree() : BinaryTree() { }
			bool search(Item item);	
			void addNode(Item item);	
			void deleteNode(Item item);
			Item dequeueMax();
			TNode* findMax();
			TNode* findClosest(int item);
			TNode* findClosest_rec(int item, TNode *p);

	protected:	bool search_rec(Item item, TNode *p);
				TNode* addNode_rec(Item item, TNode *p);
				TNode* deleteNode_rec(Item item, TNode *p);
				TNode* delete_NodeFound(TNode *p);
				TNode* findMax_rec(TNode *p);
};

