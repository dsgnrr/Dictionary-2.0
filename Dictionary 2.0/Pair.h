#pragma once
#include <iostream>
#include<string>
using namespace std;

class Pair
{
	string rus;
	string eng;
public:
	Pair() = default;
	Pair(string ru, string en) :rus(ru), eng(en) {}
	//friend istream& operator>>(istream& in, Pair& pair);
	friend ostream& operator<<(ostream& out, Pair& pair);
	void Input();
	string GetRus();
	string GetEng();
	void SetRus(string ru);
	void SetEng(string en);
};

