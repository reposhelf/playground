
//  RomanCalc.cpp

//  includes

#include "std_lib_facilities.h"
#include "RomanInt.h"

//  types

class Token {
public:
	char kind;
	int value;
	string name;
	Token(char ch)
			:kind(ch), value(0)   { }
	Token(char ch, int val)
			:kind(ch), value(val) { }
	Token(char ch, string n)
			:kind(ch), name(n)    { }
};

class TokenStream {
public:
	TokenStream();
	Token get();
	void putback(Token t);
	void ignore(char c);
	
private:
	bool full;
	Token buffer;
};

//  constants

const char number   = '8';
const char quit     = 'q';
const char print    = '=';
const string prompt = ">>>";
const string result = "= ";

//  member functions

//  TokenStream()

TokenStream::TokenStream()
		:full(false), buffer(0) { }
		
//  putback()

void TokenStream::putback(Token t) {

	if (full) error("putback(): полный буфер");
	buffer = t;
	full = true;
}

//  get()

Token TokenStream::get() {

	if (full) {
		full = false;
		return buffer;
	}
	
	char ch;
	cin >> ch;
	
	switch( ch) {
	case print:
	case quit:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return Token(ch);
	case 'I': case 'V': case 'X': case 'L':
	case 'C': case 'D': case 'M':
    {
		cin.putback(ch);
		RomanInt r;
		cin >> r;
		int val = r.asInt();
		return Token(number, val);
    }
	default:
		error("Неверная лексема");
	}
}

//  ignore()

void TokenStream::ignore(char c) {

	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

//  variable

TokenStream ts;

//  functions

//  keepWindowOpen()

bool keepWindowOpen(char ch) {

	cout << "Чтобы закрыть окно введите символ ~\n";
	char c;
	while (cin >> c)
		if (c == ch) return true;
	return false;
}

//  cleanUpMess()

void cleanUpMess() {
	ts.ignore(print);
}

//  expression()

int expression();

//  primary()

int primary() {
	
	Token t = ts.get();
	switch (t.kind) {
	case '(':
		{
			int i = expression();
			t = ts.get();
			if (t.kind != ')') error("')' отсутствует");
			return i;
		}
	case number:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("ожидается первичное выражение");
	}
}

//  term()

int term() {

	int left = primary();
	Token t = ts.get();
	
	while (true) {
		switch (t.kind) {
			case '*':
				left *= term();
				t = ts.get();
				break;
			case '/':
				{
					int i = term();
					if (i == 0) error("деление на нуль");
					left /= i;
					t = ts.get();
					break;
				}
			case '%':
				{
					int i = term();
					int i1 = int(left);
					if (i1 != left)
						error("левый операнд % не целое число");
					int i2 = int(i);
					if (i2 != i)
						error("правый операнд % не целое число");
					if (i1 < i2) i1 = i2;
					left = i1 % i2;
					t = ts.get();
					break;
				}
			default:
				ts.putback(t);
				return left;
		}
	}
}

//  expression()

int expression() {

	int left = term();
	Token t = ts.get();
	
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//  romanResult()

RomanInt romanResult() {
	int i = expression();
	RomanInt r = intToRoman( i );
	return r;
}

//  calcualte()

void calculate() {

	while (cin) {
		try {
			cout << prompt;
			
			Token t = ts.get();
			
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << romanResult() << endl;
		}
		catch (exception& e) {
			cerr << e.what() << endl;
			cleanUpMess();
		}
	}
}

//  main()

int main() {

	setlocale(LC_ALL, "Rus");
	try {
		calculate();
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "ошибка: " << e.what() << '\n';
		keepWindowOpen('~');
		return 1;
	}
	catch (...) {
		cerr << "ой! неизвестное выражение\n";
		keepWindowOpen('~');
		return 2;
	}
}
