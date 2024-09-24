#pragma once
#include "AbstractCell.h"
#include "PersonCell.h"
#include "hero.h"
#include<iostream>

using namespace std;

class EmptyCell : public AbstractCell
{
public:

    AbstractCell* copy();

    AbstractCell* operator+(Person& person);

    AbstractCell* operator-(Person& person);

    void visit(ostream& out) const;
};