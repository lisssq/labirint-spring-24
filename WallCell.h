#pragma once
#include "AbstractCell.h"

using namespace std;

class WallCell : public AbstractCell
{
public:

    AbstractCell* copy();

    AbstractCell* operator+(Person& person);

    AbstractCell* operator-(Person& person);

    void visit(ostream& out) const;

};