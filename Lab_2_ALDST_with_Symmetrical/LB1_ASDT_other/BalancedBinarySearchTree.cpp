#include "BalancedBinarySearchTree.h"
#include <math.h>


BalancedBinarySearchTree::BalancedBinarySearchTree(void)
{

}

unsigned char BalancedBinarySearchTree::height(TNode* p)
{
	return p? p->height : 0;
}

int BalancedBinarySearchTree::bfactor(TNode* p)
{
	return height(p->right) - height(p->left);
}

void BalancedBinarySearchTree::fixheight(TNode* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr? hl : hr) + 1;
}

TNode* BalancedBinarySearchTree::rotateright(TNode* p) // правый поворот вокруг p
{
	TNode* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

TNode* BalancedBinarySearchTree::rotateleft(TNode* q) // левый поворот вокруг q
{
	TNode* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

TNode* BalancedBinarySearchTree::balance(TNode* p) // балансировка узла p
{
	fixheight(p);
	int bf = bfactor(p);
	if(bf == 2)
	{
		if(bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	else if(bf == -2)
	{
		if(bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

TNode* BalancedBinarySearchTree::insert(TNode* p, int k) // вставка ключа k в дерево с корнем p
{
	if(!p)
		return new TNode(k);
	if(k < p->data)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

TNode* BalancedBinarySearchTree::findmin(TNode* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left? findmin(p->left) : p;
}

TNode* BalancedBinarySearchTree::findmax(TNode* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->right? findmax(p->right) : p;
}

TNode* BalancedBinarySearchTree::removemin(TNode* p) // удаление узла с минимальным ключом из дерева p
{
	if(p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

TNode* BalancedBinarySearchTree::remove(TNode* p, int k) // удаление ключа k из дерева p
{
	if(!p) return 0;
	if(k < p->data)
		p->left = remove(p->left, k);
	else if(k > p->data)
		p->right = remove(p->right, k);	
	else
	{
		TNode* q = p->left;
		TNode* r = p->right;
		delete p;
		if( !r ) return q;
		TNode* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}
