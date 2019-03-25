/*!
* \brief ��ϣ���Ŷ�ַ������˫ɢ���� 
* 
* ���ÿ��Ŷ�ַ�������ͻ��
* ˫ɢ��:
* h1(k) = key % tableSize
* h2(k) = 1 + key % (tableSize - 1)
* h(k) = (h1(k) + i*h2(k)) % tableSize
* 
* \author Lee  
* \date 2019.03.25 
*/
#pragma once
#include "openaddress.h"
class CDoubleHash :
	public COpenAddress
{
public:
	CDoubleHash(void);
	~CDoubleHash(void);

	Index hash(Key key, vHashTable H);
};

