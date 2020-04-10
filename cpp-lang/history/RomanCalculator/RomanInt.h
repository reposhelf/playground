
//  RomanInt.h

#ifndef ROMANINT_H
#define ROMANINT_H

//  includes

#include "std_lib_facilities.h"

//  functions declaration

bool check			( const char& );
vector<int> initial ( const string& ); 
int calculate		( vector<int>& );
bool duplicates     ( const string& );

//  type

class RomanInt {
public:
	RomanInt	() {}
	string get  () const { return _value; }
	void set	( string& str );
	int asInt   ();
private:
	string _value;
};

//  member functions

//  set()

void RomanInt::set( string& str ) {
  if ( duplicates(str) )
    _value = str;
  else
	error("error: too many identical roman characters");
}

//  asInt()

int RomanInt::asInt() {
	const int MaxLen = 9;
	vector<int> nums;
	int result = 0;
	//  length is ok?
	if (MaxLen < _value.size()) {
		error("error: too many roman characters");
		return -1;
	}
	//  transform each symbol into the appropriate number
	nums = initial( _value );

	return result = calculate( nums );
}

//  functions

//  operator<<()

ostream& operator<<( ostream& os, const RomanInt& r ) {
	return os << r.get();
}

//  operator>>()

istream& operator>>( istream& is, RomanInt& r ) {
	vector<char> roman;
	char temp;
	while ( true ) {
		is >> temp;
		if ( !( check( temp ))) { 
			is.unget();
			break;
		}
		roman.push_back( temp );
	}
	
	string str;
	
	for ( int i = 0; i < roman.size(); ++i ) 
    str += roman[ i ];
	r.set( str );
	return is;
}

//  initial()

vector<int> initial( const string& str ) {
	vector<int> nums;

	for ( int i = 0; i < str.size(); ++i ) {
		switch ( str[i] ) {
			case 'I': { nums.push_back( 1 );    break; }
			case 'V': { nums.push_back( 5 );    break; }
			case 'X': { nums.push_back( 10 );   break; }
			case 'L': { nums.push_back( 50 );   break; }
			case 'C': { nums.push_back( 100 );  break; }
			case 'D': { nums.push_back( 500 );  break; }
			case 'M': { nums.push_back( 1000 ); break; }
		}
	}

	return nums;
}

//  calculate()

int calculate( vector<int>& nums ) {
	int result = nums[0];
	int sum = 0; // if the value of the element 
				 // more than the value of the next 
				 // element, add in this variable
	int dif = 0; // and vice, the value og the element
				 // less than the value of the next
				 // element, add here
	int prevElem = 0, nexElem = 1;

	for ( ; prevElem < nums.size()-1; ++prevElem, ++nexElem ) {
		if ( nums[prevElem] >= nums[nexElem] )
			sum += nums[prevElem];
		else
			dif += nums[prevElem];
		// last element
		if ( nexElem == nums.size()-1 )
			sum += nums[nexElem];
	}

	if ( sum - dif ) result = sum - dif;

	return result;
}

//  duplicates()

bool duplicates( const string& str ) {
	const int MAX_IDENT = 3;
	int i = 0, j = 1;
	int ident = 0;

	for ( ; j < str.size(); ++i, ++j ) {
		if ( str[i] == str[j] )
			++ident;
		else 
			ident = 0;
	}

	if ( MAX_IDENT <= ident )
		return false;

	return true;
}

//  check()

bool check( const char& ch ) {
	switch ( ch ) {
	case 'I': case 'V': case 'X': case 'L': 
	case 'C': case 'D': case 'M': 
		return true;
	default: 
		return false;
  }
}

//  baseDigit()

string baseDigit( const int& val ) {
	string rom;
	
	switch ( val ) {
	case 1: rom = "I"; 
		break;
	case 5: rom = "V"; 
		break;
	case 10: rom = "X"; 
		break;
	case 50: rom = "L"; 
		break;
	case 100: rom = "C"; 
		break;
	case 500: rom = "D"; 
		break;
	case 1000: rom = "M"; 
		break;
	default:
		rom = "unknown base\n";
	}
	
	return rom;
}

//  intToRoman()

RomanInt intToRoman( int& val ) {
	string temp = "";
	int base = 0;
	RomanInt r;

	if ( (val < 0) || (val > 3999)  )
		error("error: the maximum value is exceeded");
	else
		while ( val > 0 ) {
			if ( (val >= 1) && (val <= 9) )
				base = 1;
			else if ( (val >= 10) && (val <= 99) )
				base = 10;
			else if ( (val >= 100) && (val <= 999) )
				base = 100;
			else if ( (val >= 1000) && (val <= 3999) )
				base = 1000;

			if ( val >= 9*base ) {
				temp += baseDigit( base ) + baseDigit( base*10 );
				val -= 9 * base;
			}
			else if ( val >= 5*base ) {
				temp += baseDigit( 5*base );
				val -= 5 * base;
			}
			else if ( val >= 4*base ) {
				temp += baseDigit( base ) + baseDigit( base*5 );
				val -= 4 * base;
			}
			while ( val >= base ) {
				temp += baseDigit( base );
			val -= base;
			}
		}
		
    r.set( temp );
	return r;
}

#endif  //  !defined ROMANINT_H