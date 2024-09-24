#include "ExitCell.h"
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include <cstdlib>
#include "Errors.h"

AbstractCell* ExitCell::copy()
{
	return new ExitCell(*this);
}

AbstractCell* ExitCell::operator+(Person& person)
{
	if (person.count_coins() >= 4)
	{
		//return new PersonCell();
		exit(0);
	}
	else
	{
		throw need_more_coins();
	}
}

AbstractCell* ExitCell::operator-(Person& person)
{
	return new ExitCell();
}

void ExitCell::visit(ostream& out) const
{
	out << "X";
}