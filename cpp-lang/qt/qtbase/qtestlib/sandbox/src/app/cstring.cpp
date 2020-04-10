#include "cstring.h"

CString::CString()
{

}

QString CString::up(const QString &text) const
{
    return text.toUpper();
}
