#ifndef CLABEL_GLOBAL_H
#define CLABEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CLABEL_LIBRARY)
#  define CLABELSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CLABELSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CLABEL_GLOBAL_H
