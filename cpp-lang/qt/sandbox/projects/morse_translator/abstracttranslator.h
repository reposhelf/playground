#ifndef ABSTRACTTRANSLATOR_H
#define ABSTRACTTRANSLATOR_H

#include <QObject>

class AbstractTranslator : public QObject
{
    Q_OBJECT
public:
    explicit AbstractTranslator(QObject *parent = nullptr);

    virtual QString encode(const QString &text) const = 0;
    virtual QString decode(const QString &text) const = 0;
};

#endif // ABSTRACTTRANSLATOR_H
