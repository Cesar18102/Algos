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

TNode* BalancedBinarySearchTree::FindMiddle()
{
	int maxVal = BalancedBinarySearchTree::findmax(root)->data;
	int minVal = BalancedBinarySearchTree::findmin(root)->data;
	return BinarySearchTree::findClosest((maxVal + minVal) / 2);
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

int BalancedBinarySearchTree::commonAncestor(int a, int b)
{
	return commonAncestor_rec(root, a, b);
}

int BalancedBinarySearchTree::commonAncestor_rec(TNode *p, int a, int b)
{
	if(p == NULL)
		return 0;

	if(p->data == a)
		return a;

	if(p->data == b)
		return b;

	bool hasAtLeftA = this->search_rec(a, p->left);
	bool hasAtLeftB = this->search_rec(b, p->left);

	bool hasAtRightA = this->search_rec(a, p->right);
	bool hasAtRightB = this->search_rec(b, p->right);

	if(hasAtLeftA && hasAtLeftB)
		return commonAncestor_rec(p->left, a, b);
	if(hasAtRightA && hasAtRightB)
		return commonAncestor_rec(p->right, a, b);
	if((hasAtLeftA && hasAtRightB) || (hasAtRightA && hasAtLeftB))
		return p->data;
}

BalancedBinarySearchTree BalancedBinarySearchTree::deleteDuplicate()
{
	TNode *MinNode = root;
	for (; MinNode->left != NULL; MinNode = MinNode->left);
	int min = MinNode->data;

	TNode *MaxNode = root;
	for (; MaxNode->right != NULL; MaxNode = MaxNode->right);
	int max = MaxNode->data;

	int length = max - min + 1;
	int* nodes = new int[length];
	findDuplicate_rec(root, nodes, min);

	BalancedBinarySearchTree result = BalancedBinarySearchTree();
	for (int i = 0; i < length; i++)
		if (nodes[i] != 0)
			result.root = result.insert(result.root, i + min);

	return result;
}

void BalancedBinarySearchTree::findDuplicate_rec(TNode *node, int* data, int min)
{
	if (node == NULL)
		return;

	data[node->data - min]++;
	findDuplicate_rec(node->left, data, min);
	findDuplicate_rec(node->right, data, min);
}

