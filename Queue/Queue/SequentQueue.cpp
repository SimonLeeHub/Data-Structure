#include "stdafx.h"
#include "SequentQueue.h"


CSequentQueue::CSequentQueue(void)
{
	description = "\n\n\n-------- Sequent Queue --------\n";
}


CSequentQueue::~CSequentQueue(void)
{
}

vQueue CSequentQueue::createQueue()
{
	SQ_Queue SQ = (SQ_Queue)malloc(sizeof(SQ_Node));
	assert(SQ);
	SQ->array = (ElementType*)malloc(sizeof(ElementType)*INIT_QUEUE_CAPACITY);
	assert(SQ->array);
	SQ->capacity = INIT_QUEUE_CAPACITY;
	SQ->front = 0;
	SQ->rear = 0;
	return (vQueue)SQ;
}

bool CSequentQueue::isEmpty(vQueue Q)
{
	SQ_Queue SQ = (SQ_Queue)Q;
	return SQ->front == SQ->rear;
}

bool CSequentQueue::isFull(vQueue Q)
{
	SQ_Queue SQ = (SQ_Queue)Q;
	return (SQ->rear+1)%SQ->capacity == SQ->front;
}

void CSequentQueue::enqueue(ElementType X, vQueue Q)
{
	assert(!isFull(Q));
	SQ_Queue SQ = (SQ_Queue)Q;
	SQ->array[SQ->rear] = X;
	SQ->rear = (SQ->rear+1)%SQ->capacity;
}

void CSequentQueue::dequeue(vQueue Q)
{
	assert(!isEmpty(Q));
	SQ_Queue SQ = (SQ_Queue)Q;
	SQ->front = (SQ->front+1)%SQ->capacity;
}

ElementType CSequentQueue::front(vQueue Q)
{
	assert(!isEmpty(Q));
	SQ_Queue SQ = (SQ_Queue)Q;
	return SQ->array[SQ->front];
}

ElementType CSequentQueue::frontAndDequeue(vQueue Q)
{
	assert(!isEmpty(Q));
	ElementType tempE = front(Q);
	dequeue(Q);
	return tempE;
}
void CSequentQueue::deleteQueue(vQueue Q)
{
	SQ_Queue SQ = (SQ_Queue)Q;
	free(SQ->array);
	free(SQ);
}
