#include "Dictionary.h"
#include <iostream>
#include <conio.h>
using namespace std;
Dictionary::Dictionary(int s)
{
	size = s;
	arr = new Pair[size];
	for (int i = 0; i < size; i++)
	{
		arr[i].Input();
	}
}

Dictionary::Dictionary(const Dictionary& dict)
{
	size = dict.size;
	for (int i = 0; i < size; i++)
	{
		arr[i] = dict.arr[i];
	}
}

Dictionary& Dictionary::operator=(const Dictionary& dict)
{
	if (this == &dict)
	{
		size = dict.size;
		if (arr != nullptr)
		{
			delete[]arr;
		}
		arr = new Pair[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = dict.arr[i];
		}
		return *this;
	}
	return *this;
}

Dictionary::~Dictionary()
{
	delete[]arr;
}

void Dictionary::Input()
{
	if (arr != nullptr)
		delete[]arr;
	cout << "Enter size: ";
	cin >> size;
	cin.ignore();
	arr = new Pair[size];
	cout << "Enter pair data:" << endl;
	for (int i = 0; i < size; i++)
	{
		 arr[i].Input();
	}

}

void Dictionary::SearchRus(string ru)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetRus() == ru)
		{
			cout << "Rus: " << arr[i].GetRus() << endl;
			break;
		}
		else
			cout << "Error" << endl;
	}
}

void Dictionary::SearchEng(string en)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetEng() == en)
		{
			cout << "Eng: " << arr[i].GetEng() << endl;
			break;
		}
		else
			cout << "Error" << endl;
	}
}

void Dictionary::Replace(string word)
{
	char buff[20];
	char choice;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetRus() == word)
		{
			cout << "Select word what you wnat replace: \n1. Rus\n2. Eng" << endl;
			choice = _getch();
			switch (choice)
			{
			case'1':
				cout << "Edit: ";
				cin.ignore();
				cin.getline(buff, 20);
				arr[i].SetRus(buff); break;
			case'2':
				cout << "Edit: ";
				cin.ignore();
				cin.getline(buff, 20);
				arr[i].SetEng(buff); break;
			default:
				cout << "error. this variant is not exist" << endl;
			}
			break;
		}
		else if (arr[i].GetEng() == word)
		{
			cout << "Select word what you want replace: \n1. Rus\n2. Eng" << endl;
			choice = _getch();
			switch (choice)
			{
			case'1':
				cout << "Edit: ";
				cin.ignore();
				cin.getline(buff, 20);
				arr[i].SetRus(buff); break;
			case'2':
				cout << "Edit: ";
				cin.ignore();
				cin.getline(buff, 20);
				arr[i].SetEng(buff); break;
			default:
				cout << "error. this variant is not exist" << endl;
			}
			break;
		}
		else
			cout << "Error" << endl;
	}
}

void Dictionary::Delete(string word)
{
	int element = 0;
	bool check = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetEng() == word)
		{
			element = i;
			check = true;
			cout << "We're delete:" << arr[i].GetEng() << endl;
			break;
		}
		else if (arr[i].GetRus() == word)
		{
			element = i;
			check = true;
			cout << "We're delete:" << arr[i].GetRus() << endl;
			break;
		}
		else
		{
			check = false;
		}
	}
	if (check == true)
	{
		Pair* temp = nullptr;
		int temp_size = size - 1;
		temp = new Pair[temp_size];

		for (int i = 0; i < element; i++)
		{
			temp[i] = arr[i];
		}
		for (int i = element, j = element + 1; j < size, i < temp_size; j++, i++)
		{
			temp[i] = arr[j];
		}
		delete[]arr;
		size = size - 1;
		arr = new Pair[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		delete[]temp;
	}
	else
		cout << "Sorry. Your word is not exist" << endl;
}

//istream& operator>>(istream& in, Dictionary& dict) //Работает но есть баг
//{
//	cout << "Enter size: ";
//	in >> dict.size;
//	cout << "Enter pair Data: " << endl;
//	for (int i = 0; i < dict.size; i++)
//	{
//		in >> dict.arr[i];
//		in.ignore();
//	}
//	return in;
//}

ostream& operator<<(ostream& out, Dictionary& dict)
{
	out <<"Size: " << dict.size << endl;
	for (int i = 0; i < dict.size; i++)
	{
		out << dict.arr[i] << endl;
	}
	return out;
}
