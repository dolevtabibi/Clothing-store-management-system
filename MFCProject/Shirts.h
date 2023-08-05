#pragma once
#include "Products.h"

class Shirts : public Products
{
protected:
	static int arrayofshirts[4]; 

public:

	Shirts(int amount, int type);
	virtual void setType(int NewType);
	virtual void setAmount(int NewAmount);
	virtual int& getAmount(int Type);
	virtual int getType();
	virtual int getProduct();
	virtual void updateInventory(int amount, int type);
	virtual int* getArray() { return this->arrayofshirts; };

};


