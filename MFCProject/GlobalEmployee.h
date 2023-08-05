#pragma once
#include "Workers.h"

class GlobalEmployee : public Workers
{

protected :
	int _degree; 

public:
	GlobalEmployee(CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary, int degree);
	virtual double getSalary();
};

