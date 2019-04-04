// Disjset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PureArraySet.h"
#include "ForestSet.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CDisjsetOperation *pS[2];
	pS[0] = new CPureArraySet;
	pS[1] = new CForestSet;

	for(int i=0;i<2;i++)
	{
		if(pS[i])
		{
			std::cout<<pS[i]->description;
			std::cout<<"Create set.\n";
			Disjset S;
			pS[i]->createSet(S);
			pS[i]->printSet(S);
			std::cout<<"Union All.\n";
			for(int k=1;k<=NumSet/2;k*=2)
			{
				for(int j=1;j<=NumSet-1;j += 2*k) 
				pS[i]->setUnion(S, j, j+k);
				pS[i]->printSet(S);
				std::cout<<std::endl;
			}
			
			std::cout<<"16 is belong to set "<<pS[i]->find(16, S)<<std::endl;
			pS[i]->printSet(S);
		}
	}

	std::cout<<"\n\n\nDisjset structure has been tested, press any key to exit...\n";
	getchar();
	return 0;
}

