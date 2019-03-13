/*!
* \brief ��ջ
* 
* ����ͷ������ջ��
* ������ʽ�洢��ʽʵ�֣���ע����ǣ�ɾ������
* ���ͷ�����ָ�룬���ͷ�ջָ�룻
* ������ջ��˵����������һֱΪfalse��
*
* \author Lee
* \date 2019.03.13
*/
#pragma once
#include "stackoperation.h"
struct LS_Node;
typedef LS_Node *LS_Position;
typedef LS_Node *LS_Stack;
struct LS_Node
{
	ElementType element;
	LS_Position next;
};

class CLinkedStack :
	public CStackOperation
{
public:
	CLinkedStack(void);
	~CLinkedStack(void);
	vStack createStack(void);	//O(1)
	bool isEmpty(vStack S);	//O(1)
	bool isFull(vStack S);	//O(1)
	void push(ElementType X, vStack S);	//O(1)
	void pop(vStack S);	//O(1)
	ElementType top(vStack S);	//O(1)
	ElementType topAndPop(vStack S);	//O(1)
	void deleteStack(vStack S);	//O(N)
};

