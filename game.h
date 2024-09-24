#pragma once
//#include "cell.h"
#include "CoinCell.h"
#include"hero.h"
#include<iostream>
#include "WallCell.h"
#include "EmptyCell.h"
#include "PersonCell.h"


using namespace std;
enum ACTION     //действия для перемещения персонажа в игре
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game      //сама игра
{
    int h;      //высота
    int w;      //ширина

    //int m; //счётчик монеток
    //Cell** labirint;    //указатель для хранения лабиринта как 2х-ного массива

    Person person;      //хранение информации о персонаже
    int r;
    void setpersonPose(int i, int j);   //метод, позволяющий установить координаты персонажа
    AbstractCell*** labirint;

public:
    
    Game();     //инициализация объекты и игровое поле
    Game(const Game& g);    //копирование игры
    ~Game();       //деструктор, освобождающий память 
    void move(ACTION act);  //метод для перемещения 
    friend ostream& operator << (ostream& out, Game& g);        //перегруженный оператор, выводящий состояние игры
    friend istream& operator >> (istream& in, Game& g);
    Game& operator =(const Game& other);   //присваивание

};
