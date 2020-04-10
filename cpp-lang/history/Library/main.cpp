
//  main.cpp

//  includes

#include "Book.h"
#include "Patron.h"
#include "Date.h"
#include "Library.h"

//  functions

//  data_book()

void data_book() {
	Book book;
	book.set();
	cout << book << endl;
}

//  data_patron()

void data_patron() {
	Patron patron;
	patron.set();
	cout << patron << endl;
}

void data_lib() {
	Library lib;
	lib.set_book();
	lib.set_patron();
	lib.issuing();
}
//  main()

int main() {

	//data_book();
	//data_patron();
	data_lib();
	return 0;
}

//  end of main.cpp