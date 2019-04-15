/*!
* \brief ������������ 
* 
* ��������������1��������Ԫ�أ�3��������Ԫ�أ�1����ɾ��Ԫ�أ�1����ɾ������1�������ֻ�������
* 
* \author Lee
* \date 2019.03.18
*/
#pragma once
#include "treeoperation.h"
struct SET_Node;
typedef SET_Node *SET_Position;
typedef SET_Node *SET_Tree;
struct SET_Node
{
	ElementType element;
	SET_Tree left;
	SET_Tree right;
};
class CSearchTree :
	public CTreeOperation
{
public:
	CSearchTree(void);
	~CSearchTree(void);
	vTree createTree(void);	//O(1)
	vPosition find(ElementType X, vTree T);	//O(logN)
	vPosition findMin(vTree T);	//O(logN)
	vPosition findMax(vTree T);	//O(logN)
	vTree insert(ElementType X, vTree T);	//O(logN)
	vTree deleteX(ElementType X, vTree T);	//O(logN)
	vTree deleteTree(vTree T);	//O(N)

	// ������������
	int treeHeight(vTree T);	//O(N)
	vPosition leftChild(vPosition P);	//O(1)
	vPosition rightChild(vPosition P);	//O(1)
	ElementType retrieve(vPosition P);	//O(1)
};

