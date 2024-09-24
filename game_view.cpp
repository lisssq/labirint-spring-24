#include "game_view.h"

GameView::GameView(GameModel* _model)
{
    model = _model;     //присваиваетс€ значение указател€ _model переменной model, чтобы GameView мог использовать объект GameModel
    model->addObserver(this);       //GameView добавл€етс€ в качестве наблюдател€.  означает, что GameView будет уведомл€тьс€ об изменени€х в GameModel
}

void GameView::update()
{
    system("cls");      //очистка экрана
    cout << *this;      //вывод GameView
}

ostream& operator<<(ostream& out, const GameView& view)     //перегруженный оператор, позвол€ет объекту GameView вывестись в поток вывода
{
    view.printLabirint(out);        //вывод лабиринта
    view.printPosition(out);        //позиции
    view.printHealth(out);           //кол-ва жизней
    view.printCoins(out);           //монеток
    return out;
}

void GameView::printPosition(ostream& out) const
{
    out << " оординаты: (" << model->getX() << ", " << model->getY() << ")" << endl;
}

void GameView::printHealth(ostream& out) const
{
    out << "∆изни: " << model->live() << endl;
}

void GameView::printCoins(ostream& out) const
{
    out << "ћонеты: " << model->count_coins() << endl;
}