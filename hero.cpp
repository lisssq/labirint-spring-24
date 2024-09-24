#include "hero.h"
#include<iostream>

using namespace std;

ostream& operator<<(ostream& out, Person& p) 
{
	out << "P"; // символ для персонажа
	//out << " (" << p.money << ")"; // количество собранных монеток

	return out;
}