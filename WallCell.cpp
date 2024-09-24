#include"WallCell.h"
#include "PersonCell.h"
#include "EmptyCell.h"
#include "Errors.h"


AbstractCell* WallCell::copy()
{
	return new WallCell(*this);
}

AbstractCell* WallCell::operator+(Person& person)
{
	person.smash();
	throw ydar_wall();
	return new PersonCell();
}

AbstractCell* WallCell::operator-(Person& person)
{
	person.smash();
	return new EmptyCell();
}

void WallCell::visit(ostream& out) const
{
	out << "#";
}