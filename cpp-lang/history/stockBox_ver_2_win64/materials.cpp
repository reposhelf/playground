
//  materials.cpp

//  includes

#include "materials.h"

//  functions

//  show()

void Materials::show() const {

   cout << _model << '\t'
        << _count << endl;
}

//  add()

void Materials::add(string m, int c) {
   
   if (m == _model)
      {_count += c; count = _count;}
   else
      cerr << "Обращение к несуществующему обьекту\n";
}

//  remove()

void Materials::remove(string m, int c) {

   if (m == _model)
      if (c <= _count)
         {_count -= c; count = _count;}
      else
         cerr << "Ой! Нельзя взять больше чем есть на складе.\n";   
   else
      cerr << "Обращение к несуществующему обьекту\n";   
}

//  write()

void Materials::write() const {

   ofstream outfile;
   outfile.open("D:\\Vova\\test.txt", ios_base::trunc);

   if (!outfile)
      cerr << "Невозможно открыть файл test.txt!\n";
   else 
      outfile << _model << '\t' 
            << _count << '\n';

   outfile.close();
}

//  end of materials.cpp