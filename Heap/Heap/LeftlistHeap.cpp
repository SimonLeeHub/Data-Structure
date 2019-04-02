#include "stdafx.h"
#include "LeftlistHeap.h"


CLeftlistHeap::CLeftlistHeap(void)
{
	description = "\n\n\n-------- Leftlist Heap --------\n";
}


CLeftlistHeap::~CLeftlistHeap(void)
{
}

vHeap CLeftlistHeap::createQueue()
{
	return NULL;
}

bool CLeftlistHeap::isEmpty(vHeap H)
{
	if(!H) return true;
	return false;
}

bool CLeftlistHeap::isFull(vHeap H)
{
	return false;
}

vHeap CLeftlistHeap::enqueue(ElementType X, vHeap H)
{
	LH_Position P = (LH_Position)malloc(sizeof(LH_Node));
	assert(P);
	P->element = X;
	P->left = NULL;
	P->right = NULL;
	P->NPL = 0;
	return merge(P, H);
}

vHeap CLeftlistHeap::dequeue(vHeap H)
{
	assert(H);
	LH_Heap LH = (LH_Heap)H;
	vHeap newHeap = merge(LH->left, LH->right);
	free(LH);
	return newHeap;
}

ElementType CLeftlistHeap::front(vHeap H)
{
	assert(H);
	LH_Heap LH = (LH_Heap)H;
	return LH->element;
}

void CLeftlistHeap::deleteQueue(vHeap H)
{
	if(H)
	{
		LH_Heap LH = (LH_Heap)H;
		deleteQueue(LH->left);
		deleteQueue(LH->right);
		free(LH);
	}
}

vHeap CLeftlistHeap::merge(vHeap H1, vHeap H2)
{
	if(!H1) return H2;
	if(!H2) return H1;
	LH_Heap LH1 = (LH_Heap)H1;
	LH_Heap LH2 = (LH_Heap)H2;
	if(LH1->element < LH2->element)
		return (vHeap)merge1(LH1, LH2);
	else
		return (vHeap)merge1(LH2, LH1);
}

LH_Heap CLeftlistHeap::merge1(LH_Heap LH1, LH_Heap LH2)
{
	// 先将根值较小堆的右子树与根值较大的堆递归合并，
	// 然后再将合并后的根值较大的堆作为根值较小的堆的右子树

	// 第一种情况为，根值较小的堆只有一个根节点
	if(!LH1->left)
	{
		LH1->left = LH2;
	}
	else
	{
		// 递归合并，回溯的时候检查左式堆的零路径长度条件，若不满足，则交换左右子树
		// 每次递归都要更新节点的零路径长信息
		LH1->right = (LH_Heap)merge(LH1->right, LH2);
		if(LH1->left->NPL < LH1->right->NPL)
		{
			LH_Position tempP = LH1->left;
			LH1->left = LH1->right;
			LH1->right = tempP;
		}
		LH1->NPL = LH1->right->NPL+1;
	}
	return LH1;
}

vHeap CLeftlistHeap::buildHeap(ElementType *array, int len)
{
	vHeap H = createQueue();
	for(int i=0;i<len;i++) H = enqueue(array[i], H);
	return H;
}

void CLeftlistHeap::printQueue(vHeap H)
{
	LH_Heap LH = (LH_Heap)H;
	colNum = 0;
	THeight = heapHeight(LH);
	if(THeight == 0) return;
	table = new GraphicPrintNode *[THeight];
	assert(table);
	for(int i=0;i<THeight;i++)
	{
		table[i] = new GraphicPrintNode[(int)(pow(2, THeight)-1)];
		assert(table[i]);
		for(int j=0;j<(int)(pow(2, THeight)-1); j++)
		{
			table[i][j].isEmpty = true;
		}
	}
	fillTable(LH, THeight);
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

int CLeftlistHeap::heapHeight(LH_Heap LH)
{
	if(!LH)
	{
		return 0;
	}
	else
	{
		int leftHeight = heapHeight(LH->left);
		int rightHeight = heapHeight(LH->right);
		return leftHeight > rightHeight? ++leftHeight : ++rightHeight;
	}
}

void CLeftlistHeap::fillTable(LH_Heap LH, int curHeight)
{
	if(LH)
	{
		fillTable(LH->left, curHeight-1);
		table[THeight-curHeight][colNum].element = LH->element;
		table[THeight-curHeight][colNum].isEmpty = false;
		colNum++;
		fillTable(LH->right, curHeight-1);
	}
	else
	{
		colNum += (int)(pow(2, curHeight)-1);
	}
}

