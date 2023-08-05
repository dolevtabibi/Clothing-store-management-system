#include "pch.h"
#include "dataStoring.h"
#include "GlobalEmployee.h"
#include "PerHour.h"
#include "Shirts.h"
#include "Pants.h"
#include "Owner.h"

vector<Workers*> dataStoring::workerList = {};
vector<Products*> dataStoring::productsList = {};

IMPLEMENT_SERIAL(dataStoring, CObject, 0);

dataStoring::~dataStoring()
{
	int workersize = workerList.size();
	int productsize = productsList.size();

		for (unsigned i = 0; i < workerList.size(); ++i)
			workerList.erase(workerList.begin() + i);

		for (unsigned i = 0; i < productsList.size(); ++i)
			productsList.erase(productsList.begin() + i);
}

void dataStoring::serializing(CArchive& arc)
{
	StoringWorkers(arc);
	StoringProducts(arc);
}


void dataStoring::StoringWorkers(CArchive& arc)
{
	int typeed;
	int numberofworkers = workerList.size();
	CString named;
	int aged;
	CString ided;
	COleDateTime joined;
	double salaryed;
	double bonused;
	CString usernamed;
	CString passworded;
	CString storeNamed;
	int degreed;
	if (arc.IsStoring()) //Storing the code(save);
	{
		arc << numberofworkers;
		for (int i = 0; i < numberofworkers; i++)
		{
			arc << workerList[i]->getID();
			arc << workerList[i]->getAge();
			arc << workerList[i]->getName();
			arc << workerList[i]->getDateOfJoin();
			arc << workerList[i]->getSalary();
			typeed = workerList[i]->getType(); // once for initalizing
			degreed = workerList[i]->getType();// other for degree
			arc << typeed;
			arc << degreed;
			switch (typeed)
			{
			case 0: // Global Workers
				break;
			case 1:// Managers
				arc << workerList[i]->getUsername();
				arc << workerList[i]->getPassword();
				break;

			case 2://Per Hour
				arc << workerList[i]->getBonus();
				break;
			case 3: // Owner
				arc << workerList[i]->getStoreName();

			default: _T("No such a thing");
				break;
			}
		}
	}
	else // // Loading the code;(load)
	{
		Workers* workerPtr;
		arc >> numberofworkers;
		for (int i = 0; i < numberofworkers; i++)
		{
			arc >> ided;
			arc >> aged;
			arc >> named;
			arc >> joined;
			arc >> salaryed;
			arc >> typeed;
			arc >> degreed;
			switch (typeed)
			{
			case 0: // Global Workers
				// typeed save twice, one for creating and second for to know the degree of is accesibilty
				workerPtr = new GlobalEmployee(ided, named, joined, aged, typeed, salaryed, typeed);
				break;
			case 1:
				arc >> workerList[i]->getUsername();
				arc >> workerList[i]->getPassword();
				// typeed save twice, one for creating and second for to know the degree of is accesibilty
				workerPtr = new Managers(ided, named, joined, aged, typeed, salaryed, usernamed, passworded, typeed);
				break;
			case 2:
				arc >> bonused;
				workerPtr = new PerHour(ided, named, joined, aged, typeed, salaryed, bonused);
				break;
			case 3:
				arc >> storeNamed;
				// typeed save twice, one for creating and second for to know the degree of is accesibilty.
				workerPtr = workerPtr = new Owner(storeNamed, ided, named, joined, aged, typeed, salaryed, typeed); // typeed save twice, one for creating and second for to know the degree of is accesibilty.
			default: _T("No such a thing");
				break;
			}
			dataStoring::workerList.push_back(workerPtr);
		}//end of for

	}
}

void dataStoring::StoringProducts(CArchive& arc)
{
	int typeed;
	int amounted;
	int* arrshirts;
	int* arrpants;
	int sizeoflistproduct = productsList.size();
	if (arc.IsStoring()) //Storing the code(save);
	{
		arrshirts = productsList[0]->getArray();
		arrpants = productsList[1]->getArray();
		arc << sizeoflistproduct;
		for (int i = 0; i < sizeoflistproduct; i++)
		{
			typeed = i;
			arc << typeed;
			switch (typeed)
			{
			case 0: // חולצה	
				for (int j = 0; j < 4; j++)
				{
					arc << arrshirts[j];
				}
				break;
			case 1:// מכנס
				for (int z = 0; z < 2; z++)
				{
					arc << arrpants[z];
				}
				break;

			default: _T("No such a thing");
				break;
			}
		}
	}
	else // Loading the code;(load)
	{
		Products* productPtr;
		int arrofpants[2];
		int arrofshirts[4];
		arc >> sizeoflistproduct;
		for (int i = 0; i < sizeoflistproduct; i++)
		{
			arc >> typeed;
			switch (typeed)
			{
			case 0: // חולצה
				productPtr = new Shirts(0, typeed);
				for (int j = 0; j < 4; j++) 
				{
					arc >> productPtr->getArray()[j];
				}
				break;
			case 1: // מכנס
				productPtr = new Pants(0, typeed);
				for (int z = 0; z < 2; z++)
				{
					arc >> productPtr->getArray()[z];
				}
				break;
			default: _T("No such a thing");
				break;
			}
			dataStoring::productsList.push_back(productPtr);
		}//end of for
	}
}