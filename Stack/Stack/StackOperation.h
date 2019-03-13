/*!
* \brief ջ���������ӿ���
* 
* ������ʼ����1����ѹջ��1����ջ����1������ջ��1����ջ������ջ��1�����пգ�1����������1���Լ�ɾ��ջ��1����8����������
* 
* \author Lee
* \date 2019.03.13
*/
#pragma once
typedef int ElementType;
typedef void *vStack;
class CStackOperation
{
public:
	CStackOperation(void);
	virtual ~CStackOperation(void);
	virtual vStack createStack(void) = 0;	//����ջ
	virtual bool isEmpty(vStack S) = 0;	//�ж�ջ�Ƿ�Ϊ��
	virtual bool isFull(vStack S) = 0;	//�ж�ջ�Ƿ�����
	virtual void push(ElementType X, vStack S) = 0;	//ѹջ
	virtual void pop(vStack S) = 0;	//��ջ
	virtual ElementType top(vStack S) = 0;	 //����ջ��Ԫ��
	virtual ElementType topAndPop(vStack S) = 0;	//����ջ��Ԫ�ز���ջ
	virtual void deleteStack(vStack S) = 0;	//���ջ

public:
	std::string description;
};

