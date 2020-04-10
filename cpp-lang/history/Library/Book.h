
//  Book.h

#ifndef BOOK_H
#define BOOK_H

//  includes 

#include "std_lib_facilities.h"
#include "Date.h"

//  types

//  ISBN {}

struct ISBN {
	int num1;
	int num2;
	int num3;

	char dash1;
	char dash2;
	char dash3;
	char lit;
};

//  Genre {}

enum Genre { 
	fantasy, prose, periodicals, biography, childrens
};

//  Book {}

class Book {
public:
	Book( string, string,  Date, ISBN, bool, Genre );
	Book();

	//  unmodified func-s
	string get_title    () const { return _title; }
	string get_author   () const { return _author; }
	Date get_date		() const { return _date; }
	ISBN get_isbn		() const { return _isbn; }
	bool get_status     () const { return _availebility; }
	Genre get_genre		() const { return _genre; }

	//  modifying func-s
	void set_title  ();
	void set_author ();
	void set_date   ();
	void set_isbn   ();
	void set_status ();
	void set_genre  ();
	void set        ();

private:
	string _title;
	string _author;
	Date _date;
	ISBN _isbn;
	bool _availebility;
	Genre _genre;
};

//  helper functions

ostream& operator<<( ostream&, const ISBN& );
ostream& operator<<( ostream&, const Book& );
ostream& operator<<( ostream&, const Genre& );

bool operator==( const Book&, const Book& );
bool operator!=( const Book&, const Book& );

#endif  // !defined BOOK_H

//  end of Book.h