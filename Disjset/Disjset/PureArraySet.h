/*!
* \brief 并查集的纯数组实现
* 
* 由于数组元素存储的就是集合号，所以find为O(1)
* 但是union操作需要遍历整个集合
* 
* \author Lee  
* \date 2019.04.04 
*/
#pragma once
#include "disjsetoperation.h"
class CPureArraySet :
	public CDisjsetOperation
{
public:
	CPureArraySet(void);
	~CPureArraySet(void);

	void createSet(Disjset S);
	void setUnion(Disjset S, SetType root1, SetType root2);
	SetType find(ElementType X, Disjset S);

	void printSet(Disjset S);
};

