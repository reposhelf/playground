#ifndef TIP_H
#define TIP_H

#include <QString>

class Tip
{
public:
    Tip ();
    Tip (QString textFilePath, QString imageFilePath = "None");

    QString textFilePath  () const;
    QString imageFilePath () const;

private:
    QString m_textFilePath;
    QString m_imageFilePath;
};

#endif // TIP_H
