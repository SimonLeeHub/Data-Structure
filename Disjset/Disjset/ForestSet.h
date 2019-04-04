/*!
* \brief 并查集的不相交森林实现
* 
* 森林采用数组实现，数组元素存储父节点的索引
* 对于根节点，其存储当前树的秩（参考树高）的赋值
* 对于单节点，其秩为1
* 
* \author Lee  
* \date 2019.04.04 
*/
#pragma once
#include "disjsetoperation.h"
class CForestSet :
	public CDisjsetOperation
{
public:
	CForestSet(void);
	~CForestSet(void);

	void createSet(Disjset S);
	void setUnion(Disjset S, SetType root1, SetType root2);
	SetType find(ElementType X, Disjset S);

	void printSet(Disjset S);
};

