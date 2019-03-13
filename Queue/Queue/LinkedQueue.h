/*!
* \brief 链表队列
* 
* 带有头结点的链表队列，front指针永远指向头结点，
* rear指针指向队尾元素，队列为空时，二者均指向头结点；
* 清空操作不释放头指针；
* 判满操作永远返回false。
*
* \author Lee 
* \date 2019.03.13
*/
#pragma once
#include "queueoperation.h"
struct LQ_Node;
typedef LQ_Node *LQ_Position;
struct LQ_Node
{
	ElementType element;
	LQ_Position next;
};
struct LQ_Info
{
	LQ_Position front;
	LQ_Position rear;
};
typedef LQ_Info *LQ_Queue;
class CLinkedQueue :
	public CQueueOperation
{
public:
	CLinkedQueue(void);
	~CLinkedQueue(void);
	vQueue createQueue();
	bool isEmpty(vQueue Q);	//O(1)
	bool isFull(vQueue Q);	//O(1)
	void enqueue(ElementType X, vQueue Q);	//O(1)
	void dequeue(vQueue Q);	//O(1)
	ElementType front(vQueue Q);	//O(1)
	ElementType frontAndDequeue(vQueue Q);	//O(1)
	void deleteQueue(vQueue Q);	//O(N)
};

