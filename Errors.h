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
		message = "������ ������ ����� �����!";
	}
	ydar_wall(const string& message) : message{ message } {}		//����������� ������ ydar_wall
	const char* what() const noexcept override		//���������� ������ what(), ������� �������������� ����������� ������� �� ������ exception
	{
		return message.c_str();		//������������ �������� ������ what(). 
									//���������� ��������� �� ������ (������ ��������), ���������� ��������� �� ������, ��������� �� message
	}
};


class lives_lost :exception
{
private:
	string message;

public:
	lives_lost()
	{
		message = "�� �������� ������!";
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
		message = "�������� ������ �����!";
	}

	need_more_coins(const string& message) : message{ message } {}		
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};


class need_more_hits :exception		//����� ������ ������, ����� ����� �������
{
private:
	string message;

public:
	need_more_hits()
	{
		message = "�������� ������ ������, ����� ����� �������!";
	}

	need_more_hits(const string& message) : message{ message } {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

