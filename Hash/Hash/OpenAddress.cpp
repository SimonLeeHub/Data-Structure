#include "stdafx.h"
#include "OpenAddress.h"


COpenAddress::COpenAddress(void)
{
}


COpenAddress::~COpenAddress(void)
{
}

vHashTable COpenAddress::create(int tableSize)
{
	assert(tableSize>0);
	OA_HashTable OAHT = (OA_HashTable)malloc(sizeof(OA_HashTableNode));
	assert(OAHT);
	OAHT->tableSize = nextPrime(tableSize);
	OAHT->theNodes = (OA_Array)malloc(sizeof(OA_Node)*OAHT->tableSize);
	assert(OAHT->theNodes);
	for(int i=0;i<OAHT->tableSize;i++) OAHT->theNodes[i].info = Empty;
	return (vHashTable)OAHT;
}

vHashTable COpenAddress::rehash(vHashTable H)
{
	if(!H) return H;
	OA_HashTable oldH = (OA_HashTable)H;
	OA_HashTable newH = (OA_HashTable)malloc(sizeof(OA_HashTableNode));
	assert(newH);
	newH->tableSize = nextPrime(2*oldH->tableSize);
	newH->theNodes = (OA_Array)malloc(sizeof(OA_Node)*newH->tableSize);
	assert(newH);
	for(int i=0;i<newH->tableSize;i++) newH->theNodes[i].info = Empty;
	for(int i=0;i<oldH->tableSize;i++) 
	{
		if(oldH->theNodes[i].info == Legitimate) insert(oldH->theNodes[i].key, oldH->theNodes[i].element, (vHashTable)newH);
	}
	free(oldH->theNodes);
	free(oldH);
	return newH;
}

vPostion COpenAddress::find(Key key, vHashTable H)
{
	if(!H) return NULL;
	OA_HashTable OAHT = (OA_HashTable)H;
	Index index = hash(key, H);
	if((OAHT->theNodes[index].info == Legitimate)&&(OAHT->theNodes[index].key == key)) return (vPostion)(OAHT->theNodes+index);
	return NULL;
}

ElementType COpenAddress::retrieve(vPostion P)
{
	assert(P);
	OA_Position pos = (OA_Position)P;
	assert(pos->info == Legitimate);
	return pos->element;
}

void COpenAddress::insert(Key key, ElementType X, vHashTable H)
{
	assert(H);
	OA_HashTable OAHT = (OA_HashTable)H;
	Index index = hash(key, H);
	if(OAHT->theNodes[index].info != Legitimate)
	{
		OAHT->theNodes[index].element = X;
		OAHT->theNodes[index].info = Legitimate;
		OAHT->theNodes[index].key = key;
	}	
}

void COpenAddress::deleteX(Key key, vHashTable H)
{
	OA_Position pos = (OA_Position)find(key, H);
	if(pos)
	{
		pos->info = Deleted;
	}
}

void COpenAddress::deleteHashTable(vHashTable H)
{
	assert(H);
	OA_HashTable OAHT = (OA_HashTable)H;
	free(OAHT->theNodes);
	free(OAHT);
}

void COpenAddress::printHash(vHashTable H)
{
		if(H)
	{
		OA_HashTable OAHT = (OA_HashTable)H;
		for(int i=0;i<OAHT->tableSize;i++)
		{
			std::cout<<"Index "<<i<<": ";
			if(OAHT->theNodes[i].info == Legitimate) std::cout<<OAHT->theNodes[i].element;
			std::cout<<"\n";
		}
	}
}

int COpenAddress::nextPrime(int tableSize)
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

