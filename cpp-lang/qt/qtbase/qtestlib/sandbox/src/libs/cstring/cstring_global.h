#ifndef CSTRING_GLOBAL_H
#define CSTRING_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CSTRING_LIBRARY)
#  define CSTRINGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CSTRINGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CSTRING_GLOBAL_H
