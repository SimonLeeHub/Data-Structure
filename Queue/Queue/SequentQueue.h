/*!
* \brief 顺序队列
* 
* 队列最多能容纳的元素为队列capacity-1，即含有一个空元素，以区分判空和判满；
* 所有操作均为O(1),但是队列容量有限制；
* 清空操作释放数组指针，同时也释放队列指针；
* front为队头元素数组下标，rear为队尾元素的下一个元素的数组下标。
*
* \author Lee 
* \date 2019.03.13
*/
#pragma once
#include "queueoperation.h"
#define INIT_QUEUE_CAPACITY 5
struct SQ_Node
{
	ElementType *array;
	int capacity;
	int front;
	int rear;
};
typedef SQ_Node *SQ_Queue;
class CSequentQueue :
	public CQueueOperation
{
public:
	CSequentQueue(void);
	~CSequentQueue(void);
	vQueue createQueue();
	bool isEmpty(vQueue Q);	//O(1)
	bool isFull(vQueue Q);	//O(1)
	void enqueue(ElementType X, vQueue Q);	//O(1)
	void dequeue(vQueue Q);	//O(1)
	ElementType front(vQueue Q);	//O(1)
	ElementType frontAndDequeue(vQueue Q);	//O(1)
	void deleteQueue(vQueue Q);	//O(1)
};

