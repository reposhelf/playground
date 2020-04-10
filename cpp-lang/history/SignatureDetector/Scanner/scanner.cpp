#include "scanner.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

Scanner::Scanner(const QString &signatures)
{
    readSignatures(signatures);
}

QString Scanner::scanFile(const QString &fileName, bool *infected) const
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannon open file " + file.fileName();
        return QString();
    }

    // TODO: use file mapping to increase scanning perfomance
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (!line.isEmpty()) {
            QByteArray ba = QByteArray::fromHex(line.toLatin1());
            QString guid = scanByteArray(ba, infected);
            if (infected) {
                return QFileInfo(file).filePath() + ";" + guid;
            }
        }
    }
    return QString();
}

QString Scanner::scanByteArray(const QByteArray &byteArray, bool *infected) const
{
    QMap<QByteArray, QString>::const_iterator i = m_dict.constBegin();
    while (i != m_dict.constEnd()) {
        if (byteArray.contains(i.key())) {
            *infected = true;
            return i.value();
        }
    }
    return QString();
}

void Scanner::readSignatures(const QString &signatures)
{
    QFile file(signatures);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file with signatures.";
        return;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (!line.isEmpty()) {
            QStringList sl = line.split('.');
            m_dict.insert(QByteArray::fromHex(sl.at(0).toLatin1()), sl.at(1));
        }
    }
}
