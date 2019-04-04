#include "stdafx.h"
#include "ForestSet.h"


CForestSet::CForestSet(void)
{
	description = "\n\n\n-------- Forest Disjset --------\n";
}


CForestSet::~CForestSet(void)
{
}

void CForestSet::createSet(Disjset S)
{
	// 将数组元素初始化为-1，即有NumSet个集合
	for(int i=NumSet;i>0;i--)
	{
		S[i] = -1;
	}
}

void CForestSet::setUnion(Disjset S, SetType root1, SetType root2)
{
	if(S[root1]<S[root2])
	{
		S[root2] = root1;
	}
	else if(S[root1]>S[root2])
	{
		S[root1] = root2;
	}
	else
	{
		// 如果两棵树高相等，则合并后树高+1
		S[root2] = root1;
		S[root1]--;
	}
}

SetType CForestSet::find(ElementType X, Disjset S)
{
	// 递归找树根，回溯时将路径上的子孙节点指向树根
	if(S[X]<0) return X;
	return S[X] = find(S[X], S);
}


void CForestSet::printSet(Disjset S)
{
	for(int i=1;i<=NumSet;i++) std::cout<<S[i]<<" ";
	std::cout<<std::endl;
}

