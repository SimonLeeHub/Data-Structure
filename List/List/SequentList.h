/*!
* \brief 顺序表类 
* 
* 为了复用表接口，节点位置信息采用数组元素的地址表示，而未 
* 采用常规的数组编号表示
*
* \author Lee
* \date 2019.03.12
*/
#pragma once
#include "listoperation.h"
#define INIT_CAPACITY 10
struct SL_Node
{
	ElementType *array;
	int capacity;
	int size;
};
typedef ElementType *SL_Position;
typedef SL_Node *SL_List;
class CSequentList :
	public CListOperation
{
public:
	CSequentList(void);
	~CSequentList(void);
	vList createList(void);
	bool isEmpty(vList L);	//O(1)
	bool isLast(vPosition P, vList L);	//O(1)
	vPosition findLast(vList L);	//O(1)
	vPosition find(ElementType X, vList L);	//O(N)
	vPosition findPrevious(ElementType X, vList L);	//O(N)
	vPosition findNext(ElementType X, vList L);	//O(N)
	void insertLast(ElementType X, vList L);	//0(1)
	void insertBefore(ElementType X, vPosition p, vList L);	//0(N)
	void insertAfter(ElementType X, vPosition p, vList L);	//0(N)
	void printList(vList L);	//O(N)
	void deleteX(ElementType X, vList L);	//O(N)
	void deleteList(vList L);	//O(1)
};

