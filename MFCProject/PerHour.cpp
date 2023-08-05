#include "pch.h"
#include "PerHour.h"

PerHour::PerHour(CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary,double bonus) : Workers(ID, Name, dateofjoin, age, type, salary)
{
	this->_salary = salary;
	this->_bonus = 500;
}

double PerHour::getSalary()
{
	return this->_salary;
}

