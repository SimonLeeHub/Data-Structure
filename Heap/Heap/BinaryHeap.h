/*!
* \brief 二叉堆类
* 
* 采用数组实现，二叉堆的最大size比capacity小1
* 因为array[0]为标记节点，方便入队操作，每次循环减少一次判断
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
	vHeap merge(vHeap H1, vHeap H2);	//O(N1logN2)或O(N1+N2)
	vHeap buildHeap(ElementType *array, int len);	//O(N)

	//基本辅助操作
	void printQueue(vHeap H);
};

