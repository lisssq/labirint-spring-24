#include "game_view.h"

GameView::GameView(GameModel* _model)
{
    model = _model;     //������������� �������� ��������� _model ���������� model, ����� GameView ��� ������������ ������ GameModel
    model->addObserver(this);       //GameView ����������� � �������� �����������.  ��������, ��� GameView ����� ������������ �� ���������� � GameModel
}

void GameView::update()
{
    system("cls");      //������� ������
    cout << *this;      //����� GameView
}

ostream& operator<<(ostream& out, const GameView& view)     //������������� ��������, ��������� ������� GameView ��������� � ����� ������
{
    view.printLabirint(out);        //����� ���������
    view.printPosition(out);        //�������
    view.printHealth(out);           //���-�� ������
    view.printCoins(out);           //�������
    return out;
}

void GameView::printPosition(ostream& out) const
{
    out << "����������: (" << model->getX() << ", " << model->getY() << ")" << endl;
}

void GameView::printHealth(ostream& out) const
{
    out << "�����: " << model->live() << endl;
}

void GameView::printCoins(ostream& out) const
{
    out << "������: " << model->count_coins() << endl;
}