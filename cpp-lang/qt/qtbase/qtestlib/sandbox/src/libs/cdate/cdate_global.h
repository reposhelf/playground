#ifndef CDATE_GLOBAL_H
#define CDATE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CDATE_LIBRARY)
#  define CDATESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CDATESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CDATE_GLOBAL_H
