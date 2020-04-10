#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    explicit Date(const std::string &date);

    unsigned month() const { return m_month; }
    unsigned day() const { return m_day; }
    unsigned year() const { return m_year; }

private:
    unsigned grab_month(const std::string &date);
    unsigned grab_day(const std::string &date, unsigned pos);
    void grab_year(const std::string &date, unsigned pos);

    unsigned m_year;
    unsigned m_month;
    unsigned m_day;
};

#endif
