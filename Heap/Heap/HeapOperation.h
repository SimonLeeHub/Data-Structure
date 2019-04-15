/*!
* \brief �ѣ����ȶ��У��Ļ��������ӿ���
* 
* ���������ѣ�1�����пգ�1����������1������ӣ�1�������ȳ��ӣ�1�������ض���Ԫ�أ�1������նѣ�1����ϲ��ѣ�1�������ֻ�������
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

	//������������
	virtual void printQueue(vHeap H) = 0;

	std::string description;
};

