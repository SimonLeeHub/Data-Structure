#include "stdafx.h"
#include "LinearProbing.h"


CLinearProbing::CLinearProbing(void)
{
	description = "\n\n\n-------- Linear Probing --------\n";
}


CLinearProbing::~CLinearProbing(void)
{
}

Index CLinearProbing::hash(Key key, vHashTable H)
{
	assert(H);
	OA_HashTable OAHT = (OA_HashTable)H;
	Index index = key % OAHT->tableSize;
	while((OAHT->theNodes[index].key != key) && (OAHT->theNodes[index].info == Legitimate)) index = (++index) % OAHT->tableSize;
	return index;
}
