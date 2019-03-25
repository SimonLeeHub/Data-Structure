/*!
* \brief 哈希表——分离链接法类 
* 
* 采用分离链接法解决冲突
* 
* \author Lee  
* \date 2019.03.25 
*/
#pragma once
#include "hashoperation.h"
struct SC_ListNode;
typedef SC_ListNode *SC_Position;
typedef SC_ListNode *SC_List;
struct SC_ListNode
{
	Key key;
	ElementType element;
	SC_Position next;
};
struct SC_HashTableNode
{
	int tableSize;
	SC_List *theLists;
};
typedef SC_HashTableNode *SC_HashTable;
class CSeparateChaining :
	public CHashOperation
{
public:
	CSeparateChaining(void);
	virtual ~CSeparateChaining(void);

	vHashTable create(int tableSize);
	Index hash(Key key, vHashTable H);
	vHashTable rehash(vHashTable H);
	vPostion find(Key key, vHashTable H);
	ElementType retrieve(vPostion P);
	void insert(Key key, ElementType X, vHashTable H);
	void deleteX(Key key, vHashTable H);
	void deleteHashTable(vHashTable H);

	// 基础辅助函数
	void printHash(vHashTable H);
	int nextPrime(int tableSize);	//返回大于某个正整数的最小素数
};

