#pragma once
#include "pch.h"
#include "EnemyFactory.h"
#include <iostream>

class MyString
{
public:
	MyString();
	~MyString();
	void SetString(char* string, int length);
private:
	char * string;
	int length;
};

