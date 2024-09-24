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
		message = "íåëüçÿ õîäèòü ÷åðåç ñòåíû!";
	}
	ydar_wall(const string& message) : message{ message } {}		//êîíñòðóêòîð êëàññà ydar_wall
	const char* what() const noexcept override		//îáúÿâëåíèå ìåòîäà what(), êîòîðûé ïåðåîïðåäåëÿåò âèðòóàëüíóþ ôóíêöèþ èç êëàññà exception
	{
		return message.c_str();		//âîçâðàùàåìîå çíà÷åíèå ìåòîäà what(). 
									//âîçâðàùàåò óêàçàòåëü íà ñòðîêó (ìàññèâ ñèìâîëîâ), ñîäåðæàùóþ ñîîáùåíèå îá îøèáêå, äîñòóïíîå èç message
	}
};

class lives_lost :exception
{
private:
	string message;

public:
	lives_lost()
	{
		message = "íå îñòàëîñü æèçíåé!";
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
		message = "ñîáåðèòå áîëüøå ìîíåò!";
	}

	need_more_coins(const string& message) : message{ message } {}		
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};


class need_more_hits :exception		//íóæíî áîëüøå óäàðîâ, ÷òîáû óáèòü ìîíñòðà
{
private:
	string message;

public:
	need_more_hits()
	{
		message = "ñäåëàéòå áîëüøå óäàðîâ, ÷òîáû óáèòü ìîíñòðà!";
	}

	need_more_hits(const string& message) : message{ message } {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

