#include "date.h"

#include <vector>
using std::vector;
using std::string;

static const vector<string> MONTHS = {
    "January",    "February",    "March",
    "April",      "May",         "June",
    "July",       "August",      "September",
    "October",    "November",    "December"
};

static const string NUMBERS = "0123456789";

Date::Date(const string &date)
    : m_year(-1),
      m_month(-1),
      m_day(-1)
{
    auto pos = grab_month(date);
    pos = grab_day(date, pos);
    grab_year(date, pos);
}

unsigned Date::grab_month(const string &date)
{
    for (decltype(MONTHS.size()) i = 0; i != MONTHS.size(); ++i) {
        if (date.find(MONTHS[i]) != string::npos 
	    || date.find(MONTHS[i].substr(0, 3)) != string::npos) {
	    m_month = i + 1;
	    return date.find_first_of(NUMBERS);
	}
    }

    auto pos = date.find_first_of(NUMBERS);
    m_month = std::stoul(date.substr(pos));
    pos = date.find_first_not_of(NUMBERS);
    return date.find_first_of(NUMBERS, pos);
}

unsigned Date::grab_day(const string &date, unsigned pos)
{
    m_day = std::stoul(date.substr(pos));
    pos = date.find_first_not_of(NUMBERS, pos);
    return date.find_first_of(NUMBERS, pos);
}

void Date::grab_year(const string &date, unsigned pos)
{
    m_year = std::stoul(date.substr(pos));
}


