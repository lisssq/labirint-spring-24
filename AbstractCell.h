#pragma once
#include <iostream>
#include "hero.h"
//#include "AbstractCell.h"
//#include "EmptyCell.h"
//#include "PersonCell.h"
//#include "CoinCell.h"
//#include "WallCell.h"

using namespace std;

class AbstractCell 
{
public:

    virtual AbstractCell* copy() = 0;

    virtual AbstractCell* operator+(Person& person) = 0;

    virtual AbstractCell* operator-(Person& person) = 0;

    virtual void visit(ostream& out) const = 0;

    friend ostream& operator <<(ostream& out, AbstractCell* c)      
    {
        (*c).visit(out);    //вывод
        return out;
    }
   
};










































/*friend istream& operator >>(istream& in, AbstractCell*& c)
{
    char kl;
    in >> kl;
    if (kl == '.')
    {
        c = new EmptyCell();
    }
    if (kl == '$')
    {
        c = new CoinCell();
    }
    if (kl == '#')
    {
        c = new WallCell();

    }
}
*/