#include "PersonCell.h"
#include "EmptyCell.h"


AbstractCell* PersonCell::copy()
{
	return new PersonCell(*this);
}

AbstractCell* PersonCell::operator+(Person& person)
{
	return new PersonCell();
}

AbstractCell* PersonCell::operator-(Person& person)
{
	return new EmptyCell();
}

void PersonCell::visit(ostream& out) const
{
	out << "P";
}