#include "pch.h"
#include "Managers.h"

Managers::Managers(CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary, CString Username , CString Password, int degree) : GlobalEmployee(ID, Name, dateofjoin, age, type, salary, degree)
{
	this->_username = Username;
	this->_password = Password;
	this->_degree = 1;
}

double Managers::getSalary()
{
	return _salary;
}
