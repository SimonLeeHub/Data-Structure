/*!
* \brief ˳�����
* 
* ������������ɵ�Ԫ��Ϊ����capacity-1��������һ����Ԫ�أ��������пպ�������
* ���в�����ΪO(1),���Ƕ������������ƣ�
* ��ղ����ͷ�����ָ�룬ͬʱҲ�ͷŶ���ָ�룻
* frontΪ��ͷԪ�������±꣬rearΪ��βԪ�ص���һ��Ԫ�ص������±ꡣ
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

