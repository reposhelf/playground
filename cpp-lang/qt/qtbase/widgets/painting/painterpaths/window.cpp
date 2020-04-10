#include "window.h"
#include "renderarea.h"

#include <QtWidgets>

const float Pi = 3.14159f;

Window::Window(QWidget *parent)
    : QWidget(parent),
      m_renderAreas(),
      m_fillRuleLabel(Q_NULLPTR),
      m_fillGradientLabel(Q_NULLPTR),
      m_fillToLabel(Q_NULLPTR),
      m_penWidthLabel(Q_NULLPTR),
      m_penColorLabel(Q_NULLPTR),
      m_rotationAngleLabel(Q_NULLPTR),
      m_fillRuleComboBox(Q_NULLPTR),
      m_fillColor1ComboBox(Q_NULLPTR),
      m_fillColor2ComboBox(Q_NULLPTR),
      m_penWidthSpinBox(Q_NULLPTR),
      m_penColorComboBox(Q_NULLPTR),
      m_rotationAngleSpinBox(Q_NULLPTR)
{
    QPainterPath rectPath;
    rectPath.moveTo(20.0, 30.0);
    rectPath.lineTo(80.0, 30.0);
    rectPath.lineTo(80.0, 70.0);
    rectPath.lineTo(20.0, 70.0);
    rectPath.closeSubpath();

    QPainterPath roundRectPath;
    roundRectPath.moveTo(80.0, 35.0);
    roundRectPath.arcTo(70.0, 30.0, 10.0, 10.0, 0.0, 90.0);
    roundRectPath.lineTo(25.0, 30.0);
    roundRectPath.arcTo(20.0, 30.0, 10.0, 10.0, 90.0, 90.0);
    roundRectPath.lineTo(20.0, 65.0);
    roundRectPath.arcTo(20.0, 60.0, 10.0, 10.0, 180.0, 90.0);
    roundRectPath.lineTo(75.0, 70.0);
    roundRectPath.arcTo(70.0, 60.0, 10.0, 10.0, 270.0, 90.0);
    roundRectPath.closeSubpath();

    QPainterPath ellipsePath;
    ellipsePath.moveTo(80.0, 50.0);
    ellipsePath.arcTo(20.0, 30.0, 60.0, 40.0, 0.0, 360.0);

    QPainterPath piePath;
    piePath.moveTo(50.0, 50.0);
    piePath.arcTo(20.0, 30.0, 60.0, 40.0, 60.0, 240.0);
    piePath.closeSubpath();

    QPainterPath polygonPath;
    polygonPath.moveTo(10.0, 80.0);
    polygonPath.lineTo(20.0, 10.0);
    polygonPath.lineTo(80.0, 30.0);
    polygonPath.lineTo(90.0, 70.0);
    polygonPath.closeSubpath();

    QPainterPath groupPath;
    groupPath.moveTo(60.0, 40.0);
    groupPath.arcTo(20.0, 20.0, 40.0, 40.0, 0.0, 360.0);
    groupPath.moveTo(40.0, 40.0);
    groupPath.lineTo(40.0, 80.0);
    groupPath.lineTo(80.0, 80.0);
    groupPath.lineTo(80.0, 40.0);
    groupPath.closeSubpath();

    QPainterPath textPath;
    QFont timesFont("Times", 50);
    timesFont.setStyleStrategy(QFont::ForceOutline);
    textPath.addText(10, 70, timesFont, tr("Qt"));

    QPainterPath bezierPath;
    bezierPath.moveTo(20, 30);
    bezierPath.cubicTo(80, 0, 50, 50, 80, 80);

    QPainterPath starPath;
    starPath.moveTo(90, 50);
    for (int i = 1; i < 5; ++i) {
        starPath.lineTo(50 + 40 * std::cos(0.8 * i * Pi),
                        50 + 40 * std::sin(0.8 * i * Pi));
    }
    starPath.closeSubpath();

    m_renderAreas.push_back(new RenderArea(rectPath));
    m_renderAreas.push_back(new RenderArea(roundRectPath));
    m_renderAreas.push_back(new RenderArea(ellipsePath));
    m_renderAreas.push_back(new RenderArea(piePath));
    m_renderAreas.push_back(new RenderArea(polygonPath));
    m_renderAreas.push_back(new RenderArea(groupPath));
    m_renderAreas.push_back(new RenderArea(textPath));
    m_renderAreas.push_back(new RenderArea(bezierPath));
    m_renderAreas.push_back(new RenderArea(starPath));

    m_fillRuleComboBox = new QComboBox;
    m_fillRuleComboBox->addItem(tr("Odd Even"), Qt::OddEvenFill);
    m_fillRuleComboBox->addItem(tr("Winding"), Qt::WindingFill);

    m_fillRuleLabel = new QLabel(tr("Fill &Rule:"));
    m_fillRuleLabel->setBuddy(m_fillRuleComboBox);

    m_fillColor1ComboBox = new QComboBox;
    populateWithColors(m_fillColor1ComboBox);
    m_fillColor1ComboBox->setCurrentIndex(m_fillColor1ComboBox->findText("mediumslateblue"));

    m_fillColor2ComboBox = new QComboBox;
    populateWithColors(m_fillColor2ComboBox);
    m_fillColor2ComboBox->setCurrentIndex(m_fillColor2ComboBox->findText("cornsilk"));

    m_fillGradientLabel = new QLabel(tr("&Fill Gradient:"));
    m_fillGradientLabel->setBuddy(m_fillColor1ComboBox);

    m_fillToLabel = new QLabel(tr("to"));
    m_fillToLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_penWidthSpinBox = new QSpinBox;
    m_penWidthSpinBox->setRange(0, 20);

    m_penWidthLabel = new QLabel(tr("&Pen Width:"));
    m_penWidthLabel->setBuddy(m_penWidthSpinBox);

    m_penColorComboBox = new QComboBox;
    populateWithColors(m_penColorComboBox);
    m_penColorComboBox->setCurrentIndex(m_penColorComboBox->findText("darkslateblue"));

    m_penColorLabel = new QLabel(tr("Pen &Color:"));
    m_penColorLabel->setBuddy(m_penColorComboBox);

    m_rotationAngleSpinBox = new QSpinBox;
    m_rotationAngleSpinBox->setRange(0, 359);
    m_rotationAngleSpinBox->setWrapping(true);
    m_rotationAngleSpinBox->setSuffix(QLatin1String("\xB0"));

    m_rotationAngleLabel = new QLabel(tr("&Rotation Angle:"));
    m_rotationAngleLabel->setBuddy(m_rotationAngleSpinBox);

    connect(m_fillRuleComboBox, SIGNAL(activated(int)), this, SLOT(fillRuleChanged()));
    connect(m_fillColor1ComboBox, SIGNAL(activated(int)), this, SLOT(fillGradientChanged()));
    connect(m_fillColor2ComboBox, SIGNAL(activated(int)), this, SLOT(fillGradientChanged()));
    connect(m_penColorComboBox, SIGNAL(activated(int)), this, SLOT(penColorChanged()));

    for (QList<RenderArea*>::iterator it = m_renderAreas.begin(); it != m_renderAreas.end(); ++it) {
        connect(m_penWidthSpinBox, SIGNAL(valueChanged(int)), *it, SLOT(setPenWidth(int)));
        connect(m_rotationAngleSpinBox, SIGNAL(valueChanged(int)), *it, SLOT(setRotationAngle(int)));
    }

    QGridLayout *topLayout = new QGridLayout;

    int i = 0;
    for (QList<RenderArea*>::iterator it = m_renderAreas.begin(); it != m_renderAreas.end(); ++it, i++)
        topLayout->addWidget(*it, i / 3, i % 3);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topLayout, 0, 0, 1, 4);
    mainLayout->addWidget(m_fillRuleLabel, 1, 0);
    mainLayout->addWidget(m_fillRuleComboBox, 1, 1, 1, 3);
    mainLayout->addWidget(m_fillGradientLabel, 2, 0);
    mainLayout->addWidget(m_fillColor1ComboBox, 2, 1);
    mainLayout->addWidget(m_fillToLabel, 2, 2);
    mainLayout->addWidget(m_fillColor2ComboBox, 2, 3);
    mainLayout->addWidget(m_penWidthLabel, 3, 0);
    mainLayout->addWidget(m_penWidthSpinBox, 3, 1, 1, 3);
    mainLayout->addWidget(m_penColorLabel, 4, 0);
    mainLayout->addWidget(m_penColorComboBox, 4, 1, 1, 3);
    mainLayout->addWidget(m_rotationAngleLabel, 5, 0);
    mainLayout->addWidget(m_rotationAngleSpinBox, 5, 1, 1, 3);
    setLayout(mainLayout);

    fillRuleChanged();
    fillGradientChanged();
    penColorChanged();
    m_penWidthSpinBox->setValue(2);

    setWindowTitle(tr("Painter Paths"));
}

