/*!
* \brief ���鼯�Ĳ��ཻɭ��ʵ��
* 
* ɭ�ֲ�������ʵ�֣�����Ԫ�ش洢���ڵ������
* ���ڸ��ڵ㣬��洢��ǰ�����ȣ��ο����ߣ��ĸ�ֵ
* ���ڵ��ڵ㣬����Ϊ1
* 
* \author Lee  
* \date 2019.04.04 
*/
#pragma once
#include "disjsetoperation.h"
class CForestSet :
	public CDisjsetOperation
{
public:
	CForestSet(void);
	~CForestSet(void);

	void createSet(Disjset S);
	void setUnion(Disjset S, SetType root1, SetType root2);
	SetType find(ElementType X, Disjset S);

	void printSet(Disjset S);
};

