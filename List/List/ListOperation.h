/*!
* \brief ˳��������Ľӿ��� 
* 
* ������ʼ����1�������루3����ɾ����2�������ң�4����������1�����пգ�1������β��1����13�л������� 
* 
* \author Lee
* \date 2019.03.12
*/
#pragma once
typedef void* vPosition;
typedef void* vList;
typedef int ElementType;
class CListOperation
{
public:
	CListOperation(void);
	virtual ~CListOperation(void);
	virtual vList createList(void) = 0;
	virtual bool isEmpty(vList L) = 0;
	virtual bool isLast(vPosition P, vList L) = 0;
	virtual vPosition findLast(vList L) = 0; 
	virtual vPosition find(ElementType X, vList L) = 0;
	virtual vPosition findPrevious(ElementType X, vList L) = 0;
	virtual vPosition findNext(ElementType X, vList L) = 0;
	virtual void insertLast(ElementType X, vList L) = 0;
	virtual void insertBefore(ElementType X, vPosition p, vList L) = 0;
	virtual void insertAfter(ElementType X, vPosition p, vList L) = 0;
	virtual void printList(vList L) = 0;
	virtual void deleteX(ElementType X, vList L) = 0;
	virtual void deleteList(vList L) = 0;

public:
	std::string description;
};

