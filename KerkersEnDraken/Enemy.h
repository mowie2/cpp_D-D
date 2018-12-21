#pragma once
#include "MyString.h"
class Enemy
{
public:
	Enemy();
	Enemy(MyString name, int level, int chanceAttack, int timesAttack, int minDamage, int maxDamage, int defense, int health);
	~Enemy();
private:
	
	MyString name;
	int level;
	int chanceAttack;
	int timesAttack;
	int minDamage;
	int maxDamage;
	int defense;
	int health;
	
};

