#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Products.h"

using namespace std;

class Workers : public CObject
{
private:

protected:
	double _bouns;
	CString _ID;
	COleDateTime _DateOfJoin;
	CString _name;
	int _age;
	double _salary;

public:
	int _type;

	//Ctor
	Workers(CString ID, CString _name, COleDateTime _DateOfJoin, int age, int type, double salary);

	//getters : 
	CString getID();
	CString getName() { return this->_name; }
	int getAge() { return this->_age; }
	int getType() { return this->_type; }
	virtual double getSalary() = 0;
	COleDateTime getDateOfJoin() { return this->_DateOfJoin; }


	//setters: 
	void setType(int NewType) { this->_type = NewType; }
	void setName(CString NewName) { this->_name = NewName; }
	void setID(CString NewID) { this->_ID = NewID; }
	void setAge(int NewAge) { this->_age = NewAge; }
	void setDateOfJoin(COleDateTime NewDate) { this->_DateOfJoin = NewDate; }

	virtual CString getStoreName() { return CString(""); }
	virtual void setUsername(CString username) { return; };
	virtual void setPassword(CString password) { return; };
	virtual CString getUsername() { return 0; }
	virtual CString getPassword() { return 0; }
	virtual double getBonus() { return this->_bouns; }
	virtual void setBonus(double bouns) { this->_bouns = bouns; }
};

