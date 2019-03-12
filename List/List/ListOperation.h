/*!
* \brief 顺序表和链表的接口类 
* 
* 包括初始化（1）、插入（3）、删除（2）、查找（4）、遍历（1）、判空（1）和判尾（1）共13中基本操作 
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

