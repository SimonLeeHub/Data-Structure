/*!
* \brief ���л��������ӿ���
* 
* ������ʼ����1������ӣ�1�������ӣ�1������ͷԪ�أ�1������ͷԪ�ز����ӣ�1������ն��У�1���Լ��пգ�1����������1����8�ֻ������� 
* 
* \author Lee 
* \date 2019.03.13
*/
#pragma once
typedef int ElementType;
typedef void *vQueue;
class CQueueOperation
{
public:
	CQueueOperation(void);
	virtual ~CQueueOperation(void);
	virtual vQueue createQueue() = 0;    //�����ն���
	virtual bool isEmpty(vQueue Q) = 0;    //�ж϶����Ƿ�Ϊ��
	virtual bool isFull(vQueue Q) = 0;   //�ж϶����Ƿ�����
	virtual void enqueue(ElementType X, vQueue Q) = 0;    //���
	virtual void dequeue(vQueue Q) = 0;    //����
	virtual ElementType front(vQueue Q) = 0;    //���ض�ͷԪ��
	virtual ElementType frontAndDequeue(vQueue Q) = 0;    //���ض�ͷԪ�ز�����
	virtual void deleteQueue(vQueue Q) = 0;    //��ն���

public:
	std::string description;
};