Window::~Window()
{
}

void Window::fillRuleChanged()
{
    Qt::FillRule rule = static_cast<Qt::FillRule>(currentItemData(m_fillRuleComboBox).toInt());

    for (QList<RenderArea*>::iterator it = m_renderAreas.begin(); it != m_renderAreas.end(); ++it)
        (*it)->setFillRule(rule);
}

void Window::fillGradientChanged()
{
    QColor color1 = qvariant_cast<QColor>(currentItemData(m_fillColor1ComboBox));
    QColor color2 = qvariant_cast<QColor>(currentItemData(m_fillColor2ComboBox));

    for (QList<RenderArea*>::iterator it = m_renderAreas.begin(); it != m_renderAreas.end(); ++it)
        (*it)->setFillGradient(color1, color2);
}

void Window::penColorChanged()
{
    QColor color = qvariant_cast<QColor>(currentItemData(m_penColorComboBox));

    for (QList<RenderArea*>::iterator it = m_renderAreas.begin(); it != m_renderAreas.end(); ++it)
        (*it)->setPenColor(color);
}

void Window::populateWithColors(QComboBox *comboBox)
{
    QStringList names = QColor::colorNames();
    foreach (QString name, names)
        comboBox->addItem(name, QColor(name));
}

QVariant Window::currentItemData(QComboBox *comboBox)
{
    return comboBox->currentData();
}
