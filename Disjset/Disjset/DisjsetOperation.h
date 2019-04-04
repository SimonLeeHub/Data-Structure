/*!
* \brief ���ཻ�������鼯�����������ӿ���
* 
* ������ʼ����1�����ϲ���1������ң�1����3���������� 
* 
* \author Lee  
* \date 2019.04.04 
*/
#pragma once
#define NumSet 16
typedef int ElementType;
typedef int SetType;
typedef int Disjset[NumSet+1];
class CDisjsetOperation
{
public:
	CDisjsetOperation(void);
	virtual ~CDisjsetOperation(void);

	virtual void createSet(Disjset S) = 0;
	virtual void setUnion(Disjset S, SetType root1, SetType root2) = 0;
	virtual SetType find(ElementType X, Disjset S) = 0;

	// ������������
	virtual void printSet(Disjset S) = 0;

	std::string description;
};

