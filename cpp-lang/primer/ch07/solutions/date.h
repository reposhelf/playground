#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date(unsigned year, unsigned month, unsigned day, unsigned day_of_week = 0)
	: _year(year),
	_month(month),
	_day(day),
	_day_of_week(day_of_week) {}

private:
    unsigned _year;
    unsigned _month:4;
    unsigned _day:5;
    unsigned _day_of_week:3;
};

#endif
