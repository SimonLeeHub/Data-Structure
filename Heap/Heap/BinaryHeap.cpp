#include "stdafx.h"
#include "BinaryHeap.h"


CBinaryHeap::CBinaryHeap(void)
{
	description = "\n\n\n-------- Binary Heap --------\n";
}


CBinaryHeap::~CBinaryHeap(void)
{
}

vHeap CBinaryHeap::createQueue()
{
	BH_Heap BH = (BH_Heap)malloc(sizeof(HeapStruct));
	assert(BH);
	BH->array = (ElementType*)malloc(sizeof(ElementType)*INITCAPACITY);
	assert(BH->array);
	BH->capacity = INITCAPACITY;
	BH->size = 0;
	BH->array[0] = INT_MIN;
	return (vHeap)BH;
}

bool CBinaryHeap::isEmpty(vHeap H)
{
	assert(H);
	BH_Heap BH = (BH_Heap)H;
	if(BH->size == 0) return true;
	return false;
}

bool CBinaryHeap::isFull(vHeap H)
{
	assert(H);
	BH_Heap BH = (BH_Heap)H;
	if(BH->size == BH->capacity - 1) return true;
	return false;
}

vHeap CBinaryHeap::enqueue(ElementType X, vHeap H)
{
	//从新插入的末节点开始上滤，直到能将元素插入为止
	assert(!isFull(H));
	BH_Heap BH = (BH_Heap)H;
	int i;
	// 此处需注意，for循环的终止条件成立的前提条件是有标记节点，即array[0]
	// 如无标记节点，则需在for循环中增加一次判断是否已经到达根节点，否则将成为死循环
	for(i = ++BH->size;X < BH->array[i/2]; i /= 2)
	{
		BH->array[i] = BH->array[i/2];
	}
	BH->array[i] = X;
	return (vHeap)BH;
}

vHeap CBinaryHeap::dequeue(vHeap H)
{
	//从根开始下滤，直到能把最末端的元素放入为止
	assert(!isEmpty(H));
	BH_Heap BH = (BH_Heap)H;
	int i, child;
	ElementType lastElement = BH->array[BH->size--];
	for(i = 1; 2*i <= BH->size; i = child)
	{
		child = 2*i;
		if((child != BH->size) && (BH->array[child] > BH->array[child+1])) child++;
		if(lastElement > BH->array[child])
			BH->array[i] = BH->array[child];
		else
			break;
	}
	BH->array[i] = lastElement;
	return (vHeap)BH;
}

ElementType CBinaryHeap::front(vHeap H)
{
	assert(!isEmpty(H));
	BH_Heap BH = (BH_Heap)H;
	return BH->array[1];
}

void CBinaryHeap::deleteQueue(vHeap H)
{
	assert(H);
	BH_Heap BH = (BH_Heap)H;
	free(BH->array);
	free(BH);
}

vHeap CBinaryHeap::merge(vHeap H1, vHeap H2)
{
	//二叉堆不支持合并，若要合并这能采用如下两种方法
	//当两堆大小差别很大时，采用小堆元素依次插入大堆的启发式合并，平均时间复杂度为O(N1logN2)
	//或者当两堆大小差不多时，将两个堆元素合并到一起，重新建堆，平均时间复杂度为O(N1+N2)
	if(!H1) return H2;
	if(!H2) return H1;
	BH_Heap BH1 = (BH_Heap)H1;
	BH_Heap BH2 = (BH_Heap)H2;
	if(abs(BH1->size - BH2->size)>=5)
	{
		if(BH1->size < BH2->size)
		{
			for(int i=1;i<BH1->size;i++)
			{
				enqueue(BH1->array[i], (vHeap)BH2);
			}
			deleteQueue((vHeap)BH1);
			return BH2;
		}
		else
		{
			for(int i=1;i<BH2->size;i++)
			{
				enqueue(BH2->array[i], (vHeap)BH1);
			}
			deleteQueue((vHeap)BH2);
			return BH1;
		}
	}
	else
	{
		ElementType *newArray = (ElementType*)malloc(sizeof(ElementType)*(BH1->size+BH2->size));
		assert(newArray);
		for(int i=1;i<=BH1->size;i++) newArray[i-1] = BH1->array[i];
		for(int i=1;i<=BH2->size;i++) newArray[i-1+BH1->size] = BH2->array[i];
		vHeap newBH = buildHeap(newArray, BH1->size+BH2->size);
		free(newArray);
		deleteQueue(BH1);
		deleteQueue(BH2);
		return newBH;
	}
}

vHeap CBinaryHeap::buildHeap(ElementType *array, int len)
{
	//从末节点的父节点开始依次往前执行下滤，直到到达根节点
	//与插入建堆不同，插入建堆平均时间复杂度为O(NlogN),
	//而下滤建堆的时间复杂度为O(N)
	assert(len<=(INITCAPACITY-1));
	BH_Heap BH = (BH_Heap)createQueue();
	for(int i=1;i<=len;i++)
	{
		BH->array[i] = array[i-1];
	}
	BH->size = len;
	for(int i = BH->size/2; i > 0; i--)
	{
		int j, child;
		ElementType tempE;
		for(j=i;2*j<=BH->size;j=child)
		{
			child = 2*j;
			if((child != BH->size) && (BH->array[child] > BH->array[child+1])) child++;
			if(BH->array[j] > BH->array[child])
			{
				tempE = BH->array[j];
				BH->array[j] = BH->array[child];
				BH->array[child] = tempE;
			}
			else
			{
				// 我们是从倒数第二行开始依次往上执行下滤的，所以此处可以提前终止算法已加快算法执行速度
				break;
			}
		}
	}

	return (vHeap)BH;

}

void CBinaryHeap::printQueue(vHeap H)
{
	if(H)
	{
		BH_Heap BH = (BH_Heap)H;
		for(int i = 1;i <= BH->size; i++)
		{
			std::cout<<BH->array[i]<<" ";
		}
		std::cout<<std::endl;
	}
	
}
