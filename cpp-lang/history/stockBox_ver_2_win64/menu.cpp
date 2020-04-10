
//  menu.cpp

//  includes

#include "std_lib_facilities.h"
#include "action.h"
#include "menu.h"
#include "choice.h"

//  functions

//  main_menu()

void main_menu() {

   cout << "\n\t\t\tСКЛАДСКОЙ УЧЕТ: СЕРВИС ЦЕНТР \"ВСТ\"\n\n";

   cout << "Главное меню:\n\n"
        << "1. Просмотр.\n"
        << "2. Редактировать.\n"
        << "3. Выход.\n\n";

   cout << ">>> ";

   main_menu_choice();
}

//  view_menu()

void view_menu() {

   cout << "\nПросмотр:\n\n"
        << "1. Общий список.\n"
        << "2. Выборка по количеству расходных материалов.\n"
        << "3. Назад.\n"
        << "4. Выход.\n\n";

   cout << ">>> ";

   view_menu_choice();
}       

//  general_list_menu()

void general_list_menu() {

   vector<Materials> wipers;
   vector<Materials> blades;
   vector<Materials> c_rollers;
   vector<Materials> d_rollers;
   vector<Materials> s_rollers;
   
   wipers = read(wiper);
   display(cout, wiper_title, wipers);
   
   blades = read(blade);
   display(cout, blade_title, blades);
   
   c_rollers = read(c_roller);
   display(cout, c_roller_title, c_rollers);

   d_rollers = read(d_roller);
   display(cout, d_roller_title, d_rollers);
   
   s_rollers = read(s_roller);
   display(cout, s_roller_title, s_rollers);

   cout << "\n1. Назад.\n"
        << "2. Главное меню.\n"
        << "3. Выход.\n\n";

   cout << ">>> ";

   general_list_menu_choice();
}

//  select_of_count_menu()

void select_of_count_menu() {

   cout << "\n1. Назад.\n"
        << "2. Главное меню.\n"
        << "3. Выход.\n\n";

   cout << ">>> ";

   select_of_count_menu_choice();
}

//  edit_menu()

void edit_menu() {

   cout << "\nРедактировать:\n\n"
        << "1. Добавить.\n"
        << "2. Отнять.\n"
        << "3. Назад.\n"
        << "4. Выход.\n\n";

   cout << ">>> ";

   edit_menu_choice();
}

//  add_menu()

void add_menu() {

   cout << "\nДобавить:\n\n"
        << "1. Лезвия чистящие.\n"
        << "2. Лезвия дозирующие.\n"
        << "3. Валы первичного заряда.\n"
        << "4. Валы магнитные.\n"
        << "5. Оболочки магнитных валов.\n"
        << "6. Назад.\n"
        << "7. Главное меню.\n"
        << "8. Выход.\n\n";

   cout << ">>> ";

   add_menu_choice();
}

//  remove_menu()

void remove_menu() {

   cout << "\nОтнять:\n\n"
        << "1. Лезвия чистящие.\n"
        << "2. Лезвия дозирующие.\n"
        << "3. Валы первичного заряда.\n"
        << "4. Валы магнитные.\n"
        << "5. Оболочки магнитных валов.\n"
        << "6. Назад.\n"
        << "7. Главное меню.\n"
        << "8. Выход.\n\n";

   cout << ">>> ";

   remove_menu_choice();
}

//  end of menu.cpp