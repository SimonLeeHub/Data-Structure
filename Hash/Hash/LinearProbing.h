/*!
* \brief ��ϣ���Ŷ�ַ���������Լ���� 
* 
* ���ÿ��Ŷ�ַ�������ͻ��
* ���Լ��:
* h1(k) = key % tableSize
* h(k) = (h1(k) + i) % tableSize
* 
* \author Lee  
* \date 2019.03.25 
*/
#pragma once
#include "openaddress.h"
class CLinearProbing :
	public COpenAddress
{
public:
	CLinearProbing(void);
	~CLinearProbing(void);

	Index hash(Key key, vHashTable H);
};

