#pragma once
#include "Observer.h"
#include <vector>

class Observable        //����������� ������, ��������� ��������� ����� ������������ �� ����������
{
private:
    
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer)        //��������� ������ ����������� � ������ ������������
    {
        observers.push_back(observer);      //��������� ���������� ����������� � ����� ������� observers
    }

    void notifyUpdate()     //��������� ���� ������������ � �����-���� ����������.
    {
        size_t size = observers.size();     //������������� ���������� ��������� � ������� observers, ����� �������� ��������� ������� size()
        for (size_t i = 0; i < size; i++)       // ����, ������� ���������� ��� �������� ������� observers
        {
            observers[i]->update();     //���������� ����� update() ��� ������� �����������, ����� ���������� �� �� ����������.
        }
    }


};