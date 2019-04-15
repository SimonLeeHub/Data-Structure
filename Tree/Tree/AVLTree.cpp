#include "stdafx.h"
#include "AVLTree.h"


CAVLTree::CAVLTree(void)
{
	description = "\n\n\n-------- AVL Tree --------\n";
}


CAVLTree::~CAVLTree(void)
{
}

vTree CAVLTree::createTree(void)
{
	return NULL;
}

vPosition CAVLTree::find(ElementType X, vTree T)
{
	AVLT_Tree AVLT = (AVLT_Tree)T;
	if(AVLT)
	{
		if(X < AVLT->element) return find(X, (vTree)(AVLT->left));
		if(X > AVLT->element) return find(X, (vTree)(AVLT->right));
		return (vPosition)AVLT;
	}
	else
	{
		return NULL;
	}
}

vPosition CAVLTree::findMin(vTree T)
{
	AVLT_Position tempP = (AVLT_Position)T;
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

vPosition CAVLTree::findMax(vTree T)
{
	AVLT_Position tempP = (AVLT_Position)T;
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

vTree CAVLTree::insert(ElementType X, vTree T)
{
	// ���������������ķ�ʽ���ƣ�ֻ�ǻ���ʱ������ṹ�Ƿ�����ƽ���������粻���㣬�������ת������ͬʱÿ�εݹ����Ҫ����������Ϣ

	AVLT_Tree AVLT = (AVLT_Tree)T;
	if(!AVLT)
	{
		AVLT = (AVLT_Tree)malloc(sizeof(AVLT_Node));
		assert(AVLT);
		AVLT->element = X;
		AVLT->height = 1;
		AVLT->left = NULL;
		AVLT->right = NULL;
	}
	else
	{
		if(X < AVLT->element)
		{
			AVLT->left = (AVLT_Tree)insert(X, vTree(AVLT->left));
			if(treeHeight(vTree(AVLT->left)) - treeHeight(vTree(AVLT->right)) == 2)
			{
				// �ڽϸ���������������
				if(X < AVLT->left->element) 
					AVLT = Rrotate(AVLT);
				// �ڽϸ����������Ҳ����
				else
					AVLT = LRrotate(AVLT);
			}
		}
		else if(X > AVLT->element)
		{
			AVLT->right = (AVLT_Tree)insert(X, vTree(AVLT->right));
			if(treeHeight(vTree(AVLT->right)) - treeHeight(vTree(AVLT->left)) == 2)
			{
				// �ڽϸ����������Ҳ����
				if(X > AVLT->right->element) 
					AVLT = Lrotate(AVLT);
				// �ڽϸ���������������
				else
					AVLT = RLrotate(AVLT);
			}
		}

		// ע��ÿ�εݹ鶼Ҫ��������
		AVLT->height = treeHeight((vTree)(AVLT->left))>treeHeight((vTree)(AVLT->right))? treeHeight((vTree)(AVLT->left))+1:treeHeight((vTree)(AVLT->right))+1;
	}

	return AVLT;
}

vTree CAVLTree::deleteX(ElementType X, vTree T)
{
	AVLT_Tree AVLT = (AVLT_Tree)T;
	assert(AVLT);
	
	// �����������ɾ���ķ�ʽ���ƣ�ֻ�ǻ���ʱ������ṹ�Ƿ�����ƽ���������粻���㣬�������ת������ͬʱÿ�εݹ����Ҫ����������Ϣ
	if(X < AVLT->element) 
	{
		AVLT->left = (AVLT_Tree)deleteX(X, (vTree)(AVLT->left));
		if(treeHeight(vTree(AVLT->right)) - treeHeight(vTree(AVLT->left)) == 2)
		{
			if(treeHeight(vTree(AVLT->right->right)) > treeHeight(vTree(AVLT->right->left)))
				AVLT = Lrotate(AVLT);
			else
				AVLT = RLrotate(AVLT);	
		}
	}
	else if(X > AVLT->element)
	{
		AVLT->right = (AVLT_Tree)deleteX(X, (vTree)(AVLT->right));
		if(treeHeight(vTree(AVLT->left)) - treeHeight(vTree(AVLT->right)) == 2)
		{
			if(treeHeight(vTree(AVLT->left->left)) > treeHeight(vTree(AVLT->right->right)))
				AVLT = Rrotate(AVLT);
			else
				AVLT = LRrotate(AVLT);	
		}
	}
	else
	{
		if(AVLT->left && AVLT->right)
		{
			vPosition tempPos = findMin((vTree)(AVLT->right));
			AVLT->element = retrieve(tempPos);
			AVLT->right = (AVLT_Tree)deleteX(AVLT->element, (vTree)(AVLT->right));
			if(treeHeight(vTree(AVLT->left)) - treeHeight(vTree(AVLT->right)) == 2)
			{
				if(treeHeight(vTree(AVLT->left->left)) > treeHeight(vTree(AVLT->right->right)))
					AVLT = Rrotate(AVLT);
				else
					AVLT = LRrotate(AVLT);	
			}
		}
		else
		{
			AVLT_Position tempP = AVLT;
			if(!AVLT->left)
				AVLT = AVLT->right;
			else if(!AVLT->right)
				AVLT = AVLT->left;
			free(tempP);
		}
	}
	// �˴�ע�⣺����벻ͬ���ڸ�������ʱ�������ж����Ƿ�Ϊ��
	if(AVLT) AVLT->height = treeHeight((vTree)(AVLT->left))>treeHeight((vTree)(AVLT->right))? treeHeight((vTree)(AVLT->left))+1:treeHeight((vTree)(AVLT->right))+1;
	return AVLT;
}

vTree CAVLTree::deleteTree(vTree T)
{
	AVLT_Tree AVLT = (AVLT_Tree)T;
	if(AVLT)
	{
		deleteTree(AVLT->left);
		deleteTree(AVLT->right);
		free(AVLT);
	}
	return NULL;
}

int CAVLTree::treeHeight(vTree T)
{
	AVLT_Tree AVLT = (AVLT_Tree)T;
	if(AVLT) return AVLT->height;
	return 0;
}

vPosition CAVLTree::leftChild(vPosition P)
{
	AVLT_Position pos = (AVLT_Position)P;
	assert(pos);
	return (vPosition)(pos->left);
}

vPosition CAVLTree::rightChild(vPosition P)
{
	AVLT_Position pos = (AVLT_Position)P;
	assert(pos);
	return (vPosition)(pos->right);
}

ElementType CAVLTree::retrieve(vPosition P)
{
	AVLT_Position pos = (AVLT_Position)P;
	assert(pos);
	return pos->element;
}

AVLT_Tree CAVLTree::Lrotate(AVLT_Tree oldT)
{
	AVLT_Position newT = oldT->right;
	oldT->right = newT->left;
	newT->left = oldT;

	newT->height = treeHeight((vTree)(newT->left))>treeHeight((vTree)(newT->right))? treeHeight((vTree)(newT->left))+1:treeHeight((vTree)(newT->right))+1;
	oldT->height = treeHeight((vTree)(oldT->left))>treeHeight((vTree)(oldT->right))? treeHeight((vTree)(oldT->left))+1:treeHeight((vTree)(oldT->right))+1;

	return newT;

}
AVLT_Tree CAVLTree::Rrotate(AVLT_Tree oldT)
{
	AVLT_Tree newT = oldT->left;
	oldT->left = newT->right;
	newT->right = oldT;

	newT->height = treeHeight((vTree)(newT->left))>treeHeight((vTree)(newT->right))? treeHeight((vTree)(newT->left))+1:treeHeight((vTree)(newT->right))+1;
	oldT->height = treeHeight((vTree)(oldT->left))>treeHeight((vTree)(oldT->right))? treeHeight((vTree)(oldT->left))+1:treeHeight((vTree)(oldT->right))+1;

	return newT;
}
AVLT_Tree CAVLTree::LRrotate(AVLT_Tree oldT)
{
	oldT->left = Lrotate(oldT->left);
	return Rrotate(oldT);;
}
AVLT_Tree CAVLTree::RLrotate(AVLT_Tree oldT)
{
	oldT->right = Rrotate(oldT->right);
	return Lrotate(oldT);
}