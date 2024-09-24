#pragma once
#include "Observer.h"
#include <vector>

class Observable        //наблюдаемый объект, способный оповещать своих наблюдателей об изменениях
{
private:
    
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer)        //добавляет нового наблюдателя в список наблюдателей
    {
        observers.push_back(observer);      //добавляет переданный наблюдатель в конец вектора observers
    }

    void notifyUpdate()     //оповещает всех наблюдателей о каком-либо обновлении.
    {
        size_t size = observers.size();     //присваивается количество элементов в векторе observers, чтобы избежать повторных вызовов size()
        for (size_t i = 0; i < size; i++)       // цикл, который перебирает все элементы вектора observers
        {
            observers[i]->update();     //вызывается метод update() для каждого наблюдателя, чтобы оповестить их об обновлении.
        }
    }


};