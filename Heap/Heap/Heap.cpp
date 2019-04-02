// Heap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BinaryHeap.h"
#include "LeftlistHeap.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CHeapOperation *pH[2];
	pH[0] = new CBinaryHeap;
	pH[1] = new CLeftlistHeap;

	for(int i=0;i<2;i++)
	{
		if(pH[i])
		{
			std::cout<<pH[i]->description;
			std::cout<<"Create queue.\n";
			vHeap H1 = pH[i]->createQueue();
			std::cout<<"Is empty "<<pH[i]->isEmpty(H1)<<"\n";
			std::cout<<"Enqueue 1 3 5 7 9.\n";
			for(int j=1;j<=9;j+=2) H1 = pH[i]->enqueue(j, H1);
			pH[i]->printQueue(H1);
			std::cout<<"Build min heap.(10 8 6 4 2)\n";
			ElementType *array = (ElementType*)malloc(sizeof(ElementType)*5);
			for(int j=10;j>=2;j-=2) array[5-j/2] = j;
			vHeap H2 = pH[i]->buildHeap(array, 5);
			pH[i]->printQueue(H2);
			std::cout<<"Merge H1 and H2.\n";
			vHeap H3 = pH[i]->merge(H1, H2);
			pH[i]->printQueue(H3);
			std::cout<<"Is full "<<pH[i]->isFull(H3)<<"\n";
			std::cout<<"Dequeue element is "<<pH[i]->front(H3)<<"\n";
			H3 = pH[i]->dequeue(H3);
			pH[i]->printQueue(H3);
			std::cout<<"Dequeue element is "<<pH[i]->front(H3)<<"\n";
			H3 = pH[i]->dequeue(H3);
			pH[i]->printQueue(H3);
			std::cout<<"Is full "<<pH[i]->isFull(H3)<<"\n";
			std::cout<<"Delete queue.\n";
			pH[i]->deleteQueue(H3);
		}
	}

	std::cout<<"Heap structure has been tested, press any key to exit...\n";
	getchar();
	return 0;
}

