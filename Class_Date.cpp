#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
using namespace std;

// Helper function
void error(string s)
{
	cout << s << endl;
}

// Implement class Day

ostream& operator<< (ostream& os, const Day& a)
{
	string print = "";
	switch (a)
	{
	case Day::monday:
		print = "Monday";
		break;
	case Day::tuesday:
		print = "Tuesday";
		break;
	case Day::wednesday:
		print = "Wednesday";
		break;
	case Day::thursday:
		print = "Thursday";
		break;
	case Day::friday:
		print = "Friday";
		break;
	case Day::saturday:
		print = "Saturday";
		break;
	case Day::sunday:
		print = "Sunday";
		break;
	default:
		print = "Invalid day";
		break;
	}
	return os << print;
}

Day operator++(Day& a)
{
	a = (a == Day::sunday) ? Day::monday : Day(int(a) + 1);
	return a;
}


//--------------------------------------------------------------------------------------

// Implement for class Month

ostream& operator<< (ostream& os, const Month& month)
{
	if (month < Month::sep) os << 0 << int(month);
	else os << int(month);
	return os;
	/*string print = "";
	switch (month)
	{
	case Month::jan:
		print = "January";
		break;
	case Month::feb:
		print = "Febuary";
		break;
	case Month::mar:
		print = "March";
		break;
	case Month::apr:
		print = "April";
		break;
	case Month::may:
		print = "May";
		break;
	case Month::jun:
		print = "June";
		break;
	case Month::jul:
		print = "July";
		break;
	case Month::arg:
		print = "August";
		break;
	case Month::sep:
		print = "September";
		break;
	case Month::oct:
		print = "October";
		break;
	case Month::nov:
		print = "November";
		break;
	case Month::dec:
		print = "December";
		break;
	default:
		print = "Invalid month";
		break;
	}*/
	
}

Month operator++ (Month& month)
{
	month = (month == Month::dec) ? Month::jan : Month(int(month) + 1);
	return month;
}


//--------------------------------------------------------------------------------------
// Implement for class Date

bool is_leap_year(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	return false;
}

int days_in_month(int year, Month m)
{
	int day = 0;
	switch (m)
	{
	case Month::jan : case Month::mar : case Month::may : case Month::jul :  case Month::arg : case Month::oct : case Month::dec :
		day = 31;
		break;
	case Month::apr : case Month::jun : case Month::sep : case Month::nov :
		day = 30;
		break;
	case Month::feb :
		if (is_leap_year(year)) day = 29;
		else day = 28;
		break;
	}
	return day;
}

bool is_valid_date(int day, Month m, int year)
{
	if (day <= 0 || day > days_in_month(year, m)) {
		return false;
	}
	if (m > Month::dec || m < Month::jan) return false;
	if (year <= 1600) return false;
	return true;
}


// Constructor
Date::Date(int day_month, Month mm, int y) : day_in_month{ day_month }, month{ mm }, year{ y } 
{
	if (!is_valid_date(day_month, mm, y)) throw Invalid{};
}


// Default constructor
Date::Date()
{
	day_in_month = 1;
	month = Month::jan;
	year = 2001;
}

int Date::get_day()const
{
	return day_in_month;
}

Month Date::get_month()const
{
	return month;
}

int Date::get_year()const
{
	return year;
}


// Operator overloading
ostream& operator<< (ostream& os, const Date& date)
{
	return os << date.get_day() << '/' << date.get_month() << '/' << date.get_year();
}


istream& operator>> (istream& is, Date& date)
{
	// Format day/month/year
	int day, month, year;
	char ch1, ch2;
	while (true) {
		if (is >> day >> ch1 >> month >> ch2 >> year) {
			if (ch1 == '/' && ch2 == '/') break;
			else cout << "Wrong format Ex: 6/3/2023" << endl;
		}
		else {
			is.clear();
		}
	}
	date = Date{ day,Month(month),year };
	return is;
}
