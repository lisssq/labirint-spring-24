#include "hero.h"
#include<iostream>

using namespace std;

ostream& operator<<(ostream& out, Person& p) 
{
	out << "P"; // ������ ��� ���������
	//out << " (" << p.money << ")"; // ���������� ��������� �������

	return out;
}