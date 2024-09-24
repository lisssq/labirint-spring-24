#pragma once
#include "hero.h"
#include "ExitCell.h"
#include "PersonCell.h"
#include <iostream>
#include "Errors.h"

using namespace std;

class ExitCell : public AbstractCell
{
	public:
		AbstractCell* copy();

		AbstractCell* operator+(Person& person);

		AbstractCell* operator-(Person& person);

		void visit(ostream& out) const;
};
