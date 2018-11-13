#pragma once
#include "binarysearchtree.h"
class BalancedBinarySearchTree : public BinarySearchTree
{
	public: BalancedBinarySearchTree(void);
			unsigned char height(TNode *p);
			int bfactor(TNode *p);
			void fixheight(TNode *p);
			TNode* rotateright(TNode *p);
			TNode* rotateleft(TNode *p);
			TNode* balance(TNode *p);
			TNode* insert(TNode *p, int k);
			TNode* findmin(TNode *p);
			TNode* removemin(TNode *p);
			TNode* remove(TNode *p, int k);
			TNode* findmax(TNode* p);
			TNode* FindMiddle();
};