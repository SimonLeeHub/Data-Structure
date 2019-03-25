/*!
* \brief 哈希表开放定址法——双散列类 
* 
* 采用开放定址法解决冲突；
* 双散列:
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

