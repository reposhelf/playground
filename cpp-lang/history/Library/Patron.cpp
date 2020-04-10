
//  Patron.cpp

//  includes 

#include "Patron.h"

//  member functions

//  constructors

Patron::Patron( Name n, int c, double f, bool p )
	: _name( n ), _card( c ), _fee( f ), _pay( p ) {}

Patron::Patron() 
	: _name(), _card(), _fee(), _pay(false)  {}

//  set_name()

void Patron::set_name() {
	string fn, sn;
	Name name;

	cout << "Name: \t\t";
	cin >> fn >> sn;
	name.fName = fn;
	name.sName = sn;
	_name = name;
}

//  set_card()

void Patron::set_card() {
	cout << "Card: \t\t";
	cin >> _card;
}

//  set_fee()

void Patron::set_fee() {
	cout << "Fee: \t\t";
	cin >> _fee;
}

//  set_pay()

void Patron::set_pay() {
	char answer;
	bool correct = false;
	
	while ( !correct ) {
		correct = true;
		cout << "Pd.? (y/n)\t";
		cin >> answer;
		switch ( answer ) {
			case 'y': _pay = true; break;
			case 'n': _pay = false; break;
			default: correct = false;
		}
	}
}

//  set()

void Patron::set() {
	set_name ();
	set_card ();
	set_fee  ();
	set_pay  ();
}

//  helper functions

//  pay()

string pay( Patron& p ) {
	return  p.get_pay() ? "Yes." : "No.";
}

//  operator<<()

ostream& operator<<( ostream& os, Patron& p ) {
	return os << "\nName: \t" << p.get_name () 
	          << "\nCard: \t" << p.get_card ()
			  << "\nFee: \t"  << p.get_fee  ()
			  << "\nPd.:\t"   << pay        ( p ) << endl;
}

ostream& operator<<( ostream& os, Name& n ) {
	return os << n.fName << " " << n.sName;
}

//  end of Patron.cpp