#include "stdafx.h"
#include "DoubleLinkedList.h"


CDoubleLinkedList::CDoubleLinkedList(void)
{
	description = "\n\n\n-------- Double Linked List --------\n";
}


CDoubleLinkedList::~CDoubleLinkedList(void)
{
}

vList CDoubleLinkedList::createList(void)
{
	DLL_List DLL = (DLL_List)malloc(sizeof(DLL_Node));
	assert(DLL);
	DLL->previous = NULL;
	DLL->next = NULL;
	return (vList)DLL;
}

bool CDoubleLinkedList::isEmpty(vList L)
{
	DLL_List DLL = (DLL_List)L;
	if(!(DLL->next)) return true;
	return false;
}

bool CDoubleLinkedList::isLast(vPosition P, vList L)
{
	DLL_Position pos = (DLL_Position)P;
	if(pos->next == NULL) return true;
	return false;
}

vPosition CDoubleLinkedList::findLast(vList L)
{
	DLL_List DLL = (DLL_List)L;
	DLL_Position tempPos = DLL;
	while(tempPos ->next) tempPos = tempPos->next;
	return (vPosition)tempPos;
}

vPosition CDoubleLinkedList::find(ElementType X, vList L)
{
	DLL_List DLL = (DLL_List)L;
	DLL_Position tempPos = DLL->next;
	while((tempPos != NULL) && (tempPos->element != X)) tempPos = tempPos->next;
	return (vPosition)tempPos;
}

vPosition CDoubleLinkedList::findPrevious(ElementType X, vList L)
{
	DLL_Position pos = (DLL_Position)find(X, L);
	assert(pos);
	return (vPosition)(pos->previous);
}

vPosition CDoubleLinkedList::findNext(ElementType X, vList L)
{
	DLL_Position pos = (DLL_Position)find(X, L);
	assert(pos);
	return (vPosition)(pos->next);
}

void CDoubleLinkedList::insertLast(ElementType X, vList L)
{
	DLL_Position pos = (DLL_Position)findLast(L);
	pos->next = (DLL_Position)malloc(sizeof(DLL_Node));
	assert(pos->next);
	pos->next->element = X;
	pos->next->next = NULL;
	pos->next->previous = pos;
}

void CDoubleLinkedList::insertBefore(ElementType X, vPosition p, vList L)
{
	DLL_Position pos = (DLL_Position)p;
	DLL_Position tempPos = (DLL_Position)malloc(sizeof(DLL_Node));
	assert(tempPos);
	tempPos->element = X;
	tempPos->previous = pos->previous;
	tempPos->next = pos;
	pos->previous->next = tempPos;
	pos->previous = tempPos;
}

void CDoubleLinkedList::insertAfter(ElementType X, vPosition p, vList L)
{
	DLL_Position pos = (DLL_Position)p;
	DLL_Position tempPos = (DLL_Position)malloc(sizeof(DLL_Node));
	assert(tempPos);
	tempPos->element = X;
	tempPos->next = pos->next;
	tempPos->previous = pos;
	pos->next = tempPos;
	if(tempPos->next)
	{
		tempPos->next->previous = tempPos;
	}
}

void CDoubleLinkedList::printList(vList L)
{
	DLL_List DLL = (DLL_List)L;
	DLL_Position tempPos = DLL->next;
	while(tempPos)
	{
		std::cout<<tempPos->element<<" ";
		tempPos = tempPos->next;
	}
	std::cout<<std::endl;
}

void CDoubleLinkedList::deleteX(ElementType X, vList L)
{
	DLL_Position pos = (DLL_Position)find(X, L);
	assert(pos);
	if(isLast(pos, L))
	{
		pos->previous->next = NULL;
	}
	else
	{
		pos->previous->next = pos->next;
		pos->next->previous = pos->previous;
		
	}
	free(pos);
}

void CDoubleLinkedList::deleteList(vList L)
{
	DLL_List DLL = (DLL_List)L;
	DLL_Position tempPos = DLL->next;
	while(tempPos)
	{
		DLL->next = tempPos->next;
		free(tempPos);
		tempPos = DLL->next;
	}
}
