#pragma once
#include<iostream>

struct TNode 
{
	int data;
	TNode *left;
	TNode *right;
	unsigned char height;
	TNode();
	TNode(int d);
};

class BinaryTree
{
	public:	BinaryTree();
			bool isEmpty();
			bool isFull();
			void preorder();
			void inorder();	
			void back_inorder();
			void postorder();
			void makeEmpty();
			int size();
			BinaryTree SymmetricalBBST();

	public:	TNode *root;
			void preorder_rec(TNode *p);
			void inorder_rec(TNode *p);
			void back_inorder_rec(TNode *p);
			void postorder_rec(TNode *p);
			void makeEmpty_rec(TNode *p);
			int size_rec(TNode *p);
			TNode* SymmetricalBBST_rec(TNode* rootOrig, TNode* rootCopy);
};