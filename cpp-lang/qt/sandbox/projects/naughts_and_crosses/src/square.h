#ifndef SQUARE_H
#define SQUARE_H

#include "baseitem.h"

class Square : public BaseItem
{
    Q_OBJECT
    Q_PROPERTY(QString imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)
public:
    explicit Square(QObject *parent = nullptr);

    enum SignFlag {SignNone = 0x0, SignX = 0x1, SignO = 0x2, SignMask = 0x3};
    Q_DECLARE_FLAGS(SignFlags, SignFlag)

    QString imageSource() const { return m_imageSource; }
    Square::SignFlags signFlag() const { return m_signFlag; }

    void setImageSource(const QString&);
    void setSignFlag(Square::SignFlags);

signals:
    void imageSourceChanged(const QString&);
    void signFlagChanged(Square::SignFlags);
    void clicked();

private slots:
    void onSigneTypeChanged(Square::SignFlags);

private:
    QString m_imageSource;
    Square::SignFlags m_signFlag;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(Square::SignFlags)

#endif // SQUARE_H
