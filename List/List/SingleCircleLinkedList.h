/*!
* \brief 单向循环链表类 
* 
* 带有头结点的单向循环链表
*
* \author Lee
* \date 2019.03.12
*/
#pragma once
#include "listoperation.h"
struct SCLL_Node;
typedef SCLL_Node *SCLL_Position;
typedef SCLL_Node *SCLL_List;
struct SCLL_Node
{
	ElementType element;
	SCLL_Position next;
};
class CSingleCircleLinkedList :
	public CListOperation
{
public:
	CSingleCircleLinkedList(void);
	~CSingleCircleLinkedList(void);
	vList createList(void);
	bool isEmpty(vList L);	//O(1)
	bool isLast(vPosition P, vList L);	//O(1)
	vPosition findLast(vList L);	//O(N)
	vPosition find(ElementType X, vList L);	//O(N)
	vPosition findPrevious(ElementType X, vList L);	//O(N)
	vPosition findNext(ElementType X, vList L);	//O(N)
	void insertLast(ElementType X, vList L);	//O(N)
	void insertBefore(ElementType X, vPosition p, vList L);	//O(N)
	void insertAfter(ElementType X, vPosition p, vList L);	//O(1)
	void printList(vList L);	//O(N)
	void deleteX(ElementType X, vList L);	//O(N)
	void deleteList(vList L);	//O(N)
};

