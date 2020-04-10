#ifndef CDATE_H
#define CDATE_H

#include "cdate_global.h"

class QDate;

class CDATESHARED_EXPORT CDate
{

public:
    CDate();
    bool isValid(const QDate &date) const;
};

#endif // CDATE_H
