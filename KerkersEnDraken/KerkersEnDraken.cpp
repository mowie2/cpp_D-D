// KerkersEnDraken.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include "MyString.h"
//#include "MyList.h"
#include "EnemyFactory.h"
#include <map>

void test() 
{
	EnemyFactory ef;
	//ef.Read(".\\Files\\monsters.txt");
	MyList<MyString> l;
	MyString m("hoi");
	MyString k("dag");
	l.AddItem(m);
	l.AddItem(k);
	
}

void test2() {
	std::map<unsigned int, const char*> smap1;
	std::map<unsigned int, const char*> smap2;
	std::map<unsigned int, const char*> smap3;

	smap1[1] = "afkljfewjl";
	smap1[2] = "bfkljfewjl";
	smap1[3] = "cfkljfewjl";

	smap2[4] = "dfkljfewjl";
	smap2[5] = "efkljfewjl";
	smap2[6] = "ffkljfewjl";

	smap3[7] = "gfkljfewjl";
	smap3[8] = "hfkljfewjl";
	smap3[9] = "ifkljfewjl";



	std::map<int, std::map<unsigned int, const char*>> amap1;
	amap1[1] = smap1;
	amap1[2] = smap2;
	amap1[3] = smap3;

	std::map<int, std::map<unsigned int, const char*>> amap2;
	//amap2.insert(amap1.begin(), amap1.end());
	amap2 = amap1;
	amap1.clear();


	const char* k = amap2[1][2];
	//amap1.clear();
}

int main()
{
	test2();
	_CrtDumpMemoryLeaks();
}


