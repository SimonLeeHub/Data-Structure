#include "stdafx.h"
#include "PureArraySet.h"


CPureArraySet::CPureArraySet(void)
{
	description = "\n\n\n-------- Pure Array Disjset --------\n";
}


CPureArraySet::~CPureArraySet(void)
{
}

void CPureArraySet::createSet(Disjset S)
{
	for(int i=NumSet;i>0;i--)
	{
		S[i] = i;
	}
}

void CPureArraySet::setUnion(Disjset S, SetType root1, SetType root2)
{
	for(int i=NumSet;i>0;i--)
	{
		if(S[i] == root2)
		{
			S[i] = root1;
		}
	}
}

SetType CPureArraySet::find(ElementType X, Disjset S)
{
	return S[X];
}

void CPureArraySet::printSet(Disjset S)
{
	for(int i=1;i<=NumSet;i++) std::cout<<S[i]<<" ";
	std::cout<<std::endl;
}

