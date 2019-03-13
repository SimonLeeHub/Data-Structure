// Queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentQueue.h"
#include "LinkedQueue.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CQueueOperation *pQueue[2];
	pQueue[0] = new(CSequentQueue);
	pQueue[1] = new(CLinkedQueue);

	for(int i=0;i<2;i++)
	{
		if(pQueue[i])
		{
			std::cout<<pQueue[i]->description;
			std::cout<<"Create Queue.\n";
			vQueue Q = pQueue[i]->createQueue();
			std::cout<<"isEmpty.\n"<<pQueue[i]->isEmpty(Q)<<"\n";
			std::cout<<"Enqueue 0 1 2 3.\n";
			for(int j=0;j<4;j++) pQueue[i]->enqueue(j, Q);
			std::cout<<"isFull.\n"<<pQueue[i]->isFull(Q)<<"\n";
			std::cout<<"Front is "<<pQueue[i]->front(Q)<<".\n";
			std::cout<<"Dequeue 0.\n";
			pQueue[i]->dequeue(Q);
			std::cout<<"Front and dequeue, and front is "<<pQueue[i]->frontAndDequeue(Q)<<".\n";
			std::cout<<"Enqueue 4 5.\n";
			for(int j=4;j<6;j++) pQueue[i]->enqueue(j, Q);
			std::cout<<"Dequeue all.\n";
			while(!pQueue[i]->isEmpty(Q)) std::cout<<pQueue[i]->frontAndDequeue(Q)<<"\n";
			std::cout<<"Delete queue.\n";
			pQueue[i]->deleteQueue(Q);
		}
	}

	std::cout<<"\nQueue structure has been tested, press any key to exit...\n";
	getchar();
	return 0;
}

