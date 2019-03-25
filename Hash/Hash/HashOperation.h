/*!
* \brief ��ϣ����������ӿ��� 
* 
* ����������1���������ϣֵ��1������ɢ�У�1�������ң�1��������Ԫ��ֵ��1�������루1����ɾ��Ԫ�أ�1����ɾ����ϣ��1����8�ֻ�������
* 
* \author Lee  
* \date 2019.03.25 
*/
#pragma once
typedef int Key;
typedef unsigned int Index;
typedef int ElementType;
typedef void *vPostion;
typedef void *vHashTable;

class CHashOperation
{
public:
	CHashOperation(void);
	virtual ~CHashOperation(void);
	virtual vHashTable create(int tableSize) = 0;	//������ϣ��
	virtual Index hash(Key key, vHashTable H) = 0;	//�����ϣ���������ش洢λ��
	virtual vHashTable rehash(vHashTable H) = 0;	//��ɢ��
	virtual vPostion find(Key key, vHashTable H) = 0;	//����ɢ�б���Key����ӦԪ�ص�λ��
	virtual ElementType retrieve(vPostion P) = 0;	//����λ��P����Ӧ��Ԫ�ص�ֵ
	virtual void insert(Key key, ElementType X, vHashTable H) = 0;	//����Ԫ��
	virtual void deleteX(Key key, vHashTable H) = 0;        //ɾ��Ԫ��
	virtual void deleteHashTable(vHashTable H) = 0;	//���ɢ�б�

	//������������
	virtual void printHash(vHashTable H) = 0;	//��ӡ��ϣ��

	std::string description;
};

