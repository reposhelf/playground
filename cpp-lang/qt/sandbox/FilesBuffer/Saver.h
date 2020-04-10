#ifndef SAVER_H
#define SAVER_H

#include <QObject>
#include <QString>
#include <QDir>

class Saver {
public:
    Saver() {}
    void save( const QString& src, const QString& dst );

private:
    void copyDir  ( const QDir& src, const QDir& dst );
    void copyFiles( const QDir& src, const QDir& dst );
    bool isValid  ( const QFileInfo& fi, const QDir& dst );
};

#endif // SAVER_H
