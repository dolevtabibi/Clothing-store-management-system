#pragma once
#include "Products.h"
#include "Workers.h"
#include "Managers.h"
#include "vector"
#include <iostream>

using namespace std;

class dataStoring : public CObject
{

public:
	static vector<Workers*> workerList;
	static vector<Products*> productsList;
	void serializing(CArchive& arc);
	DECLARE_SERIAL(dataStoring);
	dataStoring() {};
	virtual ~dataStoring();
	void StoringProducts(CArchive& arc);
	void StoringWorkers(CArchive& arc);
};

