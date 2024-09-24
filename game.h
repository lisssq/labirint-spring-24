#pragma once
//#include "cell.h"
#include "CoinCell.h"
#include"hero.h"
#include<iostream>
#include "WallCell.h"
#include "EmptyCell.h"
#include "PersonCell.h"


using namespace std;
enum ACTION     //�������� ��� ����������� ��������� � ����
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game      //���� ����
{
    int h;      //������
    int w;      //������

    //int m; //������� �������
    //Cell** labirint;    //��������� ��� �������� ��������� ��� 2�-���� �������

    Person person;      //�������� ���������� � ���������
    int r;
    void setpersonPose(int i, int j);   //�����, ����������� ���������� ���������� ���������
    AbstractCell*** labirint;

public:
    
    Game();     //������������� ������� � ������� ����
    Game(const Game& g);    //����������� ����
    ~Game();       //����������, ������������� ������ 
    void move(ACTION act);  //����� ��� ����������� 
    friend ostream& operator << (ostream& out, Game& g);        //������������� ��������, ��������� ��������� ����
    friend istream& operator >> (istream& in, Game& g);
    Game& operator =(const Game& other);   //������������

};
