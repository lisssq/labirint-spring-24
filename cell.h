#pragma once
#include"hero.h"
#include<iostream>
#include<fstream>

using namespace std;

class Cell 
{
	char val;	//������ �������� ������ ���������
	Person* person;	//��������� �� ������ ���� Person ������� �������� ����������

public:

	Cell();
	Cell(Person* _person);
	Cell(char _val);
	char getv() { return val; }
	void set_person(Person* _person);
	friend ostream& operator<<(ostream& out, Cell& c);
	friend istream& operator>>(istream& in, Cell& �);
	bool have_person();
	int operator +(Cell c);
};