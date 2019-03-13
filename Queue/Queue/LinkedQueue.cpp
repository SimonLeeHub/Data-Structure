#include "stdafx.h"
#include "LinkedQueue.h"


CLinkedQueue::CLinkedQueue(void)
{
	description = "\n\n\n-------- Linked Queue --------\n";
}


CLinkedQueue::~CLinkedQueue(void)
{
}

vQueue CLinkedQueue::createQueue()
{
	LQ_Queue LQ = (LQ_Queue)malloc(sizeof(LQ_Info));
	assert(LQ);
	LQ->front = LQ->rear = (LQ_Position)malloc(sizeof(LQ_Node));
	assert(LQ->front);
	LQ->front->next = NULL;
	return (vQueue)LQ;
}

bool CLinkedQueue::isEmpty(vQueue Q)
{
	LQ_Queue LQ = (LQ_Queue)Q;
	if(LQ->front == LQ->rear) return true;
	return false;
}

bool CLinkedQueue::isFull(vQueue Q)
{
	return false;
}

void CLinkedQueue::enqueue(ElementType X, vQueue Q)
{
	LQ_Queue LQ = (LQ_Queue)Q;
	LQ_Position pos = (LQ_Position)malloc(sizeof(LQ_Node));
	assert(pos);
	pos->element = X;
	pos->next = NULL;
	LQ->rear->next = pos;
	LQ->rear = pos;
}

void CLinkedQueue::dequeue(vQueue Q)
{
	assert(!isEmpty(Q));
	LQ_Queue LQ = (LQ_Queue)Q;
	LQ_Position pos = LQ->front->next;
	LQ->front->next = LQ->front->next->next;
	if(pos == LQ->rear) LQ->rear = LQ->front;
	free(pos);
}

ElementType CLinkedQueue::front(vQueue Q)
{
	assert(!isEmpty(Q));
	LQ_Queue LQ = (LQ_Queue)Q;
	return LQ->front->next->element;
}

ElementType CLinkedQueue::frontAndDequeue(vQueue Q)
{
	assert(!isEmpty(Q));
	ElementType tempE = front(Q);
	dequeue(Q);
	return tempE;
}

void CLinkedQueue::deleteQueue(vQueue Q)
{
	LQ_Queue LQ = (LQ_Queue)Q;
	LQ_Position tempPos = LQ->front->next;
	while(tempPos)
	{
		LQ->front->next = tempPos->next;
		free(tempPos);
		tempPos = LQ->front->next;
	}
	LQ->rear = LQ->front;
}
