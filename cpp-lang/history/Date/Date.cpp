
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

//  set()

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

//  leapyear()

bool leapyear(int y) {
	return ( ( y % 4 == 0 && y % 100 != 0 ) || ( y % 400 == 0) ) ? true : false;
}

//  day_of_week()

void day_of_week( const Date& d) {
	//  counters
	int counter_day = 0;
	int counter_month = 0;
	//  output day title
	string str_day;
	//  default date
	int day = 1;
	int year = 1970;
	int month = 1;
			
	while ( day != d.get_day() || month != d.get_month() || year != d.get_year() ) {
		int days_in_month = 31;
		++day;

		switch ( month ) {
			case 2/*feb*/:
				days_in_month = ( leapyear( year ) ) ? 29 : 28;
				break;
			case 4/*apr*/: case 6/*jun*/: case 9/*sep*/: case 11/*nov*/:
				days_in_month = 30;
				break;
		}

		if ( days_in_month < day ) {
			day = 1;				
			if ( counter_month == 11 ) { 
				counter_month = 0; 
				++year; 
			}
			else ++counter_month;
		}
					
		if ( counter_day == 6 ) counter_day = 0;
		else ++counter_day;

		switch ( counter_month ) {
			case 0: month = 1; break;
			case 1: month = 2; break;
			case 2: month = 3; break;
			case 3: month = 4; break;
			case 4: month = 5; break;
			case 5: month = 6; break;
			case 6: month = 7; break;
			case 7: month = 8; break;
			case 8: month = 9; break;
			case 9: month = 10; break;
			case 10: month = 11; break;
			case 11: month = 12; break;
		}
	}

	switch ( counter_day ) {
		case 0: str_day =  "Thursday."; break;
		case 1: str_day =  "Friday."; break;
		case 2: str_day =  "Saturday."; break;
		case 3: str_day =  "Sunday."; break;
		case 4: str_day =  "Monday."; break;
		case 5: str_day =  "Tuessday."; break;
		case 6: str_day =  "Wednesday."; break;
	}

	cout << str_day;
}

//  easter()

void easter( int y) {
	int a;
	a = y % 19;
	cout << "a = " << a << endl;;
	int b;
	b = y % 4;
	cout << "b = " << b << endl;;
	int c;
	c = y % 7;
	cout << "c = " << c << endl;;
	int d;
	d = ( 19 * a + 15 ) % 30;
	cout << "d = " << d << endl;;
	int e;
	e = ( 2 * b + 4 * c + 6 * d + 6 ) % 7;
	cout << "e = " << e << endl;;
	int result;
	result = (d + e - 9) + 13;
	if ( result > 30 )
		result -= 30;
	cout << result;
}

//  end of Date.cpp