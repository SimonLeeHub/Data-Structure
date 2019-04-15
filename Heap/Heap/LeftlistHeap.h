/*!
* \brief ��ʽ����
* 
* ���ö������ṹʵ��
* ���ڵ��а���ÿ���ڵ����·��������Ϣ
* ����ڶ���ѣ���ʽ�Ѻϲ����죨O(logN)��,�������Ϊ��O(N)��
* 
* \author Lee 
* \date 2019.04.02
*/
#pragma once
#include "heapoperation.h"
struct LH_Node;
typedef LH_Node *LH_Position;
typedef LH_Node *LH_Heap;
struct LH_Node
{
	ElementType element;
	LH_Heap left;
	LH_Heap right;
	int NPL;
};

struct GraphicPrintNode
{
	ElementType element;
	bool isEmpty;
};
class CLeftlistHeap :
	public CHeapOperation
{
public:
	CLeftlistHeap(void);
	~CLeftlistHeap(void);

	vHeap createQueue();	//O(1)
	bool isEmpty(vHeap H);	//O(1)
	bool isFull(vHeap H);	//O(1)
	vHeap enqueue(ElementType X, vHeap H);	//O(logN)
	vHeap dequeue(vHeap H);	//O(logN)
	ElementType front(vHeap H);	//O(1)
	void deleteQueue(vHeap H);	//O(N)
	vHeap merge(vHeap H1, vHeap H2);	//O(logN)
	vHeap buildHeap(ElementType *array, int len);	//O(N)

	//������������
	void printQueue(vHeap H);

	//��������
	LH_Heap merge1(LH_Heap LH1, LH_Heap LH2);
	int heapHeight(LH_Heap LH);
	void fillTable(LH_Heap LH, int curHeight);

	GraphicPrintNode **table;
	int colNum, THeight;
};

