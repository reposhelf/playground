
//  action.cpp

//  includes

#include "action.h"
#include "menu.h"
#include <stdio.h>
#include <time.h>
#include "std_lib_facilities.h"

//  functions

//  write()

void write(const vector<Materials>& m, consumables cons) {

   switch(cons) {
      case wiper: {
         ofstream write_file;
         write_file.open(wiper_path, ios_base::trunc);

         if( !write_file )
            cerr << "Невозможно прочитать " << wiper_path << endl;
         else
            for(int i = 0; i < m.size(); ++i)
               write_file << m[i].model << '\t'
                          << m[i].count << endl;

         write_file.close();
      }
     break;
     
      case blade: {
         ofstream write_file;
         write_file.open(blade_path, ios_base::trunc);

         if( !write_file )
            cerr << "Невозможно прочитать " << blade_path << endl;
         else
            for(int i = 0; i < m.size(); ++i)
               write_file << m[i].model << '\t'
                          << m[i].count << endl;

         write_file.close();
      }
     break;
     
      case c_roller: {
         ofstream write_file;
         write_file.open(c_roller_path, ios_base::trunc);

         if( !write_file )
            cerr << "Невозможно прочитать " << c_roller_path << endl;
         else
            for(int i = 0; i < m.size(); ++i)
               write_file << m[i].model << '\t'
                          << m[i].count << endl;

         write_file.close();
      }
     break;
     
      case d_roller: {
         ofstream write_file;
         write_file.open(d_roller_path, ios_base::trunc);

         if( !write_file )
            cerr << "Невозможно прочитать " << d_roller_path << endl;
         else
            for(int i = 0; i < m.size(); ++i)
               write_file << m[i].model << '\t'
                          << m[i].count << endl;

         write_file.close();
      }
     break;
     
      case s_roller: {
         ofstream write_file;
         write_file.open(s_roller_path, ios_base::trunc);

         if( !write_file )
            cerr << "Невозможно прочитать " << s_roller_path << endl;
         else
            for(int i = 0; i < m.size(); ++i)
               write_file << m[i].model << '\t'
                          << m[i].count << endl;

         write_file.close();
      }
     break;
   }
}

//  read()

vector<Materials> read(consumables cons) {

   switch (cons) {
      case wiper: {
         vector<Materials> wipers;

         ifstream read_file(wiper_path);

         if (!read_file)
            cerr << "Нет данных!\n";
         else {
            string model;
            int count;

            while (read_file >> model) {
               read_file >> count;
               wipers.push_back(Materials(model, count));
            }
         }
         return wipers;
      }  
      break;

      case blade: {
         vector<Materials> blades;

         ifstream read_file(blade_path);

         if (!read_file)
            cerr << "Нет данных!\n";
         else {
            string model;
            int count;

            while (read_file >> model) {
               read_file >> count;
               blades.push_back(Materials(model, count));
            }
         }
         return blades;
      }
      break;
     
      case c_roller: {
         vector<Materials> c_rollers;

         ifstream read_file(c_roller_path);

         if (!read_file)
            cerr << "Нет данных!\n";
         else {
            string model;
            int count;

            while (read_file >> model) {
               read_file >> count;
               c_rollers.push_back(Materials(model, count));
            }
         }
         return c_rollers;
      }
      break;
     
      case d_roller: {
         vector<Materials> d_rollers;

         ifstream read_file(d_roller_path);

         if (!read_file)
            cerr << "Нет данных!\n";
         else {
            string model;
            int count;

            while (read_file >> model) {
               read_file >> count;
               d_rollers.push_back(Materials(model, count));
            }
         }
         return d_rollers;
      }
      break;
     
      case s_roller: {
         vector<Materials> s_rollers;

         ifstream read_file(s_roller_path);

         if (!read_file)
            cerr << "Нет данных!\n";
         else {
            string model;
            int count;

            while (read_file >> model) {
               read_file >> count;
               s_rollers.push_back(Materials(model, count));
            }
         }
         return s_rollers;
      }
      break;
   }
}

//  display()

void display(ostream& os, string title, const vector<Materials>& m) {

   os << title << endl;

   for (int i = 0; i < m.size(); ++i) 
      os << m[i].model << '\t' 
         << m[i].count << endl; 
		 
   os << endl;
}

//  display() -- for select of count

