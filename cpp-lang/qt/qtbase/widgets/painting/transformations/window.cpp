#include "window.h"
#include "renderarea.h"

#include <QtWidgets>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    m_originalRenderArea = new RenderArea;

    m_shapeComboBox = new QComboBox;
    m_shapeComboBox->addItem(tr("Clock"));
    m_shapeComboBox->addItem(tr("House"));
    m_shapeComboBox->addItem(tr("Text"));
    m_shapeComboBox->addItem(tr("Truck"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_originalRenderArea, 0, 0);
    layout->addWidget(m_shapeComboBox, 1, 0);

    for (int i = 0; i < NumTransmormedAreas; ++i) {
        m_transformedRenderAreas[i] = new RenderArea;

        m_operationComboBoxes[i] = new QComboBox;
        m_operationComboBoxes[i]->addItem(tr("No Transformation"));
        m_operationComboBoxes[i]->addItem(tr("Rotate by 60\xC2\xB0"));
        m_operationComboBoxes[i]->addItem(tr("Scale to 75%"));
        m_operationComboBoxes[i]->addItem(tr("Translate by (50, 50)"));

        connect(m_operationComboBoxes[i],
                static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
                this, &Window::operationChanged);

        layout->addWidget(m_transformedRenderAreas[i], 0, i + 1);
        layout->addWidget(m_operationComboBoxes[i], 1, i + 1);
    }

    setLayout(layout);
    setupShapes();
    shapeSelected(0);

    setWindowTitle(tr("Transformations"));
}

void Window::operationChanged()
{
    static const Operation operationTable[] = {
        NoTransformation, Rotate, Scale, Translate
    };

    QList<Operation> operations;
    for (int i = 0; i < NumTransmormedAreas; ++i) {
        int index = m_operationComboBoxes[i]->currentIndex();
        operations.append(operationTable[index]);
        m_transformedRenderAreas[i]->setOperations(operations);
    }
}

void Window::shapeSelected(int index)
{
    QPainterPath shape = m_shapes[index];
    m_originalRenderArea->setShape(shape);
    for (int i = 0; i < NumTransmormedAreas; ++i)
        m_transformedRenderAreas[i]->setShape(shape);
}

void Window::setupShapes()
{
    QPainterPath clock;
    clock.addEllipse(-50.0, -50.0, 100.0, 100.0);
    clock.addEllipse(-48.0, -48.0, 96.0, 96.0);
    clock.moveTo(0.0, 0.0);
    clock.lineTo(-2.0, -2.0);
    clock.lineTo(0.0, -42.0);
    clock.lineTo(2.0, -2.0);
    clock.lineTo(0.0, 0.0);
    clock.moveTo(0.0, 0.0);
    clock.lineTo(2.732, -0.732);
    clock.lineTo(24.495, 14.142);
    clock.lineTo(0.732, 2.732);
    clock.lineTo(0.0, 0.0);

    QPainterPath house;
    house.moveTo(-45.0, -20.0);
    house.lineTo(0.0, -45.0);
    house.lineTo(45.0, -20.0);
    house.lineTo(45.0, 45.0);
    house.lineTo(-45.0, 45.0);
    house.lineTo(-45.0, -20.0);
    house.addRect(15.0, 5.0, 20.0, 35.0);
    house.addRect(-35.0, -15.0, 25.0, 25.0);

    QPainterPath text;
    QFont font;
    font.setPixelSize(50);
    QRect fontBoundingRect = QFontMetrics(font).boundingRect(tr("Qt"));
    text.addText(-QPointF(fontBoundingRect.center()), font, tr("Qt"));

    QPainterPath truck;
    truck.setFillRule(Qt::WindingFill);
    truck.moveTo(0.0, 87.0);
    truck.lineTo(0.0, 60.0);
    truck.lineTo(10.0, 60.0);
    truck.lineTo(35.0, 35.0);
    truck.lineTo(100.0, 35.0);
    truck.lineTo(100.0, 87.0);
    truck.lineTo(0.0, 87.0);
    truck.moveTo(17.0, 60.0);
    truck.lineTo(55.0, 60.0);
    truck.lineTo(55.0, 40.0);
    truck.lineTo(37.0, 40.0);
    truck.lineTo(17.0, 60.0);
    truck.addEllipse(17.0, 75.0, 25.0, 25.0);
    truck.addEllipse(63.0, 75.0, 25.0, 25.0);

    m_shapes.append(clock);
    m_shapes.append(house);
    m_shapes.append(text);
    m_shapes.append(truck);

    connect(m_shapeComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            this, &Window::shapeSelected);
}
