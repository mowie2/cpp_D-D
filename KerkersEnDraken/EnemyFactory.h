#pragma once
#include "fstream"
#include "Enemy.h"

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	void searchParameters(char* &par);
	char * searchParameter(char* &par,const char* split);
	void read();
private:
	char *name;
	int level;
	int chanceAttack;
	int timesAttack;
	int minDamage;
	int maxDamage;
	int defense;
	int health;
};

