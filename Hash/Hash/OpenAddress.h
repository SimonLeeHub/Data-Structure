/*!
* \brief 哈希表——开放定址法接口类 
* 
* 采用开放定址法解决冲突，其中hash函数由
* 含有特定检测方法的子类实现
* 
* \author Lee  
* \date 2019.03.25 
*/
#pragma once
#include "hashoperation.h"
enum NodeInfo {Empty,  Legitimate, Deleted};
struct OA_Node
{
	Key key;
	ElementType element;
	NodeInfo info;
};
typedef OA_Node *OA_Position;
typedef OA_Node *OA_Array;
struct OA_HashTableNode
{
	int tableSize;
	OA_Array theNodes;
	
};
typedef OA_HashTableNode *OA_HashTable;
class COpenAddress :
	public CHashOperation
{
public:
	COpenAddress(void);
	virtual ~COpenAddress(void);

	vHashTable create(int tableSize);
	//virtual Index hash(Key key, vHashTable H) = 0;  //交给子类实现
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

