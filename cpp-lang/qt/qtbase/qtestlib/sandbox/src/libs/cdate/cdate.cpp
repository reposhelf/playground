#include "cdate.h"

#include <QDate>

CDate::CDate()
{
}

bool CDate::isValid(const QDate &date) const
{
    return date.isValid();
}
