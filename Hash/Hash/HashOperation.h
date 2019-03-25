/*!
* \brief 哈希表基本操作接口类 
* 
* 包含创建（1）、计算哈希值（1）、再散列（1）、查找（1）、返回元素值（1）、插入（1）、删除元素（1）与删除哈希表（1）共8种基本操作
* 
* \author Lee  
* \date 2019.03.25 
*/
#pragma once
typedef int Key;
typedef unsigned int Index;
typedef int ElementType;
typedef void *vPostion;
typedef void *vHashTable;

class CHashOperation
{
public:
	CHashOperation(void);
	virtual ~CHashOperation(void);
	virtual vHashTable create(int tableSize) = 0;	//创建哈希表
	virtual Index hash(Key key, vHashTable H) = 0;	//计算哈希函数，返回存储位置
	virtual vHashTable rehash(vHashTable H) = 0;	//再散列
	virtual vPostion find(Key key, vHashTable H) = 0;	//查找散列表中Key所对应元素的位置
	virtual ElementType retrieve(vPostion P) = 0;	//返回位置P所对应的元素的值
	virtual void insert(Key key, ElementType X, vHashTable H) = 0;	//插入元素
	virtual void deleteX(Key key, vHashTable H) = 0;        //删除元素
	virtual void deleteHashTable(vHashTable H) = 0;	//清空散列表

	//基础辅助函数
	virtual void printHash(vHashTable H) = 0;	//打印哈希表

	std::string description;
};

