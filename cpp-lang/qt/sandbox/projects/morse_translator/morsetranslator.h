#ifndef MORSETRANSLATOR_H
#define MORSETRANSLATOR_H

#include "abstracttranslator.h"

class MorseTranslator : public AbstractTranslator
{
public:
    MorseTranslator(QObject *parent = nullptr);

    QString encode(const QString &text) const override;
    QString decode(const QString &text) const override;
};

#endif // MORSETRANSLATOR_H
