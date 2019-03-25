#include "stdafx.h"
#include "SeparateChaining.h"


CSeparateChaining::CSeparateChaining(void)
{
	description = "\n\n\n-------- Separate Chaining --------\n";
}


CSeparateChaining::~CSeparateChaining(void)
{
}

vHashTable CSeparateChaining::create(int tableSize)
{
	assert(tableSize>0);
	SC_HashTable SCHT = (SC_HashTable)malloc(sizeof(SC_HashTableNode));
	assert(SCHT);
	SCHT->tableSize = nextPrime(tableSize);
	SCHT->theLists = (SC_List*)malloc(sizeof(SC_List)*SCHT->tableSize);
	assert(SCHT->theLists);
	for(int i=0;i<SCHT->tableSize;i++)
	{
		SCHT->theLists[i] = (SC_List)malloc(sizeof(SC_ListNode));
		assert(SCHT->theLists[i]);
		SCHT->theLists[i]->next = NULL;
	}
	return (vHashTable)SCHT;
}

Index CSeparateChaining::hash(Key key, vHashTable H)
{
	assert(H);
	SC_HashTable SCHT = (SC_HashTable)H;
	return key%(SCHT->tableSize);
}

vHashTable CSeparateChaining::rehash(vHashTable H)
{
	// 分离定制法无需再散列
	return H;
}

vPostion CSeparateChaining::find(Key key, vHashTable H)
{
	SC_HashTable SCHT = (SC_HashTable)H;
	SC_Position tempP = SCHT->theLists[hash(key, H)]->next;
	while(tempP && tempP->key != key) tempP = tempP->next;
	return (vPostion)tempP;
}

ElementType CSeparateChaining::retrieve(vPostion P)
{
	assert(P);
	SC_Position pos = (SC_Position)P;
	return pos->element;
}

void CSeparateChaining::insert(Key key, ElementType X, vHashTable H)
{
	assert(H);
	SC_HashTable SCHT = (SC_HashTable)H;
	vPostion pos = find(key, H);
	if(!pos)
	{
		SC_List SCL = SCHT->theLists[hash(key, H)];
		SC_Position newNode = (SC_Position)malloc(sizeof(SC_ListNode));
		assert(newNode);
		newNode->element = X;
		newNode->key = key;
		newNode->next = SCL->next;
		SCL->next = newNode;
	}
}

void CSeparateChaining::deleteX(Key key, vHashTable H)
{
	assert(H);
	SC_HashTable SCHT = (SC_HashTable)H;
	SC_Position tempP = SCHT->theLists[hash(key, H)];
	while(tempP->next && tempP->next->key != key) tempP = tempP->next;
	if(tempP->next)
	{
		SC_Position toBeDele = tempP->next;
		tempP->next = toBeDele->next;
		free(toBeDele);
	}
}

void CSeparateChaining::deleteHashTable(vHashTable H)
{
	if(H)
	{
		SC_HashTable SCHT = (SC_HashTable)H;
		for(int i=0;i<SCHT->tableSize;i++)
		{
			SC_List SCL = SCHT->theLists[i];
			while(SCL->next)
			{
				SC_Position tempP = SCL->next;
				SCL->next = tempP->next;
				free(tempP);
			}
			free(SCL);
		}
	}
}

void CSeparateChaining::printHash(vHashTable H)
{
	if(H)
	{
		SC_HashTable SCHT = (SC_HashTable)H;
		for(int i=0;i<SCHT->tableSize;i++)
		{
			std::cout<<"Index "<<i<<": ";
			SC_Position tempP = SCHT->theLists[i]->next;
			while(tempP)
			{
				std::cout<<tempP->element<<" ";
				tempP = tempP->next;
			}
			std::cout<<"\n";
		}
	}
}

int CSeparateChaining::nextPrime(int tableSize)
{
	int i;
	bool isPrime;
	for(i=tableSize;;i++)
	{
		isPrime = true;
		for(int j=2;j<i;j++)
		{
			if(i%j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if(isPrime) return i;
	}
}

