
//  Library.cpp

//  includes

#include "Library.h"

//  member functions

//  constructor

Library::Library()
	: _book(), _patron(), _trans() {}

//  set_book()

void Library::set_book() {
	cout << "Enter book data...\n";
	Book book;
	char answer;
	bool finish = false;
	
	while ( !finish ) {
		book.set();
		_book.push_back( book );
		cout << "Continue? (y/n) ";
		cin >> answer;
		finish = ( answer == 'y' ) ? false : true;
	}
}

//  set_patron()

void Library::set_patron() {
	cout << "Enter patron data...\n";
	Patron patron;
	char answer;
	bool finish = false;

	while ( !finish ) {
		patron.set();
		_patron.push_back( patron );
		cout << "Continue? (y/n) ";
		cin >> answer;
		finish = ( answer == 'y' ) ? false: true;
	}
}

//  issuing()

void Library::issuing() {
	cout << "Issuing process . . . \n";
	Book b;
	b.set();
	Patron p;
	p.set();
	Date d;
	d.set();
	Transaction trans;
	trans.book = b;
	trans.patron = p;
	trans.date = d;
	_trans.push_back( trans );

	if ( !check( trans ) ) cerr << "Error!\n";
}

//  check()

bool Library::check( Transaction& t ) const {
	//  check patron
	for ( int i = 0; i < _patron.size(); ++i )
		if ( t.patron.get_card() != _patron[i].get_card() ) {
			cerr << "Not our patron!";
			return false;
		}
	//  check book
	for ( int i = 0; i < _book.size(); ++i )
		if ( t.book != _book[i] ) {
			cerr << "Not our book!";
			return false;
		}
	//  check pay
	for ( int i = 0; i < _patron.size(); ++i )
		if ( !_patron[i].get_pay() ) {
			cerr << "Not paid!";
			return false;
		}
	
	return true;
}

// debtors

vector<Name> Library::debtors() const {
	vector<Name> n;
	for ( int i = 0; i < _patron.size(); ++i )
		if ( !_patron[i].get_pay() )
			n.push_back( _patron[i].get_name() );

	return n;
}

//  end of Library.cpp