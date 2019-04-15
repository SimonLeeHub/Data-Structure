/*!
* \brief ������������ 
* 
* ����ͼ�α�����1����ǰ�������1�������������1�������������1����������ȱ�����1����������ȱ�����1����6�ֻ�������
* 
* \author Lee
* \date 2019.03.18
*/
#pragma once
#include "TreeOperation.h"
#include <queue>
#include <stack>
struct GraphicPrintNode
{
	ElementType element;
	bool isEmpty;
};
class CTraversal
{
public:
	CTraversal();
	~CTraversal(void);

	CTreeOperation *pT;
	vTree T;

	void graphicPrint(CTreeOperation *pT, vTree T);
private:
	GraphicPrintNode **table;
	int colNum, THeight;
	std::queue<vTree> BFS_Q;
	std::stack<vTree> DFS_S;
	void fillTable(vTree T, int curHeight);

public:
	void preorderTraversal(CTreeOperation *pT, vTree T);
	void inorderTraversal(CTreeOperation *pT, vTree T);
	void postorderTraversal(CTreeOperation *pT, vTree T);
	void BFS(CTreeOperation *pT, vTree T);
	void DFS(CTreeOperation *pT, vTree T);
};

