#include "stdafx.h"
#include "SingleCircleLinkedList.h"


CSingleCircleLinkedList::CSingleCircleLinkedList(void)
{
	description = "\n\n\n-------- Single Circle Linked List --------\n";
}


CSingleCircleLinkedList::~CSingleCircleLinkedList(void)
{
}

vList CSingleCircleLinkedList::createList(void)
{
	SCLL_List SCLL = (SCLL_List)malloc(sizeof(SCLL_Node));
	assert(SCLL);
	SCLL->next = SCLL;
	return (vList)SCLL;
}

bool CSingleCircleLinkedList::isEmpty(vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	if(SCLL->next == SCLL) return true;
	return false;
}

bool CSingleCircleLinkedList::isLast(vPosition P, vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position pos = (SCLL_Position)P;
	if(pos->next == SCLL) return true;
	return false;
}

vPosition CSingleCircleLinkedList::findLast(vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position tempPos = SCLL;
	while(tempPos ->next != SCLL) tempPos = tempPos->next;
	return (vPosition)tempPos;
}

vPosition CSingleCircleLinkedList::find(ElementType X, vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position tempPos = SCLL->next;
	while((tempPos != SCLL) && (tempPos->element != X)) tempPos = tempPos->next;
	if(tempPos == SCLL) return NULL;
	return (vPosition)tempPos;
}

vPosition CSingleCircleLinkedList::findPrevious(ElementType X, vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position tempPos = SCLL;
	while((tempPos ->next != SCLL) && (tempPos->next->element != X)) tempPos = tempPos->next;
	if(!isLast(tempPos, L)) return (vPosition)tempPos;
	return NULL;
}

vPosition CSingleCircleLinkedList::findNext(ElementType X, vList L)
{
	SCLL_Position pos = (SCLL_Position)find(X, L);
	assert(pos);
	return pos->next;
}

void CSingleCircleLinkedList::insertLast(ElementType X, vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position pos = (SCLL_Position)findLast(L);
	pos->next = (SCLL_Position)malloc(sizeof(SCLL_Node));
	assert(pos->next);
	pos->next->element = X;
	pos->next->next = SCLL;
}

void CSingleCircleLinkedList::insertBefore(ElementType X, vPosition p, vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position pos = (SCLL_Position)p;
	SCLL_Position previousPos = SCLL;
	while((previousPos->next != SCLL) && (previousPos->next != pos)) previousPos = previousPos->next;
	if(isLast(previousPos, L)) previousPos = NULL;
	assert(previousPos);
	previousPos->next = (SCLL_Position)malloc(sizeof(SCLL_Node));
	assert(previousPos->next);
	previousPos->next->element = X;
	previousPos->next->next = pos;
}

void CSingleCircleLinkedList::insertAfter(ElementType X, vPosition p, vList L)
{
	SCLL_Position pos = (SCLL_Position)p;
	SCLL_Position tempPos = (SCLL_Position)malloc(sizeof(SCLL_Node));
	assert(tempPos);
	tempPos->element = X;
	tempPos->next = pos->next;
	pos->next = tempPos;
}

void CSingleCircleLinkedList::printList(vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position tempPos = SCLL->next;
	while(tempPos != SCLL)
	{
		std::cout<<tempPos->element<<" ";
		tempPos = tempPos->next;
	}
	std::cout<<std::endl;
}

void CSingleCircleLinkedList::deleteX(ElementType X, vList L)
{
	SCLL_Position pos = (SCLL_Position)findPrevious(X, L);
	assert(pos);
	SCLL_Position tempPos = pos->next;
	pos->next = pos->next->next;
	free(tempPos);
}

void CSingleCircleLinkedList::deleteList(vList L)
{
	SCLL_List SCLL = (SCLL_List)L;
	SCLL_Position tempPos = SCLL->next;
	while(tempPos != SCLL)
	{
		SCLL->next = tempPos->next;
		free(tempPos);
		tempPos = SCLL->next;
	}
}
