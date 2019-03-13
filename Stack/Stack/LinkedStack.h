/*!
* \brief 链栈
* 
* 带有头结点的链栈；
* 采用链式存储方式实现，需注意的是，删除操作
* 仅释放数组指针，不释放栈指针；
* 对于链栈来说，判满操作一直为false。
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

