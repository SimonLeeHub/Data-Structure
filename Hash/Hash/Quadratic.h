/*!
* \brief 哈希表开放定址法——平方检测类 
* 
* 采用开放定址法解决冲突；
* 平方检测:
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

