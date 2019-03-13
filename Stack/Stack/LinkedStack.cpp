#include "stdafx.h"
#include "LinkedStack.h"


CLinkedStack::CLinkedStack(void)
{
	description = "\n\n\n-------- Linked Stack --------\n";
}


CLinkedStack::~CLinkedStack(void)
{
}

vStack CLinkedStack::createStack(void)
{
	LS_Stack LS = (LS_Stack)malloc(sizeof(LS_Node));
	assert(LS);
	LS->next = NULL;
	return (vStack)LS;
}

bool CLinkedStack::isEmpty(vStack S)
{
	LS_Stack LS = (LS_Stack)S;
	if(LS->next) return false;
	return true;
}

bool CLinkedStack::isFull(vStack S)
{
	return false;
}

void CLinkedStack::push(ElementType X, vStack S)
{
	LS_Stack LS = (LS_Stack)S;
	LS_Position pos = (LS_Position)malloc(sizeof(LS_Node));
	assert(pos);
	pos->element = X;
	pos->next = LS->next;
	LS->next = pos;
}

void CLinkedStack::pop(vStack S)
{
	assert(!isEmpty(S));
	LS_Stack LS = (LS_Stack)S;
	LS_Position pos = LS->next;
	LS->next = pos->next;
	free(pos);
}

ElementType CLinkedStack::top(vStack S)
{
	assert(!isEmpty(S));
	LS_Stack LS = (LS_Stack)S;
	return LS->next->element;
}

ElementType CLinkedStack::topAndPop(vStack S)
{
	assert(!isEmpty(S));
	ElementType tempE = top(S);
	pop(S);
	return tempE;
}

void CLinkedStack::deleteStack(vStack S)
{
	LS_Stack LS = (LS_Stack)S;
	LS_Position tempPos = LS->next;
	while(tempPos)
	{
		LS->next = tempPos->next;
		free(tempPos);
		tempPos = LS->next;
	}
}
