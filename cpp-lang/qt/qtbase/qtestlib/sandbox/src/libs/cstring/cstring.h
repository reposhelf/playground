#ifndef CSTRING_H
#define CSTRING_H

#include "cstring_global.h"

#include <QString>

class CSTRINGSHARED_EXPORT CString
{

public:
    CString();
    QString up(const QString &text) const;
};

#endif // CSTRING_H
