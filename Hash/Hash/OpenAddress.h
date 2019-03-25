/*!
* \brief ��ϣ�������Ŷ�ַ���ӿ��� 
* 
* ���ÿ��Ŷ�ַ�������ͻ������hash������
* �����ض���ⷽ��������ʵ��
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
	//virtual Index hash(Key key, vHashTable H) = 0;  //��������ʵ��
	vHashTable rehash(vHashTable H);
	vPostion find(Key key, vHashTable H);
	ElementType retrieve(vPostion P);
	void insert(Key key, ElementType X, vHashTable H);
	void deleteX(Key key, vHashTable H);
	void deleteHashTable(vHashTable H);

	// ������������
	void printHash(vHashTable H);
	int nextPrime(int tableSize);	//���ش���ĳ������������С����
};

