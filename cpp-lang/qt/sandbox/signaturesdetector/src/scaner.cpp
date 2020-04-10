#include "scaner.h"

#include <QtConcurrent/QtConcurrent>
#include <QDirIterator>

Scaner::Scaner(const QString &path, QObject *parent)
    : QThread(parent),
      m_totalFileCount(0),
      m_scannedFileCount(0),
      m_mutex(),
      m_path(path)
{

}

Scaner::~Scaner()
{

}

void Scaner::setPath(const QString &path)
{
    m_path = path;
}

void Scaner::run()
{
    m_totalFileCount = totalFileCount(m_path);
    m_scannedFileCount = 0;

    scanRecursively(m_path);
}

int Scaner::totalFileCount(const QString &path) const
{
    int result = 0;

    QDirIterator it(path, QDir::Files
                    | QDir::Hidden
                    | QDir::System
                    | QDir::NoDotAndDotDot
                    | QDir::NoSymLinks, QDirIterator::Subdirectories
                    );

    while (it.hasNext()) {
        ++result;
        it.next();
    }

    return result;
}

void Scaner::scanRecursively(const QString &path)
{
    QDirIterator it(path, QDir::AllEntries
                    | QDir::Hidden
                    | QDir::System
                    | QDir::NoDotAndDotDot
                    | QDir::NoSymLinks
                    );

    while (it.hasNext()) {
        it.next();

        const QFileInfo &fileInfo = it.fileInfo();
        const QString &filePath = it.filePath();

        if (fileInfo.isDir() && !fileInfo.isSymLink()) {
            scanRecursively(filePath); // recursive
        } else {
            QFuture<QStringList> future =
                    QtConcurrent::run(this, &Scaner::scanFile, QString(filePath));
            future.waitForFinished();

            if (!future.result().isEmpty()) {
                QStringList guids = future.result();
                for (QString guid : guids) {
                    emit guidDetected(guid);
                }
            }

            updateScanProgress();
            emit scanningFileChanged(filePath);
        }
    }
}

QStringList Scaner::scanFile(const QString &filePath) const
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QStringList();

    uchar *memory = file.map(0, file.size());
    QString text = QString::fromLocal8Bit((char*)memory);
    file.unmap(memory);
    file.close();

    QStringList result;

    QRegExp rx("[a-fA-F0-9]+[.]{1}[\{]{1}[a-fA-f0-9]{8}-([a-fA-F0-9]{4}-){3}[a-fA-F0-9]{12}[}]{1}");
    if (text.contains(rx)) {
        int pos = 0;
        while ((pos = rx.indexIn(text, pos)) != -1) {
            result << rx.cap(0).split('.').last();
            pos += rx.matchedLength();
        }
    }

    return result;
}

void Scaner::updateScanProgress()
{
    QMutexLocker locker(&m_mutex);
    const int progressValue = 100 * (++m_scannedFileCount) / m_totalFileCount;

    emit scanningProgressChanged(progressValue);
}
