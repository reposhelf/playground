#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QComboBox;
class QLabel;
class QSpinBox;
class RenderArea;
class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = Q_NULLPTR);
    ~Window();

private slots:
    void fillRuleChanged();
    void fillGradientChanged();
    void penColorChanged();

private:
    void populateWithColors(QComboBox *comboBox);
    QVariant currentItemData(QComboBox *comboBox);

    QList<RenderArea*> m_renderAreas;
    QLabel *m_fillRuleLabel;
    QLabel *m_fillGradientLabel;
    QLabel *m_fillToLabel;
    QLabel *m_penWidthLabel;
    QLabel *m_penColorLabel;
    QLabel *m_rotationAngleLabel;
    QComboBox *m_fillRuleComboBox;
    QComboBox *m_fillColor1ComboBox;
    QComboBox *m_fillColor2ComboBox;
    QSpinBox *m_penWidthSpinBox;
    QComboBox *m_penColorComboBox;
    QSpinBox *m_rotationAngleSpinBox;
};

#endif // WINDOW_H
