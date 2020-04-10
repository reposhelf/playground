#ifndef SCANNER_H
#define SCANNER_H

#include <QString>
#include <QByteArray>
#include <QMap>

class Scanner
{
public:
    Scanner(const QString &signatures);
    Scanner(const Scanner&) = delete;
    Scanner &operator=(const Scanner&) = delete;
    QString scanFile(const QString &fileName, bool *infected) const;

private:
    QString scanByteArray(const QByteArray &byteArray, bool *infected) const;
    void readSignatures(const QString &signatures);

    QMap<QByteArray, QString> m_dict;
};

#endif // SCANNER_H
