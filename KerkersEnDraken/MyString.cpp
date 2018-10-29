#include "pch.h"
#include "MyString.h"


MyString::MyString()
{
}


MyString::~MyString()
{
	delete[] string;
}

void MyString::SetString(char *string, int length)
{
	delete[] this->string;
	this->string = new char[length];
	memcpy(this->string, string, length);
	this->length = length;
}

