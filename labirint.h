#pragma once
#include"AbstractCell.h"
#include"CoinCell.h"
#include"EmptyCell.h"
#include"ExitCell.h"
#include"MonsterCell.h"
#include"PersonCell.h"
#include"WallCell.h"
#include <fstream>
#include <iostream>

using namespace std;

class Labirint
{
private:
	int w, h;
	int start_x, start_y;
	AbstractCell*** labirint;
	Person person;

public:
	Labirint(const string&);
	Labirint(const Labirint&);
	~Labirint();

	friend istream& operator>>(istream& in, Labirint& labirint);

	int getStartX() const { return start_x; }
	int getStartY() const { return start_y; }
	int getWidth() const { return w; }
	int getHeight() const { return h; }

	Person& getHero() { return person; }
	int getHeroX() { return person.getX(); }
	int getHeroY() { return person.getY(); }
	int getHeroHealth() { return person.live(); }
	int getHeroCoins() { return person.count_coins(); }

	AbstractCell*& getCellAt(int x, int y) { return labirint[y][x]; }

};