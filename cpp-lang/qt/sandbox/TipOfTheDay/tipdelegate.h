#ifndef TIPDELEGATE_H
#define TIPDELEGATE_H

#include <QString>

class TipContainer;

class TipDelegate
{
public:
    TipDelegate  ();
    ~TipDelegate ();

    QString tipText      () const;
    QString tipImagePath () const;
    QString tipImageName () const;
    void    nextTip      ();
    void    previousTip  ();

private:
    int randomNumber() const;

    TipContainer *m_container;
    int           m_index;
};

#endif // TIPDELEGATE_H
