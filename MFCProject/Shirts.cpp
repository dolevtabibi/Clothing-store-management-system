#include "pch.h"
#include "Shirts.h"


int Shirts::arrayofshirts[4] = {0};

Shirts::Shirts(int amount, int type) : Products(amount, type)
{
	arrayofshirts[type] += amount;
}

void Shirts::setType(int NewType)
{
	this->_type = NewType;
}

void Shirts::setAmount(int NewAmount)
{
	this->_amount = NewAmount;
}

int& Shirts::getAmount(int Type)
{
	return this->arrayofshirts[Type];
}

int Shirts::getType()
{
	return this->_type;
}

int Shirts::getProduct()
{
	return 0;
}

void Shirts::updateInventory(int amount, int type)
{
	arrayofshirts[type] += amount;
}



