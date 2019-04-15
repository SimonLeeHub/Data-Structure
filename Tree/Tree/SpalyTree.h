/*!
* \brief ��չ���� 
* 
* ����ʱ�Ὣ������Ԫ����������������������ָ�룬ͬʱҲ�Ǳ�����Ԫ�ص�ָ�룻
* ɾ��ʱ����������Ԫ������������ɾ����Ȼ��������������ڣ��е����ֵ������������������
* ��ʱ��������������Ϊû���Һ��ӵĽڵ㣬Ȼ����������������Ϊ�������������Һ��ӣ�
* 
* 
* \author Lee
* \date 2019.03.19
*/
#pragma once
#include "treeoperation.h"
struct SPT_Node;
typedef SPT_Node *SPT_Position;
typedef SPT_Node *SPT_Tree;
struct SPT_Node
{
	ElementType element;
	SPT_Tree left;
	SPT_Tree right;
};
class CSpalyTree :
	public CTreeOperation
{
public:
	CSpalyTree(void);
	~CSpalyTree(void);

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

private:
	SPT_Position findInside(ElementType X, SPT_Tree SPT);	//�ݹ���ң����ؽڵ�λ��
	SPT_Tree splay(SPT_Position P, SPT_Tree oldT);    //��Pλ�õĽڵ��Ϊ��չ���ĸ�
	SPT_Tree Lrotate(SPT_Tree oldT);    //����
	SPT_Tree Rrotate(SPT_Tree oldT);    //�ҵ���
};

