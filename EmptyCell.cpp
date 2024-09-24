#include "EmptyCell.h"
#include "PersonCell.h"
#include <iostream>

AbstractCell* EmptyCell::copy()
{
	return new EmptyCell(*this);
}

AbstractCell* EmptyCell::operator+(Person& person)
{
	return new PersonCell();
}

AbstractCell* EmptyCell::operator-(Person& person)
{
	return new EmptyCell();
}

void EmptyCell::visit(ostream& out) const
{
	out << ".";
}

