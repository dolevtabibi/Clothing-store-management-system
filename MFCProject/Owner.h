#pragma once
#include "GlobalEmployee.h"
class Owner : public GlobalEmployee
{

private:
	CString _storeName;

public:

	Owner(CString storename, CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary, int degree);
	void setStoreName(CString name);
	virtual CString getStoreName();
	virtual double getSalary() { return 0; }
};

