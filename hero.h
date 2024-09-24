#pragma once
#include<iostream>
#include "Errors.h"
using namespace std;

class Person
{
	int x, y;
	int coin = 0;
	int health = 5;
public:
	
	Person(int _x = 0, int _y = 0) : x(_x), y(_y) {};	//координаты персонажа начальные по умолчанию
	int getX() { return x; }		//возврат текущих значний
	int getY() { return y; }
	void move(int _x = 0, int _y = 0) { x = _x; y = _y; }	//перемещение персонажа в указанные координаты
		
	//friend ostream& operator<<(ostream& out, Person& p);

	void getCoin() { coin++; }	//собирает монетки
	int count_coins() { return coin; }	//возкращает кол-во монеток
	void smash() 
	{ 
		health--;	//когда стукается, мы отнимаем 1 жизнь
		if (health <=0)
		{
			
			throw lives_lost();
		}
	}	

	int live() { return health; }

};