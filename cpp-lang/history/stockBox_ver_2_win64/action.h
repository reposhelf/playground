
//  action.h

#ifndef ACTION_H
#define ACTION_H

//  includes

#include "std_lib_facilities.h"
#include "materials.h"

//  functions

void write                    (const vector<Materials>&, consumables);
vector<Materials> read        (consumables);
void display                  (ostream&, string, const vector<Materials>&);
void display                  (ostream&, string, const vector<Materials>&, const int);
const string currentDateTime  ();
void select_of_count	      ();
void materials_add            (consumables);
void materials_remove	      (consumables);

#endif // !define ACTION_H

//  end of action.h