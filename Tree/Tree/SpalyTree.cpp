#include "stdafx.h"
#include "SpalyTree.h"


CSpalyTree::CSpalyTree(void)
{
	description = "\n\n\n-------- Spaly Tree --------\n";
}


CSpalyTree::~CSpalyTree(void)
{
}

vTree CSpalyTree::createTree(void)
{
	return NULL;
}

SPT_Position CSpalyTree::findInside(ElementType X, SPT_Tree SPT)
{
	if(!SPT) return NULL;
	if(X < SPT->element) 
		return findInside(X, SPT->left);
	else if(X > SPT->element)
		return findInside(X, SPT->right);
	else
		return SPT;
}

vPosition CSpalyTree::find(ElementType X, vTree T)
{
	SPT_Tree SPT = (SPT_Tree)T;
	SPT_Position pos = findInside(X, SPT);
	if(pos)
		// 将被查找元素推至树根
		return (vPosition)splay(pos, SPT);
	else
		return NULL;
}

vPosition CSpalyTree::findMin(vTree T)
{
	SPT_Position tempP = (SPT_Position)T;
	if(!tempP) return NULL;
	while(tempP->left) tempP = tempP->left;
	return tempP;
}

vPosition CSpalyTree::findMax(vTree T)
{
	SPT_Position tempP = (SPT_Position)T;
	if(!tempP) return NULL;
	while(tempP->right) tempP = tempP->right;
	return tempP;
}

vTree CSpalyTree::insert(ElementType X, vTree T)
{
	SPT_Tree SPT = (SPT_Tree)T;
	if(!SPT)
	{
		SPT = (SPT_Tree)malloc(sizeof(SPT_Node));
		assert(SPT);
		SPT->element = X;
		SPT->left = SPT->right = NULL;
	}
	else if(X < SPT->element)
	{
		SPT->left = (SPT_Tree)insert(X, (vTree)(SPT->left));
	}
	else if(X > SPT->element)
	{
		SPT->right = (SPT_Tree)insert(X, (vTree)(SPT->right));
	}

	return SPT;
}

vTree CSpalyTree::deleteX(ElementType X, vTree T)
{
	// 将待删除元素推至树根
	SPT_Tree SPT = (SPT_Tree)find(X, T);
	if(SPT)
	{
		SPT_Tree LT = SPT->left;
		SPT_Tree RT = SPT->right;
		if(!LT) return RT;
		if(!RT) return LT;
		free(SPT);
		
		// 将左子树最大元素推至左子树树根，则左子树根节点的右儿子为空
		LT = splay((SPT_Position)findMax(LT), LT);

		// 将右子树插入到左子树的根节点，作为左子树根节点的右子树
		LT->right = RT;
		return (vTree)LT;
	}
	else
		return T;
}

vTree CSpalyTree::deleteTree(vTree T)
{
	SPT_Tree SPT = (SPT_Tree)T;
	if(SPT)
	{
		deleteTree((vTree)(SPT->left));
		deleteTree((vTree)(SPT->right));
		free(SPT);
	}
	return NULL;
}

// 基本辅助函数
int CSpalyTree::treeHeight(vTree T)
{
	SPT_Tree SPT = (SPT_Tree)T;
	if(!SPT) return 0;
	int leftHeight = treeHeight((vTree)(SPT->left));
	int rightHeight = treeHeight((vTree)(SPT->right));
	return leftHeight>=rightHeight?leftHeight+1:rightHeight+1;
}

vPosition CSpalyTree::leftChild(vPosition P)
{
	SPT_Position pos = (SPT_Position)P;
	assert(pos);
	return (vPosition)(pos->left);
}

vPosition CSpalyTree::rightChild(vPosition P)
{
	SPT_Position pos = (SPT_Position)P;
	assert(pos);
	return (vPosition)(pos->right);
}

ElementType CSpalyTree::retrieve(vPosition P)
{
	SPT_Position pos = (SPT_Position)P;
	assert(pos);
	return pos->element;
}

SPT_Tree CSpalyTree::splay(SPT_Position P, SPT_Tree oldT)
{
	// 递归splay，在回溯时进行单旋转，将P节点推至树根
	SPT_Tree newT;
	ElementType element = P->element;
	if(element == oldT->element)
	{
		newT = oldT;
	}
	else if(element < oldT->element)
	{
		oldT->left = splay(P, oldT->left);
		newT = Rrotate(oldT);
	}
	else
	{
		oldT->right = splay(P, oldT->right);
		newT = Lrotate(oldT);
	}

	return newT;
}

SPT_Tree CSpalyTree::Lrotate(SPT_Tree oldT)
{
	SPT_Tree newT = oldT->right;
	oldT->right = newT->left;
	newT->left = oldT;
	return newT;
}

SPT_Tree CSpalyTree::Rrotate(SPT_Tree oldT)
{
	SPT_Tree newT = oldT->left;
	oldT->left = newT->right;
	newT->right = oldT;
	return newT;
}


