
//  rational.cpp

//  includes

#include "Rational.h"

//  member functions

//  constructor

Rational::Rational()
	: _numerator(), _denominator() {}

Rational::Rational( int n, int d )
	: _numerator( n ), _denominator( d ) {}

//  reduction()

void Rational::reduction() {
	int length = ( _numerator <= _denominator) ? _denominator : _numerator;
	for ( int i = length; i > 0; --i ) 
		if ( _numerator % i == 0 && _denominator % i == 0) {
			_numerator /= i;
			_denominator /= i;
		}
}

//  operator<<()

ostream& operator<<( ostream& os, Rational& rat ) {
	return os << rat.get_numerator()
			  << '/'
			  << rat.get_denominator();
}

//  operator+()

Rational operator+( Rational& rat1, Rational& rat2 ) {
	int lcm = 1;
	while ( ( lcm % rat1.get_denominator() != 0 ) || ( lcm % rat2.get_denominator() != 0 ) )
		++lcm;
	int num1 = lcm / rat1.get_denominator() * rat1.get_numerator();
	int num2 = lcm / rat2.get_denominator() * rat2.get_numerator();
	Rational rat_result(num1 + num2, lcm);

	return rat_result;
}

//  operator-()

Rational operator-( Rational& rat1, Rational& rat2 ) {
	int lcm = 1;
	while ( ( lcm % rat1.get_denominator() != 0 ) || ( lcm % rat2.get_denominator() != 0 ) )
		++lcm;
	int num1 = lcm / rat1.get_denominator() * rat1.get_numerator();
	int num2 = lcm / rat2.get_denominator() * rat2.get_numerator();
	Rational rat_result(num1 - num2, lcm);

	return rat_result;
}

//  operator*()

Rational operator*( Rational& rat1, Rational& rat2 ) {
	int num1 = rat1.get_numerator();
	int num2 = rat2.get_numerator();
	int den1 = rat1.get_denominator();
	int den2 = rat2.get_denominator();

	Rational rat_result( num1 * num2, den1 * den2 );
	return rat_result;
}

//  operator*()

Rational operator/( Rational& rat1, Rational& rat2 ) {
	int num1 = rat1.get_numerator();
	int num2 = rat2.get_numerator();
	int den1 = rat1.get_denominator();
	int den2 = rat2.get_denominator();

	Rational rat_result( num1 * den2, den1 * num2 );
	return rat_result;
}

//  operator==()

bool operator==( Rational& rat1, Rational& rat2 ) {
	rat1.reduction(); rat2.reduction();
	return ( rat1.get_numerator() == rat2.get_numerator() &&
			 rat1.get_denominator() == rat2.get_denominator() );
}

//  end of rational.cpp