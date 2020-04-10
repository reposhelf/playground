
//  materials.h

#ifndef MATERIALS_H
#define MATERIALS_H

//  includes

#include "std_lib_facilities.h"

//  enums

enum consumables {wiper, blade, c_roller, d_roller, s_roller};

//  "constants"

const string wiper_path = "res\\wiper.txt";
const string blade_path = "res\\blade.txt";
const string c_roller_path = "res\\c_roller.txt";
const string d_roller_path = "res\\d_roller.txt";
const string s_roller_path = "res\\s_roller.txt";

const string wiper_title = "Лезвия чистящие:";
const string blade_title = "Лезвия дозирующие:";
const string c_roller_title = "Валы первичного заряда:";
const string d_roller_title = "Валы магнитные:";
const string s_roller_title = "Оболочки магнитных валов:";

//  type

class Materials {
protected:
   string _model;
   int _count;
public:
   string model;
   int count;

   Materials() {}
   Materials(string m) 
      : _model(m), _count(0) 
   { model = _model; count = _count; }
   Materials(string m, int c)
      : _model(m), _count(c) 
   { model = _model; count = _count; }
	  
   void show   () const;
   void add    (string, int);
   void remove (string, int);
   void write  () const;
};

#endif // !defined MATERIALS_H

//  end of materials.h