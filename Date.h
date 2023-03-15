#include <iostream>
#include <string>
#include <vector>
#include "single_include/nlohmann/json.hpp";

using namespace std;
using json = nlohmann::json;
#pragma once


enum class Day {
	sunday, monday, tuesday, wednesday, thursday, friday, saturday  // 0 - 6
};

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, arg, sep, oct, nov, dec
};


class Date {
public:
	class Invalid{};
	Date(int dd, Month mm, int y); // constructor
	Date();                       //  default constructor 
	int get_day()const;
	Month get_month()const;
	int get_year()const;

private:
	int day_in_month;
	Month month;
	int year;
};

// For class Day ---> Function operator overloading << , ++
ostream& operator<< (ostream& os, const Day& a);
Day operator++(Day& a);

// For class Month ---> Function operator overloading << , ++
ostream& operator<< (ostream& os, const Month& month);
istream& operator>> (istream& is, Month& month);
Month operator++(Month& month);

// Function for class Date ----> operator overloading << , >>
ostream& operator<< (ostream& os, const Date& date);
istream& operator<< (istream& is, Date& date);



