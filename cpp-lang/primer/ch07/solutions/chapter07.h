#ifndef CHAPTER07_H
#define CHAPTER07_H

void handleTransactions();
void solution_7_11();
void solution_7_13();
void handlePersons();

class NoDefault
{
public:
    NoDefault(int num) : _num(num) {}

private:
    int _num;
};

class C
{
public:
    C() : _member(0) {}

private:
    NoDefault _member;
};

void solution_7_44_45();

#endif
