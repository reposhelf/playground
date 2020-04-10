#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class RenderArea;
class QLabel;
class QComboBox;
class QSpinBox;
class QCheckBox;
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);

private slots:
    void onShapeChanged();
    void onPenChanged();
    void onBrushChanged();

private:
    RenderArea *m_renderArea;
    QLabel *m_shapeLabel;
    QLabel *m_penWidthLabel;
    QLabel *m_penStyleLabel;
    QLabel *m_penCapLabel;
    QLabel *m_penJoinLabel;
    QLabel *m_brushStyleLabel;
    QLabel *m_otherOptionsLabel;
    QComboBox *m_shapeComboBox;
    QSpinBox *m_penWidthSpinBox;
    QComboBox *m_penStyleComboBox;
    QComboBox *m_penCapComboBox;
    QComboBox *m_penJoinComboBox;
    QComboBox *m_brushStyleComboBox;
    QCheckBox *m_antialiasingCheckBox;
    QCheckBox *m_transformationsCheckBox;
};

#endif // WINDOW_H
