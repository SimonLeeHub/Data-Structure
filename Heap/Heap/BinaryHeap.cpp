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
	//���²����ĩ�ڵ㿪ʼ���ˣ�ֱ���ܽ�Ԫ�ز���Ϊֹ
	assert(!isFull(H));
	BH_Heap BH = (BH_Heap)H;
	int i;
	// �˴���ע�⣬forѭ������ֹ����������ǰ���������б�ǽڵ㣬��array[0]
	// ���ޱ�ǽڵ㣬������forѭ��������һ���ж��Ƿ��Ѿ�������ڵ㣬���򽫳�Ϊ��ѭ��
	for(i = ++BH->size;X < BH->array[i/2]; i /= 2)
	{
		BH->array[i] = BH->array[i/2];
	}
	BH->array[i] = X;
	return (vHeap)BH;
}

vHeap CBinaryHeap::dequeue(vHeap H)
{
	//�Ӹ���ʼ���ˣ�ֱ���ܰ���ĩ�˵�Ԫ�ط���Ϊֹ
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
	//����Ѳ�֧�ֺϲ�����Ҫ�ϲ����ܲ����������ַ���
	//�����Ѵ�С���ܴ�ʱ������С��Ԫ�����β����ѵ�����ʽ�ϲ���ƽ��ʱ�临�Ӷ�ΪO(N1logN2)
	//���ߵ����Ѵ�С���ʱ����������Ԫ�غϲ���һ�����½��ѣ�ƽ��ʱ�临�Ӷ�ΪO(N1+N2)
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
	//��ĩ�ڵ�ĸ��ڵ㿪ʼ������ǰִ�����ˣ�ֱ��������ڵ�
	//����뽨�Ѳ�ͬ�����뽨��ƽ��ʱ�临�Ӷ�ΪO(NlogN),
	//�����˽��ѵ�ʱ�临�Ӷ�ΪO(N)
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
				// �����Ǵӵ����ڶ��п�ʼ��������ִ�����˵ģ����Դ˴�������ǰ��ֹ�㷨�Ѽӿ��㷨ִ���ٶ�
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
