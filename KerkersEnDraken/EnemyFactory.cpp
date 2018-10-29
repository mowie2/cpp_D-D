#include "pch.h"
#include "EnemyFactory.h"
#include <iostream>

EnemyFactory::EnemyFactory()
{
}


EnemyFactory::~EnemyFactory()
{
}


void EnemyFactory::searchParameters(char* &par)
{

	//par++;
	//searchName(par);
	char* buffer;

	par++;
	name = searchParameter(par, ";");

	par++;
	buffer = searchParameter(par, ";");
	level = atoi(buffer);
	delete[] buffer;

	par++;
	buffer = searchParameter(par, "x");
	chanceAttack = atoi(buffer);
	delete[] buffer;

	par++;
	buffer = searchParameter(par, ";");
	timesAttack = atoi(buffer);
	delete[] buffer;

	par++;
	buffer = searchParameter(par, "-");
	minDamage = atoi(buffer);
	delete[] buffer;

	par++;
	buffer = searchParameter(par, ";");
	maxDamage = atoi(buffer);
	delete[] buffer;

	par++;
	buffer = searchParameter(par, ";");
	defense = atoi(buffer);
	delete[] buffer;

	par++;
	buffer = searchParameter(par, "]");
	health = atoi(buffer);
	delete[] buffer;
}

char* EnemyFactory::searchParameter(char* &par,const char * split)
{
	int count = strstr(par, split) - par;
	char *buffer = new char[count+1];
	memcpy(buffer, par, count);
	buffer[count] = '\0';
	par += count;
	return buffer;
}


void EnemyFactory::read()
{
	std::ifstream is(".\\Files\\monsters.txt", std::ifstream::binary);
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

		//while (*bufferCopy != '\0') {
			if (*bufferCopy == '[') {
				searchParameters(bufferCopy);
			}
			bufferCopy++;
		//}
		
		is.close();
		delete[] buffer,name;
		_CrtDumpMemoryLeaks();
	}
}

