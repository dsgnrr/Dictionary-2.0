#pragma once
#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;

class Dictionary
{
	Pair* arr=nullptr;
	int size;
public:
	Dictionary() = default;
	Dictionary(int s);
	Dictionary(const Dictionary& dict);
	Dictionary& operator=(const Dictionary& dict);
	~Dictionary();
	void Input();
	//friend istream& operator >> (istream& in, Dictionary& dict);
	friend ostream& operator<<(ostream& out, Dictionary& dict);
	void SearchRus(string ru);
	void SearchEng(string en);
	void Replace(string word);
	void Delete(string word);
};

