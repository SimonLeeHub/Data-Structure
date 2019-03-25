// Hash.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SeparateChaining.h"
#include "LinearProbing.h"
#include "Quadratic.h"
#include "DoubleHash.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CHashOperation *pHT[4];
	pHT[0] = new CSeparateChaining;
	pHT[1] = new CLinearProbing;
	pHT[2] = new CQuadratic;
	pHT[3] = new CDoubleHash;

	for(int i=0;i<4;i++)
	{
		if(pHT[i])
		{
			std::cout<<pHT[i]->description;
			std::cout<<"Create hash table.\n";
			vHashTable H = pHT[i]->create(10);
			std::cout<<"Insert key 89 18 47 49 58 69.\n";
			pHT[i]->insert(89, 890, H);
			pHT[i]->insert(18, 180, H);
			pHT[i]->insert(47, 470, H);
			pHT[i]->insert(49, 490, H);
			pHT[i]->insert(58, 580, H);
			pHT[i]->insert(69, 690, H);
			pHT[i]->printHash(H);
			std::cout<<"The element of key 58 is "<<pHT[i]->retrieve(pHT[i]->find(58, H))<<std::endl;
			std::cout<<"Delete key 58.\n";
			pHT[i]->deleteX(58, H);
			pHT[i]->printHash(H);
			std::cout<<"Rehash old hash table.\n";
			H = pHT[i]->rehash(H);
			pHT[i]->printHash(H);
			std::cout<<"Delete hash table.\n";
			pHT[i]->deleteHashTable(H);
		}
	}

	std::cout<<"\n\n\nHash table structure has been tested, press any key to exit...\n";
	getchar();
	
	return 0;
}

