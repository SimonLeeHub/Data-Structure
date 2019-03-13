/*!
* \brief ˳��ջ
* 
* ��������+��̬�����ڴ�Ĵ洢��ʽʵ�֣���ע����ǣ�ɾ������
* ���ͷ�����ָ�룬Ҳ�ͷ�ջָ�룻
* ����������ʹ����true��Ҳ�ɼ�����ջ����Ϊ�������̬�����ڴ档
*
* \author Lee
* \date 2019.03.13
*/
#pragma once
#include "stackoperation.h"
#define INIT_STACK_CAPACITY 5
struct SS_Node;
typedef SS_Node *SS_Stack;
struct SS_Node
{
	ElementType *array;
	int capacity;
	int topOfStack;
};
class CSequentStack :
	public CStackOperation
{
public:
	CSequentStack(void);
	~CSequentStack(void);
	vStack createStack(void);	//O(1)
	bool isEmpty(vStack S);	//O(1)
	bool isFull(vStack S);	//O(1)
	void push(ElementType X, vStack S);	//O(1)
	void pop(vStack S);	//O(1)
	ElementType top(vStack S);	//O(1)
	ElementType topAndPop(vStack S);	//O(1)
	void deleteStack(vStack S);	//O(1)
};

