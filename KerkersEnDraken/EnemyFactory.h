#pragma once

#include "MyList.h"
#include "Enemy.h"

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	void SearchParameters(char* &par);
	MyString SearchStringParameter(char* &par,const char* split);
	void Read(const char *filepath);
private:
	MyList<Enemy> enemyList;
	MyString name;
	int level;
	int chanceAttack;
	int timesAttack;
	int minDamage;
	int maxDamage;
	int defense;
	int health;
};

