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
	
	Person(int _x = 0, int _y = 0) : x(_x), y(_y) {};	//���������� ��������� ��������� �� ���������
	int getX() { return x; }		//������� ������� �������
	int getY() { return y; }
	void move(int _x = 0, int _y = 0) { x = _x; y = _y; }	//����������� ��������� � ��������� ����������
		
	//friend ostream& operator<<(ostream& out, Person& p);

	void getCoin() { coin++; }	//�������� �������
	int count_coins() { return coin; }	//���������� ���-�� �������
	void smash() 
	{ 
		health--;	//����� ���������, �� �������� 1 �����
		if (health <=0)
		{
			
			throw lives_lost();
		}
	}	

	int live() { return health; }

};