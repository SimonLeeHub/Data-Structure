/*!
* \brief ��ϣ���Ŷ�ַ������ƽ������� 
* 
* ���ÿ��Ŷ�ַ�������ͻ��
* ƽ�����:
* h1(k) = key % tableSize
* h(k) = (h1(k) + i^2) % tableSize
* 
* \author Lee  
* \date 2019.03.25 
*/
#pragma once
#include "openaddress.h"
class CQuadratic :
	public COpenAddress
{
public:
	CQuadratic(void);
	~CQuadratic(void);

	Index hash(Key key, vHashTable H);
};

