#ifndef KYU_7_GLOBAL_H
#define KYU_7_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KYU_7_LIBRARY)
#  define KYU_7SHARED_EXPORT Q_DECL_EXPORT
#else
#  define KYU_7SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // KYU_7_GLOBAL_H
