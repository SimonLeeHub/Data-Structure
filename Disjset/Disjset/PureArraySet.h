/*!
* \brief ���鼯�Ĵ�����ʵ��
* 
* ��������Ԫ�ش洢�ľ��Ǽ��Ϻţ�����findΪO(1)
* ����union������Ҫ������������
* 
* \author Lee  
* \date 2019.04.04 
*/
#pragma once
#include "disjsetoperation.h"
class CPureArraySet :
	public CDisjsetOperation
{
public:
	CPureArraySet(void);
	~CPureArraySet(void);

	void createSet(Disjset S);
	void setUnion(Disjset S, SetType root1, SetType root2);
	SetType find(ElementType X, Disjset S);

	void printSet(Disjset S);
};

