#include "window.h"
#include "renderarea.h"

#include <QtWidgets>

const int IdRole = Qt::UserRole;

Window::Window(QWidget *parent)
    : QWidget(parent),
      m_renderArea(Q_NULLPTR),
      m_shapeLabel(Q_NULLPTR),
      m_penWidthLabel(Q_NULLPTR),
      m_penStyleLabel(Q_NULLPTR),
      m_penCapLabel(Q_NULLPTR),
      m_penJoinLabel(Q_NULLPTR),
      m_brushStyleLabel(Q_NULLPTR),
      m_otherOptionsLabel(Q_NULLPTR),
      m_shapeComboBox(Q_NULLPTR),
      m_penWidthSpinBox(Q_NULLPTR),
      m_penStyleComboBox(Q_NULLPTR),
      m_penCapComboBox(Q_NULLPTR),
      m_penJoinComboBox(Q_NULLPTR),
      m_brushStyleComboBox(Q_NULLPTR),
      m_antialiasingCheckBox(Q_NULLPTR),
      m_transformationsCheckBox(Q_NULLPTR)
{
    m_renderArea = new RenderArea;

    m_shapeComboBox = new QComboBox;
    m_shapeComboBox->addItem(tr("Polygon"), RenderArea::Polygon);
    m_shapeComboBox->addItem(tr("Rectangle"), RenderArea::Rect);
    m_shapeComboBox->addItem(tr("Rounded Rectangle"), RenderArea::RoundedRect);
    m_shapeComboBox->addItem(tr("Ellipse"), RenderArea::Ellipse);
    m_shapeComboBox->addItem(tr("Pie"), RenderArea::Pie);
    m_shapeComboBox->addItem(tr("Chord"), RenderArea::Chord);
    m_shapeComboBox->addItem(tr("Path"), RenderArea::Path);
    m_shapeComboBox->addItem(tr("Line"), RenderArea::Line);
    m_shapeComboBox->addItem(tr("Polyline"), RenderArea::PolyLine);
    m_shapeComboBox->addItem(tr("Arc"), RenderArea::Arc);
    m_shapeComboBox->addItem(tr("Points"), RenderArea::Points);
    m_shapeComboBox->addItem(tr("Text"), RenderArea::Text);
    m_shapeComboBox->addItem(tr("Pixmap"), RenderArea::Pixmap);

    m_shapeLabel = new QLabel(tr("&Shape"));
    m_shapeLabel->setBuddy(m_shapeComboBox);

    m_penWidthSpinBox = new QSpinBox;
    m_penWidthSpinBox->setRange(0, 20);
    m_penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    m_penWidthLabel = new QLabel(tr("Pen &Width"));
    m_penWidthLabel->setBuddy(m_penWidthSpinBox);

    m_penStyleComboBox = new QComboBox;
    m_penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    m_penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    m_penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    m_penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    m_penStyleComboBox->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
    m_penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    m_penStyleLabel = new QLabel(tr("&Pen Style"));
    m_penStyleLabel->setBuddy(m_penStyleComboBox);

    m_penCapComboBox = new QComboBox;
    m_penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    m_penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    m_penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

    m_penCapLabel = new QLabel(tr("Pen &Cap"));
    m_penCapLabel->setBuddy(m_penCapComboBox);

    m_penJoinComboBox = new QComboBox;
    m_penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    m_penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    m_penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

    m_penJoinLabel = new QLabel(tr("Pen &Join"));
    m_penJoinLabel->setBuddy(m_penJoinComboBox);

    m_brushStyleComboBox = new QComboBox;
    m_brushStyleComboBox->addItem(tr("Linear Gradient"), static_cast<int>(Qt::LinearGradientPattern));
    m_brushStyleComboBox->addItem(tr("Radial Gradient"), static_cast<int>(Qt::RadialGradientPattern));
    m_brushStyleComboBox->addItem(tr("Conical Gradient"), static_cast<int>(Qt::ConicalGradientPattern));
    m_brushStyleComboBox->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
    m_brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    m_brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    m_brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    m_brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    m_brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    m_brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    m_brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    m_brushStyleComboBox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    m_brushStyleComboBox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    m_brushStyleComboBox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    m_brushStyleComboBox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    m_brushStyleComboBox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    m_brushStyleComboBox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    m_brushStyleComboBox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    m_brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    m_brushStyleLabel = new QLabel(tr("&Brush"));
    m_brushStyleLabel->setBuddy(m_brushStyleComboBox);

    m_otherOptionsLabel = new QLabel(tr("Options:"));
    m_antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));
    m_transformationsCheckBox = new QCheckBox(tr("&Transformations"));

    connect(m_shapeComboBox, SIGNAL(activated(int)), this, SLOT(onShapeChanged()));
    connect(m_penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onPenChanged()));
    connect(m_penStyleComboBox, SIGNAL(activated(int)), this, SLOT(onPenChanged()));
    connect(m_penCapComboBox, SIGNAL(activated(int)), this, SLOT(onPenChanged()));
    connect(m_penJoinComboBox, SIGNAL(activated(int)), this, SLOT(onPenChanged()));
    connect(m_brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(onBrushChanged()));
    connect(m_antialiasingCheckBox, SIGNAL(toggled(bool)), m_renderArea, SLOT(setAntialised(bool)));
    connect(m_transformationsCheckBox, SIGNAL(toggled(bool)), m_renderArea, SLOT(setTransformed(bool)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(m_renderArea, 0, 0, 1, 4);
    mainLayout->addWidget(m_shapeLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(m_shapeComboBox, 2, 1);
    mainLayout->addWidget(m_penWidthLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(m_penWidthSpinBox, 3, 1);
    mainLayout->addWidget(m_penStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(m_penStyleComboBox, 4, 1);
    mainLayout->addWidget(m_penCapLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(m_penCapComboBox, 3, 3);
    mainLayout->addWidget(m_penJoinLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(m_penJoinComboBox, 2, 3);
    mainLayout->addWidget(m_brushStyleLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(m_brushStyleComboBox, 4, 3);
    mainLayout->addWidget(m_otherOptionsLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(m_antialiasingCheckBox, 5, 1, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(m_transformationsCheckBox, 5, 2, 1, 2, Qt::AlignRight);
    setLayout(mainLayout);

    onShapeChanged();
    onPenChanged();
    onBrushChanged();
    m_antialiasingCheckBox->setChecked(true);

    setWindowTitle(tr("Basic Drawing"));
}

void Window::onShapeChanged()
{
    RenderArea::Shape shape = RenderArea::Shape(m_shapeComboBox->currentData(IdRole).toInt());
    m_renderArea->setShape(shape);
}

void Window::onPenChanged()
{
    int width = m_penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(m_penStyleComboBox->currentData(IdRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(m_penJoinComboBox->currentData(IdRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(m_penCapComboBox->currentData(IdRole).toInt());
    m_renderArea->setPen(QPen(Qt::blue, width, style, cap, join));
}

void Window::onBrushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle(m_brushStyleComboBox->currentData(IdRole).toInt());

    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        m_renderArea->setBrush(linearGradient);
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        m_renderArea->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        m_renderArea->setBrush(conicalGradient);
    } else if (style == Qt::TexturePattern) {
        m_renderArea->setBrush(QBrush(QPixmap(":/brick.png")));
    } else {
        m_renderArea->setBrush(QBrush(Qt::green, style));
    }
}
