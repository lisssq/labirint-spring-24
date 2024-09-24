#pragma once

//класс, с помощью которого наблюдаемый объект оповещает наблюдателей

class Observer
{
public:
    virtual void update() = 0;
};