#pragma once
#include "AbstractCell.h"
#include "PersonCell.h"
#include "hero.h"

using namespace std;

class CoinCell : public AbstractCell
{
public:
	AbstractCell* copy();

	AbstractCell* operator+(Person& person);

	AbstractCell* operator-(Person& person);

	void visit(ostream& out) const;
};
