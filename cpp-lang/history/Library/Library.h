
//  Library.h

#ifndef LIBRARY_H
#define LIBRARY_H

//  includes

#include "std_lib_facilities.h"
#include "Book.h"
#include "Patron.h"
#include "Date.h"

//  types

//  Transaction

struct Transaction {
	Book book;
	Patron patron;
	Date date;
};

//  Library

class Library {
public:
	Library();

	//  modifying func-s
	void set_book   ();
	void set_patron ();
	void issuing    ();

	//  unmodified func-s
	bool check( Transaction& ) const;
	vector<Name> debtors() const;

private:
	vector<Book>   		_book;
	vector<Patron> 		_patron;
	vector<Transaction> _trans;
};

#endif  // !defined LIBRARY_H

//  end of Library.h