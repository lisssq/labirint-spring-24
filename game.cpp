#include "game.h"
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include"hero.h"
#include "Errors.h"
#include "ExitCell.h"
#include "MonsterCell.h"
#include <stdio.h>
#include <conio.h>

void Game::setpersonPose(int i, int j) 
{
    char c = '.';
   
    if (((i < 0) || (j < 0) || (i >= h) || (j >= w)))   //если выходит за "стены" то ничего не делать   
    {
        return;
    }
    else
	{

        try         
        {
            AbstractCell* new_cell = *labirint[i][j] + person;  //нова€ €чейка в которую персонаж перемещаетс€
            if (new_cell != labirint[i][j])                 //если нова€ €чейка создалась, то
            {
                delete labirint[i][j];              //очищаем п€м€ть
                labirint[i][j] = new_cell;          //замен€ем указатель старой €чейки на новый
            }
            AbstractCell* old_cell = *labirint[person.getX()][person.getY()] - person;

            if (old_cell != labirint[person.getX()][person.getY()])     //если выше была создана нова€ €чейка, 
            {
                delete labirint[person.getX()][person.getY()];      //то стара€ €чейка удал€етс€ из пам€ти
                labirint[person.getX()][person.getY()] = old_cell;  //указатель на старую €чейку замен€етс€ указателем на новую €чейку
            }
       
            person.move(i, j);      //перемещаем персонажа в новую €чейку
        }
       
      
        catch (const ydar_wall& err)         //ищем исключение
        {
            cerr << "ошибка: " << err.what() << endl;
            _getch();
        }

        catch (const lives_lost& err)        
        {
            cerr << "ошибка: " << err.what() << endl;
            _getch();
            exit(0);
        }

        catch (const need_more_coins& err)      
        {
            cerr << "ошибка: " << err.what() << endl;
            _getch();
        }

        catch (const need_more_hits& err)         
        {
            cerr << "ошибка: " << err.what() << endl;
            _getch();
        }            
    }
}



Game::Game()
{
    ifstream in("labirint.txt");  //создаетс€ объект "файл" который используетс€ дл€ чтени€ 
    in >> w;  //считываем ширину и высоту
    in >> h;
    labirint = new AbstractCell * *[h];  //выдел€ем пам€ть дл€ хранени€ лабиринта

    for (int i = 0; i < h; i++)
    {
        labirint[i] = new AbstractCell * [w];
        for (int j = 0; j < w; j++)
        {
            char c;
            in >> c;
            if (c == '.')
            {
                labirint[i][j] = new EmptyCell();
            }
            if (c == '$') {
                labirint[i][j] = new CoinCell();
            }
            if (c == '#') {
                labirint[i][j] = new WallCell();
            }
            if (c == 'X') {
                labirint[i][j] = new ExitCell();
            }
            if (c == '@') {
                labirint[i][j] = new MonsterCell();
            }
        }
    }
    labirint[0][0] = new PersonCell;
    //setpersonPose(0, 0);        //устанавливаем начальную позицию (0,0)
}


 Game::Game(const Game&g)       //копирование игры 
{
    h = g.h;
    w = g.w;
    labirint = new AbstractCell ** [h];      //выделение пам€ти
    for (int i = 0; i < h; i++)
    {
        labirint[i] = new AbstractCell*[w];
        for(int j=0; j < w; j++)
        {
            labirint[i][j]=g.labirint[i][j];    //копирование
        }
    }
    r = g.r;
    person = g.person;
}

Game& Game::operator =(const Game& other)   //присваивание
{
    if (&other == this) //проверка на присваивание самому себе
    {
        return *this;
    }
       
    for (int i = 0; i < h; i++) //освобождение пам€ти
    {
        for (int j = 0; j < w;j++)
        {
            delete[] labirint[i];
        }
        delete[] labirint;
    }
    delete[] labirint;

    h = other.h;    //копирование высоты и ширины
    w = other.w;

    //person = other.person;  //  опирование персонажа 
   

    labirint = new AbstractCell **[h];      //выделение пам€ти
    for (int i = 0; i < h; i++)
    {
       labirint[i] = new AbstractCell*[w];
       for (int j = 0; j < w; j++)
        {
           labirint[i][j] = other.labirint[i][j];               // ->copy();    //копирование          
        }
    }
    return *this;
}


Game::~Game()           //деструктор освобождает пам€ть выделенную дл€ хранени€ лабиринта
{   
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            delete[] labirint[i][j];
        }
        delete[] labirint[i];
    }
    delete[] labirint;
}


void Game::move(ACTION act  ) 
{
    int ip = person.getX(); //получаем текущее положение персонажа
    int jp = person.getY();
    switch (act) {
    case UP:
        ip--;
        break;
    case DOWN:
        ip++;
        break;
    case LEFT:
        jp--;
        break;
    case RIGHT:
        jp++;
        break;
    }
    setpersonPose(ip, jp);     //устанавливаем позицию геро€

}


ostream& operator << (ostream& out, Game& g)    //перегруженный оператор
{
    int ip = g.person.getX();   //получаем текцщие координаты персонажа
    int jp = g.person.getY();
    int r = 5;
    for (int i = ip - r; i <= ip + r; i++)      //выводим на экран окрестности персонажа
    {
        for (int j = jp - r; j <= jp + r; j++)
        {
            if ((i < 0) || (j < 0) || (i >= g.h) || (j >= g.w)) //проверка на то что положение персонажа находитс€ в границах лабиринта
            {           //если за границей лабиринта, то выводим /
                out << '/';
            }
            else
                out << g.labirint[i][j];    //если в границах лабиринта, то выводим содержимое клетки
        }
        out << endl;
    }
    out << " оличество собранных монеток: " << g.person.count_coins() << endl;
    out << "¬аше здоровье: " << g.person.live() << endl;

    return out;
}
    




































/*
Game::Game()
{
    h = 0;
    w = 0;

    labirint = nullptr;

    setpersonPose(0, 0);        //устанавливаем начальную позицию (0,0)
}
*/





/*
istream& operator>>(istream& in, Game& g)
{
    int h, w;
    in >> h >> w;
    g.labirint = new AbstractCell **[h];

    for (int i = 0; i < h; i++)
    {
        g.labirint[i] = new AbstractCell * [w];
        for (int j = 0; j < w; j++) 
        {
            in >> g.labirint[i][j];

        }
    }
}

*/










