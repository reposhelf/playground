#ifndef COMPOSITIONWIDGET_H
#define COMPOSITIONWIDGET_H

#include <QWidget>

class QRadioButton;
class CompositionWidget : public QWidget
{
    Q_OBJECT

public:
    CompositionWidget(QWidget *parent = Q_NULLPTR);

private:
    bool m_cycleEnabled;

    QRadioButton *m_rbClear;
    QRadioButton *m_rbSource;
    QRadioButton *m_rbDest;
    QRadioButton *m_rbSourceOver;
    QRadioButton *m_rbDestOver;
    QRadioButton *m_rbSourceIn;
    QRadioButton *m_rbDestIn;
    QRadioButton *m_rbSourceOut;
    QRadioButton *m_rbDestOut;
    QRadioButton *m_rbSourceAtop;
    QRadioButton *m_rbDestAtop;
    QRadioButton *m_rbXor;

    QRadioButton *m_rbPlus;
    QRadioButton *m_rbMultiply;
    QRadioButton *m_rbScreen;
    QRadioButton *m_rbOverlay;
    QRadioButton *m_rbDarken;
    QRadioButton *m_rbLighten;
    QRadioButton *m_rbColorDodge;
    QRadioButton *m_rbColorBurn;
    QRadioButton *m_rbHardLight;
    QRadioButton *m_rbSoftLight;
    QRadioButton *m_rbDifference;
    QRadioButton *m_rbExclusion;
};

#endif // COMPOSITIONWIDGET_H
