/*!
* \brief 堆（优先队列）的基本操作接口类
* 
* 包括创建堆（1）、判空（1）、判满（1）、入队（1）、优先出队（1）、返回队首元素（1）、清空堆（1）与合并堆（1）共八种基本操作
* 
* \author Lee 
* \date 2019.04.02
*/
#pragma once
typedef int ElementType;
typedef void *vHeap;
typedef void *vPosition;
class CHeapOperation
{
public:
	CHeapOperation(void);
	virtual ~CHeapOperation(void);

	virtual vHeap createQueue() = 0;
	virtual bool isEmpty(vHeap H) = 0;
	virtual bool isFull(vHeap H) = 0;
	virtual vHeap enqueue(ElementType X, vHeap H) = 0;
	virtual vHeap dequeue(vHeap H) = 0;
	virtual ElementType front(vHeap H) = 0;
	virtual void deleteQueue(vHeap H) = 0;
	virtual vHeap merge(vHeap H1, vHeap H2) = 0;
	virtual vHeap buildHeap(ElementType *array, int len) = 0;

	//基本辅助操作
	virtual void printQueue(vHeap H) = 0;

	std::string description;
};