void display(ostream& os, string title, const vector<Materials>& m, const int user_count) {

   os << title << endl;
   
   int counter = 0;
   
   for (int i = 0; i < m.size(); ++i) {
      if (m[i].count <= user_count) {
	     os << m[i].model << '\t'
		    << m[i].count << endl;
		 ++counter;
	  }
   }
   
   if (!counter)
      os << "--Full--\n";
   
   os << endl;
}

//  currentDateTime()

const string currentDateTime() {

   time_t now = time(0);
   struct tm tstruct;
   char buf[80];
   tstruct = *localtime(&now);
   strftime(buf, sizeof(buf), "%d/%m/%Y -- %X", &tstruct);
   
   return buf;
}

//  order()

void order(const vector<Materials>& w, const vector<Materials>& b, const vector<Materials>& cr,
          const vector<Materials>& dr, const vector<Materials>& sr, int count) {

   ofstream write_file("res\\order.txt", ios_base::trunc);
   
   if (!write_file)
      cerr << "Невозможно прочитать order.txt\n";
   else {
      write_file << "\t\t\tЗАКАЗ\t" << currentDateTime() << "\n\n";
     
      int counter = 0;
      write_file << wiper_title << endl;
     for (int i = 0; i < w.size(); ++i) 
        if (w[i].count <= count) {
          write_file << w[i].model << '\t'
                    << w[i].count << endl;
         ++counter;
       }
      if (counter == 0) 
        write_file << "--Full--\n";
      write_file << endl;
       
      counter = 0;
      write_file << blade_title << endl;
     for (int i = 0; i < b.size(); ++i) 
        if (b[i].count <= count) {
          write_file << b[i].model << '\t'
                    << b[i].count << endl;
         ++counter;
       }
      if (counter == 0) 
        write_file << "--Full--\n";
      write_file << endl;

      counter = 0;
      write_file << c_roller_title << endl;
     for (int i = 0; i < cr.size(); ++i) 
        if (cr[i].count <= count) {
          write_file << cr[i].model << '\t'
                    << cr[i].count << endl;
         ++counter;
       }
      if (counter == 0) 
        write_file << "--Full--\n";
      write_file << endl;

      counter = 0;
      write_file << d_roller_title << endl;
     for (int i = 0; i < dr.size(); ++i) 
        if (dr[i].count <= count) {
          write_file << dr[i].model << '\t'
                    << dr[i].count << endl;
         ++counter;
       }
      if (counter == 0) 
        write_file << "--Full--\n";
      write_file << endl;

      counter = 0;
      write_file << s_roller_title << endl;
     for (int i = 0; i < sr.size(); ++i) 
        if (sr[i].count <= count) {
          write_file << sr[i].model << '\t'
                    << sr[i].count << endl;
         ++counter;
       }
      if (counter == 0) 
        write_file << "--Full--\n";
      write_file << endl;
   }
   write_file.close();
}

//  select_of_count()

void select_of_count() {

   vector<Materials> wipers;
   vector<Materials> blades;
   vector<Materials> c_rollers;
   vector<Materials> d_rollers;
   vector<Materials> s_rollers;
   
   wipers = read(wiper);
   blades = read(blade);
   c_rollers = read(c_roller);
   d_rollers = read(d_roller);
   s_rollers = read(s_roller);


   cout << "Введите интересуемое количество материалов::\n"
        << ">>> ";
   int user_count;
   cin >> user_count;

   cout << '\n';
   
   display(cout, wiper_title, wipers, user_count);
   display(cout, blade_title, blades, user_count);
   display(cout, c_roller_title, c_rollers, user_count);
   display(cout, d_roller_title, d_rollers, user_count);
   display(cout, s_roller_title, s_rollers, user_count);
   
   order(wipers, blades, c_rollers, d_rollers, s_rollers, user_count);
}

//  materials_add()

