// List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentList.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "SingleCircleLinkedList.h"
#include "DoubleCircleLinkedList.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CListOperation *pList[5];
	pList[0] = new(CSequentList);
	pList[1] = new(CSingleLinkedList);
	pList[2] = new(CDoubleLinkedList);
	pList[3] = new(CSingleCircleLinkedList);
	pList[4] = new(CDoubleCircleLinkedList);
	
	for(int i=0;i<5;i++)
	{
		if(pList[i])
		{
			std::cout<<pList[i]->description;
			std::cout<<"Create List.\n";
			vList L = pList[i]->createList();
			std::cout<<"isEmpty.\n";
			std::cout<<pList[i]->isEmpty(L)<<"\n";
			std::cout<<"Insert 0 2 4 6 8.\n";
			for(int j=0;j<5;j++)
			{
				pList[i]->insertLast(2*j, L);
			}
			std::cout<<"Print.\n";
			pList[i]->printList(L);
			std::cout<<"Insert 1 after 0.\n";
			vPosition tempPos= pList[i]->find(0, L);
			pList[i]->insertAfter(1, tempPos, L);
			pList[i]->printList(L);
			std::cout<<"Insert 3 before 4.\n";
			tempPos= pList[i]->find(4, L);
			pList[i]->insertBefore(3, tempPos, L);
			pList[i]->printList(L);
			std::cout<<"Insert 5 before 6.\n";
			tempPos= pList[i]->findNext(4, L);
			pList[i]->insertBefore(5, tempPos, L);
			pList[i]->printList(L);
			std::cout<<"Insert 7 after 6.\n";
			tempPos= pList[i]->findPrevious(8, L);
			pList[i]->insertAfter(7, tempPos, L);
			pList[i]->printList(L);
			std::cout<<"Insert 9 after 8.\n";
			tempPos= pList[i]->findLast(L);
			pList[i]->insertAfter(9, tempPos, L);
			pList[i]->printList(L);
			std::cout<<"Insert 10 after 9.\n";
			tempPos= pList[i]->findLast(L);
			pList[i]->insertAfter(10, tempPos, L);
			pList[i]->printList(L);
			std::cout<<"Insert 11 12 13 at the end of List.\n";
			pList[i]->insertLast(11, L);
			pList[i]->insertLast(12, L);
			pList[i]->insertLast(13, L);
			pList[i]->printList(L);
			std::cout<<"13 isLast.\n";
			tempPos = pList[i]->find(13, L);
			std::cout<<pList[i]->isLast(tempPos, L)<<"\n";
			std::cout<<"Delete 7.\n";
			pList[i]->deleteX(7, L);
			pList[i]->printList(L);
			std::cout<<"Delete 0.\n";
			pList[i]->deleteX(0, L);
			pList[i]->printList(L);
			std::cout<<"Delete 13.\n";
			pList[i]->deleteX(13, L);
			pList[i]->printList(L);
			std::cout<<"Delete list.\n";
			pList[i]->deleteList(L);
			pList[i]->printList(L);
		}
	}

	std::cout<<"List structure has been tested, press any key to exit...\n";
	getchar();
	return 0;
}

