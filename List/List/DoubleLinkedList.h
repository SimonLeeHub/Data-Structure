/*!
* \brief 双向链表类 
* 
* 带有头结点的双向链表
*
* \author Lee
* \date 2019.03.12
*/
#pragma once
#include "listoperation.h"
struct DLL_Node;
typedef DLL_Node *DLL_Position;
typedef DLL_Node *DLL_List;
struct DLL_Node
{
	ElementType element;
	DLL_Position previous;
	DLL_Position next;
};
class CDoubleLinkedList :
	public CListOperation
{
public:
	CDoubleLinkedList(void);
	~CDoubleLinkedList(void);
	vList createList(void);
	bool isEmpty(vList L);	//O(1)
	bool isLast(vPosition P, vList L);	//O(1)
	vPosition findLast(vList L);	//O(N)
	vPosition find(ElementType X, vList L);	//O(N)
	vPosition findPrevious(ElementType X, vList L);	//O(N)
	vPosition findNext(ElementType X, vList L);	//O(N)
	void insertLast(ElementType X, vList L);	//O(N)
	void insertBefore(ElementType X, vPosition p, vList L);	//O(1)
	void insertAfter(ElementType X, vPosition p, vList L);	//O(1)
	void printList(vList L);	//O(N)
	void deleteX(ElementType X, vList L);	//O(N)
	void deleteList(vList L);	//O(N)
};

