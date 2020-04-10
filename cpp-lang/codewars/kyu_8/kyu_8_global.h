#ifndef KYU_8_GLOBAL_H
#define KYU_8_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KYU_8_LIBRARY)
#  define KYU_8SHARED_EXPORT Q_DECL_EXPORT
#else
#  define KYU_8SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // KYU_8_GLOBAL_H
