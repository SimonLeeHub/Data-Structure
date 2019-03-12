/*!
* \brief ˳����� 
* 
* Ϊ�˸��ñ�ӿڣ��ڵ�λ����Ϣ��������Ԫ�صĵ�ַ��ʾ����δ 
* ���ó���������ű�ʾ
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

