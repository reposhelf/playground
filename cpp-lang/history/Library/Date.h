
//  Date.h

#ifndef DATE_H
#define DATE_H

//  includes

#include "std_lib_facilities.h"

//  types

class Date {
public:
	Date( int, char, int, char, int );
	Date();

	//  modifying functions
	void set();

	//  unmodified functions
	int get_day      () const { return _day; }
	int get_month    () const { return _month; }
	int get_year     () const { return _year; }

private:
	int    _day;
	int    _month;
	int    _year;
	char   _separator1;
	char   _separator2;
	bool   date_is_correct( int&, int&, int&, char&, char& );
};

//  helper functions

//  operator<<()

ostream& operator<<( ostream&, Date& );

#endif  // !defined DATE_H

//  end of Date.h