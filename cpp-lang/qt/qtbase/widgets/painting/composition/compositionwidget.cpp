#include "compositionwidget.h"
#include "compositionrenderer.h"

#include <QtWidgets>
#include <QGLPixelBuffer>

CompositionWidget::CompositionWidget(QWidget *parent)
    : QWidget(parent)
{
    CompositionRenderer *view = new CompositionRenderer(this);

    QGroupBox *mainGroup = new QGroupBox(tr("Composition Modes"), this);
    QGroupBox *modeGroup = new QGroupBox(tr("Mode"), this);

    m_rbClear = new QRadioButton(tr("Clear"), modeGroup);
    connect(m_rbClear, SIGNAL(clicked()), view, SLOT(setClearMode()));
    m_rbSource = new QRadioButton(tr("Source"), modeGroup);
    connect(m_rbSource, SIGNAL(clicked()), view, SLOT(setSourceMode()));
    m_rbDest = new QRadioButton(tr("Destination"), modeGroup);
    connect(m_rbDest, SIGNAL(clicked()), view, SLOT(setDestMode()));
    m_rbSourceOver = new QRadioButton(tr("Source Over"), modeGroup);
    connect(m_rbSourceOver, SIGNAL(clicked()), view, SLOT(setSourceOverMode()));
    m_rbDestOver = new QRadioButton(tr("Destination Over"), modeGroup);
    connect(m_rbDestOver, SIGNAL(clicked()), view, SLOT(setDestOverMode()));
    m_rbSourceIn = new QRadioButton(tr("Source In"), modeGroup);
    connect(m_rbSourceIn, SIGNAL(clicked()), view, SLOT(setSourceInMode()));
    m_rbDestIn = new QRadioButton(tr("Dest In"), modeGroup);
    connect(m_rbDestIn, SIGNAL(clicked()), view, SLOT(setDestInMode()));
    m_rbSourceOut = new QRadioButton(tr("Source Out"), modeGroup);
    connect(m_rbSourceOut, SIGNAL(clicked()), view, SLOT(setSourceOutMode()));
    m_rbDestOut = new QRadioButton(tr("Dest Out"), modeGroup);
    connect(m_rbDestOut, SIGNAL(clicked()), view, SLOT(setDestOutMode()));
    m_rbSourceAtop = new QRadioButton(tr("Source Atop"), modeGroup);
    connect(m_rbSourceAtop, SIGNAL(clicked()), view, SLOT(setSourceAtopMode()));
    m_rbDestAtop = new QRadioButton(tr("Dest Atop"), modeGroup);
    connect(m_rbDestAtop, SIGNAL(clicked()), view, SLOT(setDestAtopMode()));
    m_rbXor = new QRadioButton(tr("Xor"), modeGroup);
    connect(m_rbXor, SIGNAL(clicked()), view, SLOT(setXorMode()));

    m_rbPlus = new QRadioButton(tr("Plus"), modeGroup);
    connect(m_rbPlus, SIGNAL(clicked()), view, SLOT(setPlusMode()));
    m_rbMultiply = new QRadioButton(tr("Multiply"), modeGroup);
    connect(m_rbMultiply, SIGNAL(clicked()), view, SLOT(setMultiplyMode()));
    m_rbScreen = new QRadioButton(tr("Screen"), modeGroup);
    connect(m_rbScreen, SIGNAL(clicked()), view, SLOT(setScreenMode()));
    m_rbOverlay = new QRadioButton(tr("Overlay"), modeGroup);
    connect(m_rbOverlay, SIGNAL(clicked()), view, SLOT(setOverlayMode()));
    m_rbDarken = new QRadioButton(tr("Darken"), modeGroup);
    connect(m_rbDarken, SIGNAL(clicked()), view, SLOT(setDarkenMode()));
    m_rbLighten = new QRadioButton(tr("Lighten"), modeGroup);
    connect(m_rbLighten, SIGNAL(clicked()), view, SLOT(setLightenMode()));
    m_rbColorDodge = new QRadioButton(tr("Color Dodge"), modeGroup);
    connect(m_rbColorDodge, SIGNAL(clicked()), view, SLOT(setColorDodgeMode()));
    m_rbColorBurn = new QRadioButton(tr("Color Burn"), modeGroup);
    connect(m_rbColorBurn, SIGNAL(clicked()), view, SLOT(setColorBurnMode()));
    m_rbHardLight = new QRadioButton(tr("Hard Light"), modeGroup);
    connect(m_rbHardLight, SIGNAL(clicked()), view, SLOT(setHardLightMode()));
    m_rbSoftLight = new QRadioButton(tr("Soft Light"), modeGroup);
    connect(m_rbSoftLight, SIGNAL(clicked()), view, SLOT(setSoftLightMode()));
    m_rbDifference = new QRadioButton(tr("Difference"), modeGroup);
    connect(m_rbDifference, SIGNAL(clicked()), view, SLOT(setDifferenceMode()));
    m_rbExclusion = new QRadioButton(tr("Exclusion"), modeGroup);
    connect(m_rbExclusion, SIGNAL(clicked()), view, SLOT(setExclusionMode()));

    QGroupBox *circleColorGroup = new QGroupBox(tr("Circle Color"), mainGroup);
    QSlider *circleColorSlider = new QSlider(Qt::Horizontal, circleColorGroup);
    circleColorSlider->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    circleColorSlider->setRange(0, 359);
    connect(circleColorSlider, &QSlider::valueChanged, view, &CompositionRenderer::setCircleColor);

    QGroupBox *circleAlphaGroup = new QGroupBox(tr("Circle Alpha"), mainGroup);
    QSlider *circleAlphaSlider = new QSlider(Qt::Horizontal, circleAlphaGroup);
    circleAlphaSlider->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    circleAlphaSlider->setRange(0, 255);
    connect(circleAlphaSlider, &QSlider::valueChanged, view, &CompositionRenderer::setCircleAlpha);

    QPushButton *animateButton = new QPushButton(tr("Animated"), mainGroup);
    animateButton->setCheckable(true);
    animateButton->setChecked(true);

    QPushButton *showSourceButton = new QPushButton(tr("Show Source"), mainGroup);

    QPushButton *whatsThisButton = new QPushButton(tr("What's this"), mainGroup);
    whatsThisButton->setCheckable(true);

#if defined(USE_OPENGL) && !defined(QT_OPENGL_ES)
    QPushButton *enableOpenGLButton = new QPushButton(tr("Use OpenGL"), mainGroup);
    enableOpenGLButton->setCheckable(true);
    enableOpenGLButton->setChecked(view->usesOpenGL());
    if (!QGLFormat::hasOpenGL() || !QGLPixelBuffer::hasOpenGLPbuffers())
        enableOpenGLButton->hide();
#endif

    QHBoxLayout *viewLayout = new QHBoxLayout(this);
    viewLayout->addWidget(view);
    viewLayout->addWidget(mainGroup);

    QVBoxLayout *mainGroupLayout = new QVBoxLayout(mainGroup);
    mainGroupLayout->addWidget(circleColorGroup);
    mainGroupLayout->addWidget(circleAlphaGroup);
    mainGroupLayout->addWidget(modeGroup);
    mainGroupLayout->addStretch();
    mainGroupLayout->addWidget(animateButton);
    mainGroupLayout->addWidget(whatsThisButton);
    mainGroupLayout->addWidget(showSourceButton);
#if defined(USE_OPENGL) && !defined(QT_OPENGL_ES)
    mainGroupLayout->addWidget(enableOpenGLButton);
#endif

    QGridLayout *modeLayout = new QGridLayout(modeGroup);
    modeLayout->addWidget(m_rbClear, 0, 0);
    modeLayout->addWidget(m_rbSource, 1, 0);
    modeLayout->addWidget(m_rbDest, 2, 0);
    modeLayout->addWidget(m_rbSourceOver, 3, 0);
    modeLayout->addWidget(m_rbDestOver, 4, 0);
    modeLayout->addWidget(m_rbSourceIn, 5, 0);
    modeLayout->addWidget(m_rbDestIn, 6, 0);
    modeLayout->addWidget(m_rbSourceOut, 7, 0);
    modeLayout->addWidget(m_rbDestOut, 8, 0);
    modeLayout->addWidget(m_rbSourceAtop, 9, 0);
    modeLayout->addWidget(m_rbDestAtop, 10, 0);
    modeLayout->addWidget(m_rbXor, 11, 0);

    modeLayout->addWidget(m_rbPlus, 0, 1);
    modeLayout->addWidget(m_rbMultiply, 1, 1);
    modeLayout->addWidget(m_rbScreen, 2, 1);
    modeLayout->addWidget(m_rbOverlay, 3, 1);
    modeLayout->addWidget(m_rbDarken, 4, 1);
    modeLayout->addWidget(m_rbLighten, 5, 1);
    modeLayout->addWidget(m_rbColorDodge, 6, 1);
    modeLayout->addWidget(m_rbColorBurn, 7, 1);
    modeLayout->addWidget(m_rbHardLight, 8, 1);
    modeLayout->addWidget(m_rbSoftLight, 9, 1);
    modeLayout->addWidget(m_rbDifference, 10, 1);
    modeLayout->addWidget(m_rbExclusion, 11, 1);

    QVBoxLayout *circleColorLayout = new QVBoxLayout(circleColorGroup);
    circleColorLayout->addWidget(circleColorSlider);

    QVBoxLayout *circleAlphaLayout = new QVBoxLayout(circleAlphaGroup);
    circleAlphaLayout->addWidget(circleAlphaSlider);

    view->loadDescription(":/composition.html");
    view->loadSourceFile(":/compositionrenderer.cpp");

    connect(whatsThisButton, SIGNAL(clicked(bool)), view, SLOT(setDescriptionEnabled(bool)));
    connect(view, SIGNAL(descriptionEnabledChanged(bool)), whatsThisButton, SLOT(setChecked(bool)));
    connect(showSourceButton, SIGNAL(clicked()), view, SLOT(showSource()));
#if defined(USE_OPENGL) && !defined(QT_OPENGL_ES)
    connect(enableOpenGLButton, SIGNAL(toggled(bool)), view, SLOT(enableOpenGL(bool)));
#endif

    circleColorSlider->setValue(270);
    circleAlphaSlider->setValue(200);
    m_rbSourceOut->animateClick();

    setWindowTitle(tr("Composition Modes"));
}
