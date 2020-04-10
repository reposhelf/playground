#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class RenderArea;
class QComboBox;
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

public slots:
    void operationChanged();
    void shapeSelected(int index);

private:
    void setupShapes();

    enum { NumTransmormedAreas = 3 };
    RenderArea *m_originalRenderArea;
    RenderArea *m_transformedRenderAreas[NumTransmormedAreas];
    QComboBox *m_shapeComboBox;
    QComboBox *m_operationComboBoxes[NumTransmormedAreas];
    QList<QPainterPath> m_shapes;
};

#endif // WINDOW_H
