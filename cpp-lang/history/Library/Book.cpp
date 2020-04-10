
//  Book.cpp

//  includes

#include "Book.h"

//  member functions

//  constructor

Book::Book( string t, string a, Date d, ISBN i, bool av, Genre g )
		: _title( t ), _author( a ), _date( d ), _isbn( i ),  _availebility( av ), _genre( g ) {}

Book::Book()
	: _title(), _author(), _date(), _isbn(),  _availebility(), _genre() {}

//  set_title()

void Book::set_title() {
	cout << "Enter book title: \t";
	cin >> _title;
}

//  set_author()

void Book::set_author() {
	cout << "Enter book author: \t";
	cin >> _author;
}

//  set_date()

void Book::set_date() {
	_date.set();
}

//  set_isbn()

void Book::set_isbn() {
	bool correct = false;
	//  use exception!
	while ( !correct ) {
		correct = true;
		cout << "Enter ISBN: \t\t";
		cin >> _isbn.num1; 
		cin >> _isbn.dash1;
		cin >> _isbn.num2; 
		cin >> _isbn.dash2;
		cin >> _isbn.num3; 
		cin >> _isbn.dash3;
		cin >> _isbn.lit;

		//  ISBN is correct ?
		if ( _isbn.num1 < 0 || _isbn.num2 < 0 || _isbn.num3 < 0 ) {
			cerr << "Invalid ISBN format! The number can not be negative.\n";
			correct = false;
		}
		if ( _isbn.dash1 != '-' || _isbn.dash2 != '-' || _isbn.dash3 != '-' ) {
			cerr << "Invalid ISBN format! Exprcted \"-\"\n";
			correct = false;
		}
	}
}

//  set_status()

void Book::set_status() {
	char answer;
	bool correct = false;

	while ( !correct ) {
		correct = true;
		cout << "Available? (y/n) \t";
		cin >> answer;

		if ( answer != 'y' && answer != 'n' ) {
			cerr << "Invalid answer!\n";
			correct = false;
		}
	}

	_availebility = ( answer == 'y' ) ? true : false;
}

//  set_genre()

void Book::set_genre() {
	char answer;
	bool correct = false;

	while ( !correct ) {
		correct = true;
		cout << "Genre:\n";
		cout << "  1. Fanntasy.\n";
		cout << "  2. Prose.\n";
		cout << "  3. Periodicals.\n";
		cout << "  4. Biography.\n";
		cout << "  5. Childrens.\n";
		cin >> answer;

		switch ( answer ) {
			case '1': _genre = fantasy; break;
			case '2': _genre = prose; break;
			case '3': _genre = periodicals; break;
			case '4': _genre = biography; break;
			case '5': _genre = childrens; break;
			default: correct = false;
		}
	}
}

//  set()

void Book::set() {
	set_title   ();
	set_author  ();
	set_date    ();
	set_isbn    ();
	set_status  ();
	set_genre   ();
}

//  helper functions

//  operator<<()

ostream& operator<<( ostream& os, const Book& b ) {
	//  available ?
	string status;
	if ( b.get_status() ) 
		status = "Available";
	else 
		status = "Unavailable";

	//  output
	return os << "\nTitle: \t"  << b.get_title  ()
			  << "\nAuthor: "   << b.get_author ()
			  << "\nISBN: \t"	<< b.get_isbn   ()
			  << "\nDate:\t"    << b.get_date()
			  << "\nGenre: \t"  << b.get_genre()
			  << "\nStatus: "   << status << endl;;
}

ostream& operator<<( ostream& os, const ISBN& isbn ) {
	return os << isbn.num1 << isbn.dash1
			  << isbn.num2 << isbn.dash2
			  << isbn.num3 << isbn.dash3
			  << isbn.lit;
}

ostream& operator<<( ostream& os, const Genre& g ) {
	string str_genre;

	switch ( g ) {
		case fantasy: str_genre = "Fanntasy."; break;
		case prose: str_genre = "Prose."; break;
		case periodicals: str_genre = "Periodicals."; break;
		case biography: str_genre = "Biography."; break;
		case childrens: str_genre = "Childrens."; break;
	}

	return os << str_genre;
}

//  operator==()

bool operator==( const Book& b1, const Book& b2 ) {
	ISBN i1 = b1.get_isbn();
	ISBN i2 = b2.get_isbn();

	return i1.num1 == i2.num1 && 
		   i1.num2 == i2.num2 && 
		   i1.num3 == i2.num3 &&
		   i1.lit == i2.lit;
}

//  operator!=()

bool operator!=( const Book& b1, const Book& b2 ) {
	ISBN i1 = b1.get_isbn();
	ISBN i2 = b2.get_isbn();

	return !( i1.num1 == i2.num1 && 
		   	  i1.num2 == i2.num2 && 
		   	  i1.num3 == i2.num3 &&
		   	  i1.lit == i2.lit );
}

//  end of Book.cpp