#include "game_controller.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>

GameController::GameController(GameModel* model)
{
    _model = model;
}

void GameController::start()
{
    const int ARROW_UP = 72;
    const int ARROW_RIGHT = 77;
    const int ARROW_DOWN = 80;
    const int ARROW_LEFT = 75;

    int key;

    while (true) {
        key = _getch();
        if (key == 0 or key == 224) {
            switch (_getch()) {
            case ARROW_UP:
                _model->moveHeroUp();
                break;
            case ARROW_RIGHT:
                _model->moveHeroRight();
                break;
            case ARROW_DOWN:
                _model->moveHeroDown();
                break;
            case ARROW_LEFT:
                _model->moveHeroLeft();
                break;
            }
        }
    }
}