// Saver.cpp

#include "Saver.h"

#include <new>
#include <QDebug>

void Saver::copyDir( const QDir& src, const QDir& dst )
{
    QFileInfo fiSrc = src.absolutePath();
    if ( fiSrc.isDir() ) {
        if ( !dst.exists() )
            dst.mkdir( dst.absolutePath() );
        foreach( QFileInfo srcSubDir, src.entryInfoList() )
            if ( isValid(srcSubDir, dst) ) {
                copyFiles( src, dst );
                QString subDirName = srcSubDir.fileName();
                copyDir( QDir(srcSubDir.absoluteFilePath()),
                         QDir(dst.absolutePath() + "/" + subDirName) );
            }
    }
}

void Saver::save( const QString& src, const QString& dst )
{
    QFileInfo fi( src );
    if ( fi.isFile() )
        QFile::copy( fi.absoluteFilePath(), dst + fi.fileName() );
    try {
        if ( fi.isDir() )
            copyDir( fi.absoluteFilePath(),dst + fi.baseName() );
    } catch ( const std::bad_alloc& e ) {
        qDebug() << "Allocation failed:" << e.what();
    }
}

void Saver::copyFiles( const QDir& src, const QDir& dst )
{
    QFileInfoList files = src.entryInfoList();
    foreach ( QFileInfo file, files )
        if ( !file.isDir() ) {
            QString fileName = file.fileName();
            if ( !(new QFile(dst.absolutePath() + "/" + fileName))->exists() )
                QFile::copy( file.absoluteFilePath(),
                             dst.absolutePath() + "/" + fileName );
        }
}

bool Saver::isValid( const QFileInfo &fi, const QDir &dst )
{
    return ( fi.fileName() != "." &&
             fi.fileName() != ".." &&
             fi.absoluteFilePath() != dst.absolutePath() );
}
