#include "stdafx.h"
#include "Quadratic.h"


CQuadratic::CQuadratic(void)
{
	description = "\n\n\n-------- Quadratic Probing --------\n";
}


CQuadratic::~CQuadratic(void)
{
}

Index CQuadratic::hash(Key key, vHashTable H)
{
	assert(H);
	OA_HashTable OAHT = (OA_HashTable)H;
	Index ini_index = key % OAHT->tableSize;
	Index index = ini_index;
	int i=1;
	while((OAHT->theNodes[index].key != key) && (OAHT->theNodes[index].info == Legitimate)) index = (ini_index + (int)pow(i++, 2)) % OAHT->tableSize;
	return index;
}
