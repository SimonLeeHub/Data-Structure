// Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentStack.h"
#include "LinkedStack.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CStackOperation *pStack[2];
	pStack[0] = new(CSequentStack);
	pStack[1] = new(CLinkedStack);

	for(int i=0; i<2; i++)
	{
		if(pStack[i])
		{
			std::cout<<pStack[i]->description;
			std::cout<<"Create Stack.\n";
			vStack S = pStack[i]->createStack();
			std::cout<<"Push 0 1 2 3.\n";
			for(int j=0; j<4; j++)
			{
				pStack[i]->push(j, S);
			}
			std::cout<<"Top is "<<pStack[i]->top(S)<<".\n";
			std::cout<<"Pop 3.\n";
			pStack[i]->pop(S);
			std::cout<<"Top and pop, and the top is "<<pStack[i]->topAndPop(S)<<".\n";
			std::cout<<"Push 4 5 6 7 8.\n";
			for(int j=4; j<9; j++)
			{
				pStack[i]->push(j, S);
			}
			std::cout<<"Pop all.\n";
			while(!(pStack[i]->isEmpty(S))) std::cout<<pStack[i]->topAndPop(S)<<std::endl;
			std::cout<<"Delete stack.\n";
			pStack[i]->deleteStack(S);
		}
	}

	std::cout<<"\n\nStack structure has been tested, press any key to exit...\n";
	getchar();
	return 0;
}

