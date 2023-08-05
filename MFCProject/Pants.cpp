#include "pch.h"
#include "Pants.h"


int Pants::arrayofpants[2] = { 0 };

Pants::Pants(int amount, int type) : Products(amount,  type)
{
	arrayofpants[type] += amount;
}

int Pants::getProduct()
{
	return 1;
}

void Pants::setType(int NewType)
{
	this->_type = NewType;
}

void Pants::setAmount(int NewAmount)
{
	this->_amount = NewAmount;
}

int& Pants::getAmount(int Type)
{
	return this->arrayofpants[Type];
}

int Pants::getType()
{
	return this->_type;
}

void Pants::updateInventory(int amount, int type)
{
	arrayofpants[type] += amount;
}
