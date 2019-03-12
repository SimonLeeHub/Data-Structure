/*!
* \brief 单向链表类 
* 
* 带有头结点的单向链表
*
* \author Lee
* \date 2019.03.12
*/
#pragma once
#include "listoperation.h"
struct SLL_Node;
typedef SLL_Node *SLL_Position;
typedef SLL_Node *SLL_List;
struct SLL_Node
{
	ElementType element;
	SLL_Position next;
};
class CSingleLinkedList :
	public CListOperation
{
public:
	CSingleLinkedList(void);
	~CSingleLinkedList(void);
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

