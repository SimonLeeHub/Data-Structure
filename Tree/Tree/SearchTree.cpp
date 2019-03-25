#include "stdafx.h"
#include "SearchTree.h"


CSearchTree::CSearchTree(void)
{
	description = "\n\n\n-------- Search Tree --------\n";
}


CSearchTree::~CSearchTree(void)
{
}

vTree CSearchTree::createTree(void)
{
	return NULL;
}

vPosition CSearchTree::find(ElementType X, vTree T)
{
	SET_Tree SET = (SET_Tree)T;
	if(SET)
	{
		if(X < SET->element) return find(X, (vTree)(SET->left));
		if(X > SET->element) return find(X, (vTree)(SET->right));
		return (vPosition)SET;
	}
	else
	{
		return NULL;
	}
}

vPosition CSearchTree::findMin(vTree T)
{
	SET_Position tempP = (SET_Position)T;
	if(tempP)
	{
		while(tempP->left) tempP = tempP->left;
		return (vPosition)tempP;
	}
	else
	{
		return NULL;
	}
}

vPosition CSearchTree::findMax(vTree T)
{
	SET_Position tempP = (SET_Tree)T;
	if(tempP)
	{
		while(tempP->right) tempP = tempP->right;
		return (vPosition)tempP;
	}
	else
	{
		return NULL;
	}
}

vTree CSearchTree::insert(ElementType X, vTree T)
{
	SET_Tree SET = (SET_Tree)T;
	if(!SET)
	{
		SET = (SET_Position)malloc(sizeof(SET_Node));
		assert(SET);
		SET->element = X;
		SET->left = NULL;
		SET->right = NULL;
	}
	else
	{
		if(X < SET->element) SET->left = (SET_Position)insert(X, (vTree)(SET->left));
		if(X > SET->element) SET->right = (SET_Position)insert(X, (vTree)(SET->right));
	}
	return (vTree)SET;
}

vTree CSearchTree::deleteX(ElementType X, vTree T)
{
	SET_Tree SET = (SET_Tree)T;
	assert(SET);

	// 递归查找元素并删除
	if(X < SET->element) SET->left = (SET_Tree)deleteX(X, (vTree)(SET->left));
	if(X > SET->element) SET->right = (SET_Tree)deleteX(X, (vTree)(SET->right));

	// 找到元素
	if(X == SET->element)
	{
		// 如果待删除节点有双儿子，则将右子树的最小节点的值放到当前节点，
		// 然后递归删除右子树的最小节点
		if(SET->left && SET->right)
		{
			SET_Position tempP = (SET_Position)findMin((vTree)(SET->right));
			SET->element = tempP->element;
			SET->right = (SET_Tree)deleteX(tempP->element, (vTree)(SET->right));
		}
		else
		{
			SET_Position tempP = SET;
			if(!SET->left) 
			{
				SET = SET->right;
			}
			else if(!SET->right)
			{
				SET = SET->left;
			}
			free(tempP);
		}
	}

	return (vTree)SET;
}

vTree CSearchTree::deleteTree(vTree T)
{
	SET_Tree SET = (SET_Tree)T;
	if(SET)
	{
		deleteTree((vTree)SET->left);
		deleteTree((vTree)SET->right);
		free(SET);
	}
	return NULL;
}

int CSearchTree::treeHeight(vTree T)
{
	SET_Tree SET = (SET_Tree)T;
	if(!SET) return 0;
	int leftHeight = treeHeight((vTree)(SET->left));
	int rightHeight = treeHeight((vTree)(SET->right));
	return leftHeight>=rightHeight?leftHeight+1:rightHeight+1;
}

vPosition CSearchTree::leftChild(vPosition P)
{
	SET_Position pos = (SET_Position)P;
	assert(pos);
	return (vPosition)(pos->left);
}

vPosition CSearchTree::rightChild(vPosition P)
{
	SET_Position pos = (SET_Position)P;
	assert(pos);
	return (vPosition)(pos->right);
}

ElementType CSearchTree::retrieve(vPosition P)
{
	SET_Position pos = (SET_Position)P;
	assert(pos);
	return pos->element;
}
