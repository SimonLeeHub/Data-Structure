/*!
* \brief 顺序栈
* 
* 采用数据+动态分配内存的存储方式实现，需注意的是，删除操作
* 既释放数组指针，也释放栈指针；
* 判满操作即使返回true，也可继续入栈，因为会继续动态分配内存。
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

