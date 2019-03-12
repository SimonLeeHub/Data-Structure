/*!
* \brief 双向循环链表类 
* 
* 带有头结点的双向循环链表
*
* \author Lee
* \date 2019.03.12
*/
#pragma once
#include "listoperation.h"
struct DCLL_Node;
typedef DCLL_Node *DCLL_Position;
typedef DCLL_Node *DCLL_List;
struct DCLL_Node
{
	ElementType element;
	DCLL_Position previous;
	DCLL_Position next;
};
class CDoubleCircleLinkedList :
	public CListOperation
{
public:
	CDoubleCircleLinkedList(void);
	~CDoubleCircleLinkedList(void);

	vList createList(void);
	bool isEmpty(vList L);	//O(1)
	bool isLast(vPosition P, vList L);//O(1)
	vPosition findLast(vList L);	//O(1)
	vPosition find(ElementType X, vList L);	//O(N)
	vPosition findPrevious(ElementType X, vList L);	//O(N)
	vPosition findNext(ElementType X, vList L);	//O(N)
	void insertLast(ElementType X, vList L);	//O(1)
	void insertBefore(ElementType X, vPosition p, vList L);	//O(1)
	void insertAfter(ElementType X, vPosition p, vList L);	//O(1)
	void printList(vList L);	//O(N)
	void deleteX(ElementType X, vList L);	//O(N)
	void deleteList(vList L);	//O(N)
};

