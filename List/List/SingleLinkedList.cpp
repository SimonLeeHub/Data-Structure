#include "stdafx.h"
#include "SingleLinkedList.h"


CSingleLinkedList::CSingleLinkedList(void)
{
	description = "\n\n\n-------- Single Linked List --------\n";
}


CSingleLinkedList::~CSingleLinkedList(void)
{
}

vList CSingleLinkedList::createList(void)
{
	SLL_List SLL = (SLL_List)malloc(sizeof(SLL_Node));
	assert(SLL);
	SLL->next = NULL;
	return (vList)SLL;
}

bool CSingleLinkedList::isEmpty(vList L)
{
	SLL_List SLL = (SLL_List)L;
	if(!(SLL->next)) return true;
	return false;
}

bool CSingleLinkedList::isLast(vPosition P, vList L)
{
	SLL_Position pos = (SLL_Position)P;
	if(pos->next == NULL) return true;
	return false;
}

vPosition CSingleLinkedList::findLast(vList L)
{
	SLL_List SLL = (SLL_List)L;
	SLL_Position tempPos = SLL;
	while(tempPos ->next) tempPos = tempPos->next;
	return (vPosition)tempPos;
}

vPosition CSingleLinkedList::find(ElementType X, vList L)
{
	SLL_List SLL = (SLL_List)L;
	SLL_Position tempPos = SLL->next;
	while((tempPos != NULL) && (tempPos->element != X)) tempPos = tempPos->next;
	return (vPosition)tempPos;
}

vPosition CSingleLinkedList::findPrevious(ElementType X, vList L)
{
	SLL_List SLL = (SLL_List)L;
	SLL_Position tempPos = SLL;
	while((tempPos ->next != NULL) && (tempPos->next->element != X)) tempPos = tempPos->next;
	if(!isLast(tempPos, L)) return (vPosition)tempPos;
	return NULL;
}

vPosition CSingleLinkedList::findNext(ElementType X, vList L)
{
	SLL_Position pos = (SLL_Position)find(X, L);
	assert(pos);
	return pos->next;
}

void CSingleLinkedList::insertLast(ElementType X, vList L)
{
	SLL_Position pos = (SLL_Position)findLast(L);
	pos->next = (SLL_Position)malloc(sizeof(SLL_Node));
	assert(pos->next);
	pos->next->element = X;
	pos->next->next = NULL;
}

void CSingleLinkedList::insertBefore(ElementType X, vPosition p, vList L)
{
	SLL_List SLL = (SLL_List)L;
	SLL_Position pos = (SLL_Position)p;
	SLL_Position previousPos = SLL;
	while((previousPos->next) && (previousPos->next != pos)) previousPos = previousPos->next;
	if(isLast(previousPos, L)) previousPos = NULL;
	assert(previousPos);
	previousPos->next = (SLL_Position)malloc(sizeof(SLL_Node));
	assert(previousPos->next);
	previousPos->next->element = X;
	previousPos->next->next = pos;
}

void CSingleLinkedList::insertAfter(ElementType X, vPosition p, vList L)
{
	SLL_Position pos = (SLL_Position)p;
	SLL_Position tempPos = (SLL_Position)malloc(sizeof(SLL_Node));
	assert(tempPos);
	tempPos->element = X;
	tempPos->next = pos->next;
	pos->next = tempPos;
}

void CSingleLinkedList::printList(vList L)
{
	SLL_List SLL = (SLL_List)L;
	SLL_Position tempPos = SLL->next;
	while(tempPos)
	{
		std::cout<<tempPos->element<<" ";
		tempPos = tempPos->next;
	}
	std::cout<<std::endl;
}

void CSingleLinkedList::deleteX(ElementType X, vList L)
{
	SLL_Position pos = (SLL_Position)findPrevious(X, L);
	assert(pos);
	SLL_Position tempPos = pos->next;
	pos->next = pos->next->next;
	free(tempPos);
}

void CSingleLinkedList::deleteList(vList L)
{
	SLL_List SLL = (SLL_List)L;
	SLL_Position tempPos = SLL->next;
	while(tempPos)
	{
		SLL->next = tempPos->next;
		free(tempPos);
		tempPos = SLL->next;
	}
}
