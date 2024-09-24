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
   
    if (((i < 0) || (j < 0) || (i >= h) || (j >= w)))   //���� ������� �� "�����" �� ������ �� ������   
    {
        return;
    }
    else
	{

        try         
        {
            AbstractCell* new_cell = *labirint[i][j] + person;  //����� ������ � ������� �������� ������������
            if (new_cell != labirint[i][j])                 //���� ����� ������ ���������, ��
            {
                delete labirint[i][j];              //������� ������
                labirint[i][j] = new_cell;          //�������� ��������� ������ ������ �� �����
            }
            AbstractCell* old_cell = *labirint[person.getX()][person.getY()] - person;

            if (old_cell != labirint[person.getX()][person.getY()])     //���� ���� ���� ������� ����� ������, 
            {
                delete labirint[person.getX()][person.getY()];      //�� ������ ������ ��������� �� ������
                labirint[person.getX()][person.getY()] = old_cell;  //��������� �� ������ ������ ���������� ���������� �� ����� ������
            }
       
            person.move(i, j);      //���������� ��������� � ����� ������
        }
       
      
        catch (const ydar_wall& err)         //���� ����������
        {
            cerr << "������: " << err.what() << endl;
            _getch();
        }

        catch (const lives_lost& err)        
        {
            cerr << "������: " << err.what() << endl;
            _getch();
            exit(0);
        }

        catch (const need_more_coins& err)      
        {
            cerr << "������: " << err.what() << endl;
            _getch();
        }

        catch (const need_more_hits& err)         
        {
            cerr << "������: " << err.what() << endl;
            _getch();
        }            
    }
}



Game::Game()
{
    ifstream in("labirint.txt");  //��������� ������ "����" ������� ������������ ��� ������ 
    in >> w;  //��������� ������ � ������
    in >> h;
    labirint = new AbstractCell * *[h];  //�������� ������ ��� �������� ���������

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
    //setpersonPose(0, 0);        //������������� ��������� ������� (0,0)
}


 Game::Game(const Game&g)       //����������� ���� 
{
    h = g.h;
    w = g.w;
    labirint = new AbstractCell ** [h];      //��������� ������
    for (int i = 0; i < h; i++)
    {
        labirint[i] = new AbstractCell*[w];
        for(int j=0; j < w; j++)
        {
            labirint[i][j]=g.labirint[i][j];    //�����������
        }
    }
    r = g.r;
    person = g.person;
}

Game& Game::operator =(const Game& other)   //������������
{
    if (&other == this) //�������� �� ������������ ������ ����
    {
        return *this;
    }
       
    for (int i = 0; i < h; i++) //������������ ������
    {
        for (int j = 0; j < w;j++)
        {
            delete[] labirint[i];
        }
        delete[] labirint;
    }
    delete[] labirint;

    h = other.h;    //����������� ������ � ������
    w = other.w;

    //person = other.person;  // ����������� ��������� 
   

    labirint = new AbstractCell **[h];      //��������� ������
    for (int i = 0; i < h; i++)
    {
       labirint[i] = new AbstractCell*[w];
       for (int j = 0; j < w; j++)
        {
           labirint[i][j] = other.labirint[i][j];               // ->copy();    //�����������          
        }
    }
    return *this;
}


Game::~Game()           //���������� ����������� ������ ���������� ��� �������� ���������
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
    int ip = person.getX(); //�������� ������� ��������� ���������
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
    setpersonPose(ip, jp);     //������������� ������� �����

}


ostream& operator << (ostream& out, Game& g)    //������������� ��������
{
    int ip = g.person.getX();   //�������� ������� ���������� ���������
    int jp = g.person.getY();
    int r = 5;
    for (int i = ip - r; i <= ip + r; i++)      //������� �� ����� ����������� ���������
    {
        for (int j = jp - r; j <= jp + r; j++)
        {
            if ((i < 0) || (j < 0) || (i >= g.h) || (j >= g.w)) //�������� �� �� ��� ��������� ��������� ��������� � �������� ���������
            {           //���� �� �������� ���������, �� ������� /
                out << '/';
            }
            else
                out << g.labirint[i][j];    //���� � �������� ���������, �� ������� ���������� ������
        }
        out << endl;
    }
    out << "���������� ��������� �������: " << g.person.count_coins() << endl;
    out << "���� ��������: " << g.person.live() << endl;

    return out;
}
    




































/*
Game::Game()
{
    h = 0;
    w = 0;

    labirint = nullptr;

    setpersonPose(0, 0);        //������������� ��������� ������� (0,0)
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










