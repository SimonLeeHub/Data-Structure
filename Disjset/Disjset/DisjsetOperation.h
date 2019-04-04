/*!
* \brief 不相交集（并查集）基本操作接口类
* 
* 包含初始化（1）、合并（1）与查找（1）共3个基本操作 
* 
* \author Lee  
* \date 2019.04.04 
*/
#pragma once
#define NumSet 16
typedef int ElementType;
typedef int SetType;
typedef int Disjset[NumSet+1];
class CDisjsetOperation
{
public:
	CDisjsetOperation(void);
	virtual ~CDisjsetOperation(void);

	virtual void createSet(Disjset S) = 0;
	virtual void setUnion(Disjset S, SetType root1, SetType root2) = 0;
	virtual SetType find(ElementType X, Disjset S) = 0;

	// 基本辅助函数
	virtual void printSet(Disjset S) = 0;

	std::string description;
};

