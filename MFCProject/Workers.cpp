#include "pch.h"
#include "Workers.h"

Workers::Workers(CString ID, CString name, COleDateTime DateOfJoin, int age, int type, double salary)
{
	this->_ID =ID;
	this->_name = name;
	this->_DateOfJoin = DateOfJoin;
	this->_age = age;
	this->_salary = salary;
	this->_type = type;
}

CString Workers::getID()
{
	return this->_ID;
}





