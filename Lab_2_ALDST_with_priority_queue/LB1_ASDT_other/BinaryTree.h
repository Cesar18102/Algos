#pragma once
#include<iostream>
#include "Item.h"

struct TNode 
{
	Item data;
	TNode *left;
	TNode *right;
	unsigned char height;
	TNode();
	TNode(int data, int priority);
};

class BinaryTree
{
	public:	BinaryTree();
			bool isEmpty();
			bool isFull();
			void preorder();
			void inorder();	
			void postorder();
			void makeEmpty();
			int size();

	public:	TNode *root;
			void preorder_rec(TNode *p);
			void inorder_rec(TNode *p);
			void postorder_rec(TNode *p);
			void makeEmpty_rec(TNode *p);
			int size_rec(TNode *p);
};