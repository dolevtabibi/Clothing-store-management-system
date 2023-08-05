#pragma once
#include "Workers.h"
class PerHour : public Workers
{
protected: 
	double _salary;
	double _bonus;
	public:
		PerHour(CString ID, CString Name, COleDateTime dateofjoin, int age, int type, double salary, double bonus);
		virtual double getSalary();
		virtual void setUsername(CString username) { return; };
		virtual void setPassword(CString password) { return; };
		virtual CString getUsername() { return CString(" "); };
		virtual CString getPassword() { return CString(" "); };
		virtual double getBonus() { return this->_bonus; }
		virtual void setBonus(double bonus) { this->_bonus = bonus; }


};


