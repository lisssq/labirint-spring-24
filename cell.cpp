#include "cell.h"
#include<iostream>
#include<fstream>

Cell::Cell()
{
	person = nullptr;	//нет персонажа
	val = ' ';			//пустая ячейка
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

ostream& operator<<(ostream& out, Cell& c)	//перегруженный оператор "<<" для вывода объектов класса Cell в стандарт.поток
{
	if (c.have_person())	//если ячейка содержит персонажа, то 
	{
		out << "R";			
	}
	else					//иначе выводим то, что хранится в ячейке
	{
		out << c.getv();
		}
	return out;
}

istream& operator>>(istream& in, Cell& с)	//для считывания
{
	
	in >> с.val;
	return in;
}

bool Cell::have_person()		//проверяет есть ли персонаж. если да, то возвращает true
{
	return person != nullptr;
}


int Cell:: operator +(Cell c) //перегруженный оператор "+", проверяет возможность перемещения в след клетку. 
{
	if ((c.getv() == '#')||(c.getv() == '/'))	//если значение ячейки - решетка или стенка, то двигаться в эту клетку нельзя
		return 0;
	if (c.getv() == '.')	//если же точка, то в ячейку можно переместиться
		return 1;
	if (c.getv() == '$')	//если в клетке лежит монетка
		return 2;


	if (c.getv() == '*')
		return 3;
}