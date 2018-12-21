#include "pch.h"
#include "EnemyFactory.h"
#include <iostream>
#include <fstream>

EnemyFactory::EnemyFactory()
{
}


EnemyFactory::~EnemyFactory()
{
}

void EnemyFactory::SearchParameters(char* &par)
{	
	par++;
	name = SearchStringParameter(par, ";");

	par++;
	level = SearchStringParameter(par, ";").Parse();

	par++;
	chanceAttack = SearchStringParameter(par, "x").Parse();

	par++;
	timesAttack = SearchStringParameter(par, ";").Parse();

	par++;
	minDamage = SearchStringParameter(par, "-").Parse();

	par++;
	maxDamage = SearchStringParameter(par, ";").Parse();

	par++;
	defense = SearchStringParameter(par, ";").Parse();

	par++;
	health = SearchStringParameter(par, "]").Parse();
	Enemy newEnemy(name, level, chanceAttack, timesAttack, minDamage, maxDamage, defense, health);
	enemyList.AddItem(newEnemy);
}

MyString EnemyFactory::SearchStringParameter(char* &par,const char * split)
{
	int count = strstr(par, split) - par;
	MyString parameter(par, count);
	par += count;
	return parameter;
}


void EnemyFactory::Read(const char *filepath)
{
	std::ifstream is(filepath, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);
		char * buffer = new char[length];
		is.read(buffer, length);

		if (is)
			std::cout << "all characters read successfully.";
		else
			std::cout << "error: only " << is.gcount() << " could be read";
		

		// ...buffer contains the entire file...
		
		char* bufferCopy = buffer;
		
		while (*bufferCopy != '[') {
			bufferCopy++;
		}

		while (*bufferCopy != '\0') {
			if (*bufferCopy == '[') {
				SearchParameters(bufferCopy);
			}
			bufferCopy++;
		}
		
		is.close();
		delete[] buffer,bufferCopy;
		_CrtDumpMemoryLeaks();
	}
}

