#include "stdafx.h"
#include "DoubleHash.h"


CDoubleHash::CDoubleHash(void)
{
	description = "\n\n\n-------- Double Hash --------\n";
}


CDoubleHash::~CDoubleHash(void)
{
}

Index CDoubleHash::hash(Key key, vHashTable H)
{
	assert(H);
	OA_HashTable OAHT = (OA_HashTable)H;
	Index h1 = key % OAHT->tableSize;
	Index h2 = 1 + key % (OAHT->tableSize - 1);
	Index index = h1;
	int i=1;
	while((OAHT->theNodes[index].key != key) && (OAHT->theNodes[index].info == Legitimate)) index = (h1 + h2*i++) % OAHT->tableSize;
	return index;
}
