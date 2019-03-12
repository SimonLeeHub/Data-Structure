#include "stdafx.h"
#include "SequentList.h"


CSequentList::CSequentList(void)
{
	description = "\n\n\n-------- Sequent List --------\n";
}


CSequentList::~CSequentList(void)
{
}

vList CSequentList::createList(void)
{
	SL_List SL = (SL_List)malloc(sizeof(SL_Node));
	assert(SL);
	SL->array = (ElementType*)malloc(sizeof(ElementType)*INIT_CAPACITY);
	assert(SL->array);
	SL->capacity = INIT_CAPACITY;
	SL->size = 0;
	return (vList)SL;
}

bool CSequentList::isEmpty(vList L)
{
	SL_List SL = (SL_List)L;
	if(SL->size == 0) return true;
	return false;
}

bool CSequentList::isLast(vPosition P, vList L)
{
	SL_List SL = (SL_List)L;
	if(((SL_Position)P-SL->array) / sizeof(ElementType) == (SL->size -1)) return true;
	return false;
}

vPosition CSequentList::findLast(vList L)
{
	SL_List SL = (SL_List)L;
	return (vPosition)(SL->array+sizeof(ElementType)*(SL->size-1));
}

vPosition CSequentList::find(ElementType X, vList L)
{
	SL_List SL = (SL_List)L;
	for(int i=0;i<SL->size;i++)
	{
		if(SL->array[i] == X)
		{
			return (vPosition)(SL->array + sizeof(ElementType)*i);
		}
	}
	return NULL;
}

vPosition CSequentList::findPrevious(ElementType X, vList L)
{
	SL_List SL = (SL_List)L;
	SL_Position pos = (SL_Position)find(X,L);
	if(pos)
	{
		if(pos != SL->array)
		{
			return (vPosition)(pos-sizeof(ElementType));
		}
	}
	return NULL;
}

vPosition CSequentList::findNext(ElementType X, vList L)
{
	SL_List SL = (SL_List)L;
	SL_Position pos = (SL_Position)find(X,L);
	if(pos)
	{
		if(pos != SL->array+sizeof(ElementType)*(SL->size-1))
		{
			return (vPosition)(pos+sizeof(ElementType));
		}
	}
	return NULL;
}

void CSequentList::insertLast(ElementType X, vList L)
{
	SL_List SL = (SL_List)L;
	if(SL->size == SL->capacity)
	{
		SL->array = (ElementType*)realloc(SL->array, sizeof(ElementType)*(SL->capacity+1));
		assert(SL->array);
		SL->capacity++;
	}
	SL->size++;
	SL->array[SL->size-1] = X;
}

void CSequentList::insertBefore(ElementType X, vPosition p, vList L)
{
	SL_List SL = (SL_List)L;
	SL_Position pos = (SL_Position)p;
	assert(pos>=SL->array);
	assert(pos<=(SL->array+(sizeof(ElementType)*(SL->size-1))));
	int iPos = (pos-SL->array)/(sizeof(ElementType));
	if(SL->size == SL->capacity)
	{
		SL->array = (ElementType*)realloc(SL->array, sizeof(ElementType)*(SL->capacity+1));
		assert(SL->array);
		SL->capacity++;
	}
	SL->size++;
	for(int i=SL->size-1;i>iPos;i--)
	{
		SL->array[i] = SL->array[i-1];
	}
	SL->array[iPos] = X;
}

void CSequentList::insertAfter(ElementType X, vPosition p, vList L)
{
	SL_List SL = (SL_List)L;
	SL_Position pos = (SL_Position)p;
	assert(pos>=SL->array);
	assert(pos<=(SL->array+(sizeof(ElementType)*(SL->size-1))));
	int iPos = (pos-SL->array)/(sizeof(ElementType));
	if(SL->size == SL->capacity)
	{
		SL->array = (ElementType*)realloc(SL->array, sizeof(ElementType)*(SL->capacity+1));
		assert(SL->array);
		SL->capacity++;
	}
	SL->size++;
	for(int i=SL->size-1;i>iPos+1;i--)
	{
		SL->array[i] = SL->array[i-1];
	}
	SL->array[iPos+1] = X;
}

void CSequentList::printList(vList L)
{
	SL_List SL = (SL_List)L;
	if(!SL) return;
	for(int i=0; i<SL->size; i++)
	{
		std::cout<<SL->array[i]<<" ";
	}
	std::cout<<std::endl;
}

void CSequentList::deleteX(ElementType X, vList L)
{
	SL_List SL = (SL_List)L;
	SL_Position pos = (SL_Position)find(X,L);
	if(pos)
	{
		int iPos = (pos-SL->array)/(sizeof(ElementType));
		for(int i=iPos;i<SL->size-1;i++)
		{
			SL->array[i] = SL->array[i+1];
		}
		SL->size--;
	}
}

void CSequentList::deleteList(vList L)
{
	SL_List SL = (SL_List)L;
	if(SL)
	{
		free(SL->array);
		SL->array = NULL;
		free(SL);
		SL = NULL;
	}
}
