#include"WallCell.h"
#include "PersonCell.h"
#include "EmptyCell.h"
#include "Errors.h"
#include "MonsterCell.h"
#include "hero.h"


AbstractCell* MonsterCell::copy()
{
	return new MonsterCell(*this);
}

AbstractCell* MonsterCell::operator+(Person& person)
{
	person.smash();
	monster_lives--;
	if (monster_lives > 0)
	{
		throw need_more_hits();
	}
	else
	{
		return new PersonCell();
	}
}

AbstractCell* MonsterCell::operator-(Person& person)
{
	return new EmptyCell();
}

void MonsterCell::visit(ostream& out) const
{
	out << "@";
}