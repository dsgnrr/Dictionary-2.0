#define _CRT_SECURE_NO_WARNINGS
#include "Pair.h"
#include<iostream>
#include <string>
using namespace std;

//istream& operator>>(istream& in, Pair& pair)// баги из-за неё не считываются первые символы строки
//{
//	char buff[20];
//	cin.ignore();
//	gets_s(buff, 20);
//	pair.SetRus(buff);
//	gets_s(buff, 20);
//	pair.SetEng(buff);
//	return in;
//}

ostream& operator<<(ostream& out, Pair& pair)
{
	cout << endl;
	out <<"Rus: " << pair.GetRus() << endl;
	out <<"Eng: " << pair.GetEng() << endl;
	return out;
}

void Pair::Input()
{
	char buff[20];
	gets_s(buff, 20);
	SetRus(buff);
	gets_s(buff, 20);
	SetEng(buff);
}

string Pair::GetRus()
{
	return rus;
}

string Pair::GetEng()
{
	return eng;
}

void Pair::SetRus(string ru)
{
	rus = ru;
}

void Pair::SetEng(string en)
{
	eng = en;
}
