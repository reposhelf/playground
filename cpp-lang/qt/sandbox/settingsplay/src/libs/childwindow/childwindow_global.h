#ifndef CHILDWINDOW_GLOBAL_H
#define CHILDWINDOW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CHILDWINDOW_LIBRARY)
#  define CHILDWINDOWSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CHILDWINDOWSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CHILDWINDOW_GLOBAL_H
