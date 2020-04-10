
//  Patron.h

#ifndef PATRON_H
#define PATRON_H

//  includes

#include "std_lib_facilities.h"

//  types

//  Name {}

struct Name {
	string fName;
	string sName;
};

//  Patron {}

class Patron {
public:
	Patron( Name, int, double, bool );
	Patron();

	//  unmodified
	Name get_name  () const { return _name; }
	int get_card   () const { return _card; }
	double get_fee () const { return _fee; }
	bool get_pay   () const { return _pay; }

	//  modifying
	void set_name ();
	void set_card ();
	void set_fee  ();
	void set_pay  ();
	void set      ();

private:
	Name    _name;
	int 	_card;
	double 	_fee;
	bool 	_pay;
};

//  helper functions

//  operator<<()

ostream& operator<<( ostream&, Patron& );
ostream& operator<<( ostream&, Name& );

// pay()

string pay( Patron& );

#endif  // !defined PATRON_H

//  end of Patron.h