#pragma once
#include "Products.h"

class Pants : public Products
{

protected:
	static int arrayofpants[2]; // [0] = shortpants, [1]= longpants.
public:

	Pants(int amount, int type);

	virtual int getProduct();
	virtual void setType(int NewType);
	virtual void setAmount(int NewAmount);
	virtual int& getAmount(int Type);
	virtual int getType();
	virtual void updateInventory(int amount, int type);
	virtual int* getArray() { return this->arrayofpants; };

};

