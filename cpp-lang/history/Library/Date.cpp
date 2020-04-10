
//  Date.cpp

//  includes

#include "Date.h"

//  member functions

//  constructors

Date::Date( int d, char s1, int m, char s2, int y )
	: _day( d ), _separator1( s1 ), _month( m ), _separator2( s2 ), _year( y ) {}

Date::Date()
	: _day( 1 ), _separator1 ( '.' ), _month( 1 ), _separator2( '.' ), _year( 2000 ) {}

//  date_is_correct()

bool Date::date_is_correct( int& d, int& m, int& y, char& s1, char& s2 ) {
	bool correct = true;

	if ( d <= 0 || d > 31 ) {
		cerr << "Invalid date format! Day must be greater than 0 or less than 32.\n";
		correct = false;
	}
	if ( _month <= 0 || _month > 12 ) {
		cerr << "Invalid date format! Month must be greater than 0 or less than 13.\n";
		correct = false;
	}
	if ( _year < 0 ) {
		cerr << "Invalid date format! Year must be greater than 0.\n";
		correct = false;
	}
	if ( _separator1 != '.' || _separator2 != '.' ) {
		cerr << "Invalid date format! Expected \".\".\n";
		correct = false;
	}

	return correct;
}

//  set_date()

void Date::set() {
	bool correct = false;
	//  use exception
	while ( !correct ) {
		correct = true;
		cout << "Enter reg. date: \t";
		cin >> _day;
		cin >> _separator1;
		cin >> _month;
		cin >> _separator2;
		cin >> _year;

		//  date is correct ?
		correct = date_is_correct( _day, _month, _year, _separator1, _separator2 );
	}
}

//  helper functions

//  operator<<()

ostream& operator<<( ostream& os, Date& d ) {
	return os << d.get_day   ()  << '.'
			  << d.get_month ()  << '.'
			  << d.get_year  ();
}

//  end of Date.cpp