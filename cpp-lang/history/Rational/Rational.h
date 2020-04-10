
// rational.h

#ifndef RATIONAL_H
#define RATIONAL_H

//  includes

#include "std_lib_facilities.h"

//  types

class Rational {
public:
	Rational();
	Rational( int, int );

	//  unmodifying func-s
	int get_numerator	() const { return _numerator; }
	int get_denominator () const { return _denominator; }

	//  modified func-s
	void reduction();

private:	
	int   _numerator;
	int   _denominator;
};

//  overloaded operators

ostream& operator<<( ostream&, Rational& );
Rational operator+( Rational&, Rational& );
Rational operator-( Rational&, Rational& );
Rational operator*( Rational&, Rational& );
Rational operator/( Rational&, Rational& );
bool operator==( Rational&, Rational& );

#endif // !defined RATIONAL_H

//  end of rational.h