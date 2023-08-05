#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Products.h"

using namespace std;

class Products : public CObject 
{
protected:
	int _amount;

public:
	int _type;


	//Ctor

	Products(int amount, int type);

	//getters : 
	virtual int& getAmount(int Type) = 0;
	virtual int getType() = 0;

	virtual void updateInventory(int amount, int type) = 0;
	virtual int getProduct() = 0;

	//setters: 
	virtual void setType(int NewType) = 0;
	virtual void setAmount(int NewAmount) = 0;
	virtual int* getArray() = 0;



};