void materials_add(consumables cons) {

   switch(cons) {
      case wiper: {
         vector<Materials> wipers;
         wipers = read(wiper);
   
		 string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;
	  
	        int counter = 0;
	  
	        for (int i = 0; i < wipers.size(); ++i) 
	           if (wipers[i].model == model) {
		          wipers[i].add(model, count);	
			      ++counter;
		    }
	  
	        if (counter == 0) 
	           wipers.push_back(Materials(model, count));
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(wipers, wiper);
      }
	  break;
	  
      case blade: {
         vector<Materials> blades;
         blades = read(blade);
   
		 string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;
	  
	        int counter = 0;
	  
	        for (int i = 0; i < blades.size(); ++i) 
	           if (blades[i].model == model) {
		          blades[i].add(model, count);	
			      ++counter;
		    }
	  
	        if (counter == 0) 
	           blades.push_back(Materials(model, count));
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(blades, blade);
      }
	  break;
	  
      case c_roller: {
         vector<Materials> c_rollers;
         c_rollers = read(c_roller);
   
		 string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;
	  
	        int counter = 0;
	  
	        for (int i = 0; i < c_rollers.size(); ++i) 
	           if (c_rollers[i].model == model) {
		          c_rollers[i].add(model, count);	
			      ++counter;
		    }
	  
	        if (counter == 0) 
	           c_rollers.push_back(Materials(model, count));
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(c_rollers, c_roller);
      }
	  break;
	  
      case d_roller: {
         vector<Materials> d_rollers;
         d_rollers = read(d_roller);
   
		 string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;
	  
	        int counter = 0;
	  
	        for (int i = 0; i < d_rollers.size(); ++i) 
	           if (d_rollers[i].model == model) {
		          d_rollers[i].add(model, count);	
			      ++counter;
		    }
	  
	        if (counter == 0) 
	           d_rollers.push_back(Materials(model, count));
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(d_rollers, d_roller);
      }
	  break;
	  
      case s_roller: {
         vector<Materials> s_rollers;
         s_rollers = read(s_roller);
   
		 string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;
	  
	        int counter = 0;
	  
	        for (int i = 0; i < s_rollers.size(); ++i) 
	           if (s_rollers[i].model == model) {
		          s_rollers[i].add(model, count);	
			      ++counter;
		    }
	  
	        if (counter == 0) 
	           s_rollers.push_back(Materials(model, count));
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(s_rollers, s_roller);
      }
	  break;
   }
}

//  materials_remove()

void materials_remove(consumables cons) {

   switch(cons) {
      case wiper: {
         vector<Materials> wipers;
         wipers = read(wiper);
   
         string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;

	        int counter = 0;
	  
	        for (int i = 0; i < wipers.size(); ++i) 
	           if (wipers[i].model == model) {
		          wipers[i].remove(model, count);
			      ++counter;
		       } 
	  
	        if (counter == 0)
	           cerr << "Такой записи не существует!\n";
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(wipers, wiper);
      }
	  break;

      case blade: {
         vector<Materials> blades;
         blades = read(blade);
   
         string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;

	        int counter = 0;
	  
	        for (int i = 0; i < blades.size(); ++i) 
	           if (blades[i].model == model) {
		          blades[i].remove(model, count);
			      ++counter;
		       } 
	  
	        if (counter == 0)
	           cerr << "Такой записи не существует!\n";
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(blades, blade);
      }
	  break;
	  
      case c_roller: {
         vector<Materials> c_rollers;
         c_rollers = read(c_roller);
   
         string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;

	        int counter = 0;
	  
	        for (int i = 0; i < c_rollers.size(); ++i) 
	           if (c_rollers[i].model == model) {
		          c_rollers[i].remove(model, count);
			      ++counter;
		       } 
	  
	        if (counter == 0)
	           cerr << "Такой записи не существует!\n";
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(c_rollers, c_roller);
      }
	  break;
	  
      case d_roller: {
         vector<Materials> d_rollers;
         d_rollers = read(d_roller);
   
         string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;

	        int counter = 0;
	  
	        for (int i = 0; i < d_rollers.size(); ++i) 
	           if (d_rollers[i].model == model) {
		          d_rollers[i].remove(model, count);
			      ++counter;
		       } 
	  
	        if (counter == 0)
	           cerr << "Такой записи не существует!\n";
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(d_rollers, d_roller);
      }
	  break;
	  
      case s_roller: {
         vector<Materials> s_rollers;
         s_rollers = read(s_roller);
   
         string model;
         int count;
         char c;
   
         do {
            cout << ">>> ";
	        cin >> model >> count;

	        int counter = 0;
	  
	        for (int i = 0; i < s_rollers.size(); ++i) 
	           if (s_rollers[i].model == model) {
		          s_rollers[i].remove(model, count);
			      ++counter;
		       } 
	  
	        if (counter == 0)
	           cerr << "Такой записи не существует!\n";
	  
	        cout << "Продолжить? (y/n)";
	        cin >> c ;
         } while (c == 'y');
   
         write(s_rollers, s_roller);
      }
	  break;
   }
}

//  end of action.cpp

