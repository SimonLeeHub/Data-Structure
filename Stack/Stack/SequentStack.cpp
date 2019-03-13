#include "stdafx.h"
#include "SequentStack.h"


CSequentStack::CSequentStack(void)
{
	description = "\n\n\n-------- Sequent Stack --------\n";
}


CSequentStack::~CSequentStack(void)
{
}

vStack CSequentStack::createStack(void)
{
	SS_Stack SS = (SS_Stack)malloc(sizeof(SS_Node));
	assert(SS);
	SS->array = (ElementType*)malloc(sizeof(ElementType)*INIT_STACK_CAPACITY);
	assert(SS->array);
	SS->capacity = INIT_STACK_CAPACITY;
	SS->topOfStack = -1;
	return (vStack)SS;
}
bool CSequentStack::isEmpty(vStack S)
{
	SS_Stack SS = (SS_Stack)S;
	if(SS->topOfStack < 0) return true;
	return false;
}

bool CSequentStack::isFull(vStack S)
{
	SS_Stack SS = (SS_Stack)S;
	if(SS->topOfStack == SS->capacity-1) return true;
	return false;
}

void CSequentStack::push(ElementType X, vStack S)
{
	SS_Stack SS = (SS_Stack)S;
	if(isFull(S))
	{
		SS->array = (ElementType*)realloc(SS->array, sizeof(ElementType)*(SS->capacity+1));
		assert(SS->array);
		SS->capacity++;
	}
	SS->array[++SS->topOfStack] = X;
}

void CSequentStack::pop(vStack S)
{
	assert(!isEmpty(S));
	SS_Stack SS = (SS_Stack)S;
	SS->topOfStack--;
}

ElementType CSequentStack::top(vStack S)
{
	assert(!isEmpty(S));
	SS_Stack SS = (SS_Stack)S;
	return SS->array[SS->topOfStack];
}

ElementType CSequentStack::topAndPop(vStack S)
{
	assert(!isEmpty(S));
	ElementType tempE = top(S);
	pop(S);
	return tempE;
}

void CSequentStack::deleteStack(vStack S)
{
	SS_Stack SS = (SS_Stack)S;
	free(SS->array);
	free(SS);
}
