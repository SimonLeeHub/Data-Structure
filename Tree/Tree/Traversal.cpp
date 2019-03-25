#include "stdafx.h"
#include "Traversal.h"

CTraversal::CTraversal()
{
}


CTraversal::~CTraversal(void)
{
}

void CTraversal::graphicPrint(CTreeOperation *pT, vTree T)
{
	this->pT = pT;
	this->T = T;
	colNum = 0;
	THeight = pT->treeHeight(T);
	if(THeight == 0) return;
	table = new GraphicPrintNode *[THeight];
	assert(table);
	for(int i=0;i<THeight;i++)
	{
		int k =(int)(pow(2, THeight)-1);
		table[i] = new GraphicPrintNode[(int)(pow(2, THeight)-1)];
		assert(table[i]);
		for(int j=0;j<(int)(pow(2, THeight)-1); j++)
		{
			table[i][j].isEmpty = true;
		}
	}
	fillTable(T, THeight);
	for(int i=0;i<THeight;i++)
	{
		for(int j=0;j<(int)(pow(2, THeight)-1); j++)
		{
			if(table[i][j].isEmpty)
			{
				std::cout<<"  ";
			}
			else
			{
				std::cout<<std::setw(2)<<table[i][j].element;
			}
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<THeight;i++)
	{
		delete [] table[i];
	}
	delete [] table;
	table = NULL;
}

void CTraversal::fillTable(vTree T, int curHeight)
{
	if(T)
	{
		fillTable(pT->leftChild(T), curHeight-1);
		table[THeight-curHeight][colNum].element = pT->retrieve(T);
		table[THeight-curHeight][colNum].isEmpty = false;
		colNum++;
		fillTable(pT->rightChild(T), curHeight-1);
	}
	else
	{
		colNum += (int)(pow(2, curHeight)-1);
	}
}


void CTraversal::preorderTraversal(CTreeOperation *pT, vTree T)
{
	if(T)
	{
		std::cout<<pT->retrieve(T)<<" ";
		preorderTraversal(pT, pT->leftChild(T));
		preorderTraversal(pT, pT->rightChild(T));
	}
}


void CTraversal::inorderTraversal(CTreeOperation *pT, vTree T)
{
	if(T)
	{
		inorderTraversal(pT, pT->leftChild(T));
		std::cout<<pT->retrieve(T)<<" ";
		inorderTraversal(pT, pT->rightChild(T));
	}
}


void CTraversal::postorderTraversal(CTreeOperation *pT, vTree T)
{
	if(T)
	{
		postorderTraversal(pT, pT->leftChild(T));
		postorderTraversal(pT, pT->rightChild(T));
		std::cout<<pT->retrieve(T)<<" ";
	}
}


void CTraversal::BFS(CTreeOperation *pT, vTree T)
{
	vTree tempT;
	if(T)
	{
		BFS_Q.push(T);
		while(!BFS_Q.empty())
		{
			tempT = BFS_Q.front();
			std::cout<<pT->retrieve(tempT)<<" ";
			BFS_Q.pop();
			if(pT->leftChild(tempT)) BFS_Q.push(pT->leftChild(tempT));
			if(pT->rightChild(tempT)) BFS_Q.push(pT->rightChild(tempT));
		}
	}
}


void CTraversal::DFS(CTreeOperation *pT, vTree T)
{
	vTree tempT;
	if(T)
	{
		DFS_S.push(T);
		while(!DFS_S.empty())
		{
			tempT = DFS_S.top();
			std::cout<<pT->retrieve(tempT)<<" ";
			DFS_S.pop();
			if(pT->rightChild(tempT)) DFS_S.push(pT->rightChild(tempT));
			if(pT->leftChild(tempT)) DFS_S.push(pT->leftChild(tempT));	
		}
	}
}
