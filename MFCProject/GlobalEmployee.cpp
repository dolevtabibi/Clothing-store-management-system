#include "pch.h"
#include "GlobalEmployee.h"

GlobalEmployee::GlobalEmployee(CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary, int degree) : Workers(ID, Name, dateofjoin, age, type, salary)
{
	this->_degree = type;
}
double GlobalEmployee::getSalary()
{
	return this->_salary;
}
