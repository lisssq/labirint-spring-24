#include "CoinCell.h"
#include "EmptyCell.h"
#include "WallCell.h"
#include "PersonCell.h"
#include "AbstractCell.h"



AbstractCell* CoinCell::copy()
{
	return new CoinCell(*this);			//������� ������ ���������� ������� = �����
}

AbstractCell* CoinCell::operator+(Person& person)
{
	person.getCoin();	//�������� �������
	return new PersonCell();
}

AbstractCell* CoinCell::operator-(Person& person)
{
	return new EmptyCell();
}

void CoinCell::visit(ostream& out) const		//����� ���������� � ������
{
	out << "$";		//���������� �������
}