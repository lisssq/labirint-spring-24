#pragma once
#include "game_model.h"

class GameController {
private:
    GameModel* _model;

public:

    GameController(GameModel* model);

    void start();
};