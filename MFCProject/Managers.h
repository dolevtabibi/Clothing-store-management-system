#pragma once
#include "GlobalEmployee.h"

class Managers : public GlobalEmployee
{
protected:
	CString _username;
	CString _password;

public:
	Managers(CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary, CString Username, CString Password, int degree);
	virtual double getSalary();

	// getters:

	virtual CString getUsername() { return this->_username ; }
	virtual CString getPassword() { return this->_password ; }

	//setters:

	virtual void setUsername(CString username) { this->_username = username; }
	virtual void setPassword(CString password) { this->_password = password; }

};

