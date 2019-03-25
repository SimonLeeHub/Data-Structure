// Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SearchTree.h"
#include "AVLTree.h"
#include "SpalyTree.h"
#include "Traversal.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CTreeOperation *pTree[3];
	pTree[0] = new CSearchTree;
	pTree[1] = new CAVLTree;
	pTree[2] = new CSpalyTree;

	for(int i=0;i<3;i++)
	{
		if(pTree[i])
		{
			CTraversal mTraversal;
			std::cout<<pTree[i]->description;
			std::cout<<"Create Tree.\n";
			vTree T = pTree[i]->createTree();
			std::cout<<"Insert 5 2 8 1 3 7 9 0 4 6 10 11\n";
			T = pTree[i]->insert(5, T);
			T = pTree[i]->insert(2, T);
			T = pTree[i]->insert(8, T);
			T = pTree[i]->insert(1, T);
			T = pTree[i]->insert(3, T);
			T = pTree[i]->insert(7, T);
			T = pTree[i]->insert(9, T);
			T = pTree[i]->insert(0, T);
			T = pTree[i]->insert(4, T);
			T = pTree[i]->insert(6, T);
			T = pTree[i]->insert(10, T);
			T = pTree[i]->insert(11, T);
			std::cout<<"Graphic print.\n";
			mTraversal.graphicPrint(pTree[i], T);
			std::cout<<"Preorder traversal.\n";
			mTraversal.preorderTraversal(pTree[i], T);
			std::cout<<"\n";
			std::cout<<"Inorder traversal.\n";
			mTraversal.inorderTraversal(pTree[i], T);
			std::cout<<"\n";
			std::cout<<"Postorder traversal.\n";
			mTraversal.postorderTraversal(pTree[i], T);
			std::cout<<"\n";
			std::cout<<"Breadth-first traversal.\n";
			mTraversal.BFS(pTree[i], T);
			std::cout<<"\n";
			std::cout<<"Depth-first traversal.\n";
			mTraversal.DFS(pTree[i], T);
			std::cout<<"\n";
			std::cout<<"Min element is "<<pTree[i]->retrieve(pTree[i]->findMin(T))<<".\n";
			std::cout<<"Max element is "<<pTree[i]->retrieve(pTree[i]->findMax(T))<<".\n";
			vPosition pos = pTree[i]->find(8, T);
			if(typeid(*(pTree[i])) == typeid(CSpalyTree))
			{
				T = pos;
			}
			std::cout<<"Element 8 is "<<pTree[i]->retrieve(pos)<<".\n";
			
			mTraversal.graphicPrint(pTree[i], T);
			std::cout<<"Delete 4.\n";
			T = pTree[i]->deleteX(4, T);
			mTraversal.graphicPrint(pTree[i], T);
			std::cout<<"Delete 7.\n";
			T = pTree[i]->deleteX(7, T);
			mTraversal.graphicPrint(pTree[i], T);
			std::cout<<"Delete 5.\n";
			T = pTree[i]->deleteX(5, T);
			mTraversal.graphicPrint(pTree[i], T);
			std::cout<<"Delete 0 1 2 3.\n";
			T = pTree[i]->deleteX(0, T);
			T = pTree[i]->deleteX(1, T);
			T = pTree[i]->deleteX(2, T);
			T = pTree[i]->deleteX(3, T);
			mTraversal.graphicPrint(pTree[i], T);
			std::cout<<"Delete tree.\n";
			T = pTree[i]->deleteTree(T);
			mTraversal.graphicPrint(pTree[i], T);
		}
	}

	std::cout<<"\n\n\nTree structure has been tested, press any key to exit...\n";
	getchar();
	return 0;
}

