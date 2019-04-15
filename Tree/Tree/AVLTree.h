/*!
* \brief ƽ��������� 
* 
* ���ڵ��а����߶���Ϣ��ÿ���ڵ�����������������ĸ߶�����1��
* �սڵ�߶�Ϊ�㣬Ҷ�ӽڵ�߶�Ϊ1
* 
* \author Lee
* \date 2019.03.19
*/
#pragma once
#include "treeoperation.h"
struct AVLT_Node;
typedef AVLT_Node *AVLT_Position;
typedef AVLT_Node *AVLT_Tree;
struct AVLT_Node
{
	ElementType element;
	AVLT_Tree left;
	AVLT_Tree right;
	int height;
};
class CAVLTree :
	public CTreeOperation
{
public:
	CAVLTree(void);
	~CAVLTree(void);

	vTree createTree(void);	//O(1)
	vPosition find(ElementType X, vTree T);	//O(logN)
	vPosition findMin(vTree T);	//O(logN)
	vPosition findMax(vTree T);	//O(logN)
	vTree insert(ElementType X, vTree T);	//O(logN)
	vTree deleteX(ElementType X, vTree T);	//O(logN)
	vTree deleteTree(vTree T);	//O(N)

	// ������������
	int treeHeight(vTree T);	//O(1)
	vPosition leftChild(vPosition P);	//O(1)
	vPosition rightChild(vPosition P);	//O(1)
	ElementType retrieve(vPosition P);	//O(1)

private:
	AVLT_Tree Lrotate(AVLT_Tree oldT);    //�������ڽϸ����������Ҳ���룩
	AVLT_Tree Rrotate(AVLT_Tree oldT);    //�ҵ������ڽϸ��������������룩
	AVLT_Tree LRrotate(AVLT_Tree oldT);    //����˫�����ڽϸ����������Ҳ���룩
	AVLT_Tree RLrotate(AVLT_Tree oldT);    //����˫�����ڽϸ��������������룩
};

