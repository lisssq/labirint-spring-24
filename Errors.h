#pragma once
#include <exception>
#include<iostream>

using namespace std;

class ydar_wall : exception
{
private:
	string message;

public:
	ydar_wall()
	{
		message = "нельзя ходить через стены!";
	}
	ydar_wall(const string& message) : message{ message } {}		//конструктор класса ydar_wall
	const char* what() const noexcept override		//объявление метода what(), который переопределяет виртуальную функцию из класса exception
	{
		return message.c_str();		//возвращаемое значение метода what(). 
									//возвращает указатель на строку (массив символов), содержащую сообщение об ошибке, доступное из message
	}
};


class lives_lost :exception
{
private:
	string message;

public:
	lives_lost()
	{
		message = "не осталось жизней!";
	}

	lives_lost(const string& message) : message{ message } {}		
	const char* what() const noexcept override		
	{
		return message.c_str();		
	}
};


class need_more_coins :exception
{
private:
	string message;

public:
	need_more_coins()
	{
		message = "соберите больше монет!";
	}

	need_more_coins(const string& message) : message{ message } {}		
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};


class need_more_hits :exception		//нужно больше ударов, чтобы убить монстра
{
private:
	string message;

public:
	need_more_hits()
	{
		message = "сделайте больше ударов, чтобы убить монстра!";
	}

	need_more_hits(const string& message) : message{ message } {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

