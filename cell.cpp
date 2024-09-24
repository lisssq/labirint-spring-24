#include "cell.h"
#include<iostream>
#include<fstream>

Cell::Cell()
{
	person = nullptr;	//��� ���������
	val = ' ';			//������ ������
}

Cell::Cell(Person* _person) : person(_person), val(' ') 
{
}

Cell::Cell(char _val) : person(nullptr), val(_val) 
{
}

void Cell::set_person(Person* _person)
{
	person = _person;
}

ostream& operator<<(ostream& out, Cell& c)	//������������� �������� "<<" ��� ������ �������� ������ Cell � ��������.�����
{
	if (c.have_person())	//���� ������ �������� ���������, �� 
	{
		out << "R";			
	}
	else					//����� ������� ��, ��� �������� � ������
	{
		out << c.getv();
		}
	return out;
}

istream& operator>>(istream& in, Cell& �)	//��� ����������
{
	
	in >> �.val;
	return in;
}

bool Cell::have_person()		//��������� ���� �� ��������. ���� ��, �� ���������� true
{
	return person != nullptr;
}


int Cell:: operator +(Cell c) //������������� �������� "+", ��������� ����������� ����������� � ���� ������. 
{
	if ((c.getv() == '#')||(c.getv() == '/'))	//���� �������� ������ - ������� ��� ������, �� ��������� � ��� ������ ������
		return 0;
	if (c.getv() == '.')	//���� �� �����, �� � ������ ����� �������������
		return 1;
	if (c.getv() == '$')	//���� � ������ ����� �������
		return 2;


	if (c.getv() == '*')
		return 3;
}