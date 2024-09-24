#pragma once

#include "game_model.h"
#include <iostream>

class GameView : public Observer
{
private:
	GameModel* model;
public:
	GameView(GameModel*);

	void printLabirint(ostream&) const;
	void printPosition(ostream&) const;
	void printHealth(ostream&) const;
	void printCoins(ostream&) const;

	void update();		//обновление информации в соотвт. с изменениями модели
};