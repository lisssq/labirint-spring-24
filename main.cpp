#include <iostream>
#include "game.h"
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <fstream>

#include "game_controller.h"
#include "game_model.h"
#include "game_view.h"


int main() 
{
	setlocale(LC_ALL, "Russian");

    string labirintPath = "labirint.txt";

    GameModel model(labirintPath);
    GameView view(&model);
    GameController controller(&model);

    view.update();
    controller.start();

    return 0;
}