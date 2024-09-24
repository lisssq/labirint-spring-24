#pragma once
#include "AbstractCell.h"
#include"PersonCell.h"
#include"hero.h"
#include<iostream>

using namespace std;

class MonsterCell : public AbstractCell
{
    int monster_lives = 2;
public:

    AbstractCell* copy();

    AbstractCell* operator+(Person& person);

    AbstractCell* operator-(Person& person);

    void visit(ostream& out) const;

};