#include "pch.h"
#include "Owner.h"

Owner::Owner(CString storename, CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary, int degree) : GlobalEmployee(ID, Name, dateofjoin, age, type, salary, degree)
{
	CString _storeName;
	this->_degree = 3;
}

void Owner::setStoreName(CString name)
{
	this->_storeName = name;
}

CString Owner::getStoreName()
{
	return this->_storeName;
}
