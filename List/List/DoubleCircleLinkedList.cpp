#include "stdafx.h"
#include "DoubleCircleLinkedList.h"


CDoubleCircleLinkedList::CDoubleCircleLinkedList(void)
{
	description = "\n\n\n-------- Double Circle Linked List --------\n";
}


CDoubleCircleLinkedList::~CDoubleCircleLinkedList(void)
{
}

vList CDoubleCircleLinkedList::createList(void)
{
	DCLL_List DCLL = (DCLL_List)malloc(sizeof(DCLL_Node));
	assert(DCLL);
	DCLL->previous = DCLL;
	DCLL->next = DCLL;
	return (vList)DCLL;
}

bool CDoubleCircleLinkedList::isEmpty(vList L)
{
	DCLL_List DCLL = (DCLL_List)L;
	if(DCLL->next == DCLL) return true;
	return false;
}

bool CDoubleCircleLinkedList::isLast(vPosition P, vList L)
{
	DCLL_List DCLL = (DCLL_List)L;
	DCLL_Position pos = (DCLL_Position)P;
	if(pos->next == DCLL) return true;
	return false;
}

vPosition CDoubleCircleLinkedList::findLast(vList L)
{
	DCLL_List DCLL = (DCLL_List)L;
	DCLL_Position tempPos = DCLL;
	while(tempPos->next != DCLL) tempPos = tempPos->next;
	return (vPosition)tempPos;
}

vPosition CDoubleCircleLinkedList::find(ElementType X, vList L)
{
	DCLL_List DCLL = (DCLL_List)L;
	DCLL_Position tempPos = DCLL->next;
	while((tempPos != DCLL) && (tempPos->element != X)) tempPos = tempPos->next;
	if(tempPos == DCLL) return NULL;
	return (vPosition)tempPos;
}

vPosition CDoubleCircleLinkedList::findPrevious(ElementType X, vList L)
{
	DCLL_Position pos = (DCLL_Position)find(X, L);
	assert(pos);
	return (vPosition)(pos->previous);
}

vPosition CDoubleCircleLinkedList::findNext(ElementType X, vList L)
{
	DCLL_Position pos = (DCLL_Position)find(X, L);
	assert(pos);
	return (vPosition)(pos->next);
}

void CDoubleCircleLinkedList::insertLast(ElementType X, vList L)
{
	DCLL_List DCLL = (DCLL_List)L;
	DCLL_Position pos = (DCLL_Position)findLast(L);
	pos->next = (DCLL_Position)malloc(sizeof(DCLL_Node));
	assert(pos->next);
	pos->next->element = X;
	pos->next->next = DCLL;
	pos->next->previous = pos;
	DCLL->previous = pos->next;
}

void CDoubleCircleLinkedList::insertBefore(ElementType X, vPosition p, vList L)
{
	DCLL_Position pos = (DCLL_Position)p;
	DCLL_Position tempPos = (DCLL_Position)malloc(sizeof(DCLL_Node));
	assert(tempPos);
	tempPos->element = X;
	tempPos->previous = pos->previous;
	tempPos->next = pos;
	pos->previous->next = tempPos;
	pos->previous = tempPos;
}

void CDoubleCircleLinkedList::insertAfter(ElementType X, vPosition p, vList L)
{
	DCLL_Position pos = (DCLL_Position)p;
	DCLL_Position tempPos = (DCLL_Position)malloc(sizeof(DCLL_Node));
	assert(tempPos);
	tempPos->element = X;
	tempPos->next = pos->next;
	tempPos->previous = pos;
	pos->next = tempPos;
	tempPos->next->previous = tempPos;
}

void CDoubleCircleLinkedList::printList(vList L)
{
	DCLL_List DCLL = (DCLL_List)L;
	DCLL_Position tempPos = DCLL->next;
	while(tempPos != DCLL)
	{
		std::cout<<tempPos->element<<" ";
		tempPos = tempPos->next;
	}
	std::cout<<std::endl;
}

void CDoubleCircleLinkedList::deleteX(ElementType X, vList L)
{
	DCLL_Position pos = (DCLL_Position)find(X, L);
	assert(pos);
	pos->previous->next = pos->next;
	pos->next->previous = pos->previous;
	free(pos);
}

void CDoubleCircleLinkedList::deleteList(vList L)
{
	DCLL_List DCLL = (DCLL_List)L;
	DCLL_Position tempPos = DCLL->next;
	while(tempPos != DCLL)
	{
		DCLL->next = tempPos->next;
		free(tempPos);
		tempPos = DCLL->next;
	}
}
