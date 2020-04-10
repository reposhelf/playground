#ifndef GRADIENTWIDGET_H
#define GRADIENTWIDGET_H

#include <QWidget>

class QRadioButton;
class GradientRenderer;
class GradientEditor;
class GradientWidget : public QWidget
{
    Q_OBJECT

public:
    GradientWidget(QWidget *parent = Q_NULLPTR);

public slots:
    void setDefault1();
    void setDefault2();
    void setDefault3();
    void setDefault4();

private:
    void setDefault(int i);

    GradientRenderer *m_renderer;
    GradientEditor *m_editor;

    QRadioButton *m_linearButton;
    QRadioButton *m_radialButton;
    QRadioButton *m_conicalButton;
    QRadioButton *m_padSpreadButton;
    QRadioButton *m_reflectSpreadButton;
    QRadioButton *m_repeatSpreadButton;
};

#endif // GRADIENTWIDGET_H
