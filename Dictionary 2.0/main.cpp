#include <iostream>
#include "Pair.h"
#include "Dictionary.h"
using namespace std;

void main()
{
	Dictionary obj;
	obj.Input();
	system("cls");
	cout << obj << endl;
	obj.Delete("Cat");
	cout << obj << endl;
}