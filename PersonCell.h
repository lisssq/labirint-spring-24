#pragma once
#include "AbstractCell.h"
#include "EmptyCell.h"

using namespace std;

class PersonCell : public AbstractCell
{
public:

    AbstractCell* copy();

    AbstractCell* operator+(Person& person);

    AbstractCell* operator-(Person& person);

    void visit(ostream& out) const;

};