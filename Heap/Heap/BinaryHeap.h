/*!
* \brief �������
* 
* ��������ʵ�֣�����ѵ����size��capacityС1
* ��Ϊarray[0]Ϊ��ǽڵ㣬������Ӳ�����ÿ��ѭ������һ���ж�
* 
* \author Lee 
* \date 2019.04.02
*/
#pragma once
#include "heapoperation.h"
#define INITCAPACITY 11
struct HeapStruct
{
	int capacity;
	int size;
	ElementType *array;
};
typedef HeapStruct *BH_Heap;
class CBinaryHeap :
	public CHeapOperation
{
public:
	CBinaryHeap(void);
	~CBinaryHeap(void);

	vHeap createQueue();	//O(1)
	bool isEmpty(vHeap H);	//O(1)
	bool isFull(vHeap H);	//O(1)
	vHeap enqueue(ElementType X, vHeap H);	//O(logN)
	vHeap dequeue(vHeap H);	//O(logN)
	ElementType front(vHeap H);	//O(1)
	void deleteQueue(vHeap H);	//O(1)
	vHeap merge(vHeap H1, vHeap H2);	//O(N1logN2)��O(N1+N2)
	vHeap buildHeap(ElementType *array, int len);	//O(N)

	//������������
	void printQueue(vHeap H);
};

