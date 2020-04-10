
//  choice.cpp

//  includes

#include "choice.h"

//  functions

//  main_menu_choice()

void main_menu_choice() {

   int choice;
   cin >> choice;

   switch (choice) {
   case 1:
      system("cls");  //  очищает окно консоли
      view_menu();
      break;
   case 2:
      system("cls");
      edit_menu();
      break;
   case 3:
      exit(1);
      break;
   default:
      _flushall();    //  очищает поток от символов
      cin.clear();
      system("cls");  
      main_menu();
   }
}

//  view_menu_choice()

void view_menu_choice() {

   int choice;
   cin >> choice;

   switch (choice) {
   case 1:
      system("cls");
      general_list_menu();
      break;
   case 2:
      system("cls");
      select_of_count();
      select_of_count_menu();
      break;
   case 3:
      system("cls");
      main_menu();
      break;
   case 4:
      exit(1);
      break;
   default:
      _flushall();
      cin.clear();
      system("cls");
      view_menu();
   }
}

//  general_list_menu_choice()

void general_list_menu_choice() {

   int choice;
   cin >> choice;

   switch (choice) {
   case 1:
      system("cls");
      view_menu();
      break;
   case 2:
      system("cls");
      main_menu();
   case 3:
      exit(1);
      break;
   default:
      _flushall();
      cin.clear();
      system("cls");
      general_list_menu();
   }
}

//  select_of_count_menu_choice()

void select_of_count_menu_choice() {

   int choice;
   cin >> choice;

   switch (choice) {
   case 1:
      system("cls");
      view_menu();
      break;
   case 2:
      system("cls");
      main_menu();
   case 3:
      exit(1);
      break;
   default:
      _flushall();
      cin.clear();
      system("cls");
      select_of_count_menu();
   }
}

//  edit_menu_choice()

void edit_menu_choice() {

   int choice;
   cin >> choice;

   switch (choice) {
   case 1:
      system("cls");
      add_menu();
      break;
   case 2:
      system("cls");
      remove_menu();
      break;
   case 3:
      system("cls");
      main_menu();
      break;
   case 4:
      exit(1);
      break;
   default:
      _flushall();
      cin.clear();
      system("cls");
      edit_menu();
   }
}

//  add_menu_choice()

void add_menu_choice() {

   int choice;
   cin >> choice;

   switch (choice) {
   case 1:
      system("cls");
      materials_add(wiper);
      system("cls"); 
      add_menu();
      break;
   case 2:
      system("cls");
      materials_add(blade);
      system("cls"); 
      add_menu();
      break;
   case 3:
      system("cls");
      materials_add(c_roller);
      system("cls"); 
      add_menu();
      break;
   case 4:
      system("cls");
      materials_add(d_roller);
      system("cls"); 
      add_menu();
      break;
   case 5:
      system("cls");
      materials_add(s_roller);
      system("cls"); 
      add_menu();
      break;
   case 6:
      system("cls");
      edit_menu();
      break;
   case 7:
      system("cls");
      main_menu();
      break;
   case 8:
      exit(1);
      break;
   default:
      _flushall();
      cin.clear();
      system("cls");
      add_menu();
   }
}

//  remove_menu_choice()

void remove_menu_choice() {

   int choice;
   cin >> choice;

   switch (choice) {
   case 1:
      system("cls");
	  materials_remove(wiper);
	  system("cls");
	  remove_menu();
      break;
   case 2:
      system("cls");
	  materials_remove(blade);
	  system("cls");
	  remove_menu();
      break;
   case 3:
      system("cls");
	  materials_remove(c_roller);
	  system("cls");
	  remove_menu();
      break;
   case 4:
      system("cls");
	  materials_remove(d_roller);
	  system("cls");
	  remove_menu();
      break;
   case 5:
      system("cls");
	  materials_remove(s_roller);
	  system("cls");
	  remove_menu();
      break;
   case 6:
      system("cls");
      edit_menu();
      break;
   case 7:
      system("cls");
      main_menu();
      break;
   case 8:
      exit(1);
      break;
   default:
      _flushall();
      cin.clear();
      system("cls");
      remove_menu();
   }
}

//  end of choice.cpp