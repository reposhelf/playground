#include "pathstrokecontrols.h"
#include "pathstrokerenderer.h"

#include <QtWidgets>

PathStrokeControls::PathStrokeControls(PathStrokeRenderer *renderer,
                                       bool smallScreen,
                                       QWidget *parent)
    : QWidget(parent),
      m_renderer(renderer),
      m_capGroup(Q_NULLPTR),
      m_joinGroup(Q_NULLPTR),
      m_styleGroup(Q_NULLPTR),
      m_pathModeGroup(Q_NULLPTR)
{
    smallScreen ? layoutForSmallScreen() : layoutForDesktop();
}

void PathStrokeControls::emitQuitSignal()
{
    emit quitPressed();
}

void PathStrokeControls::emitOkSignal()
{
    emit okPressed();
}

void PathStrokeControls::createCommonControls(QWidget *parent)
{
    m_capGroup = new QGroupBox(tr("Cap Style"), parent);
    m_capGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    QRadioButton *flatCap = new QRadioButton(tr("Flat"), m_capGroup);
    QRadioButton *squareCap = new QRadioButton(tr("Square"), m_capGroup);
    QRadioButton *roundCap = new QRadioButton(tr("Round"), m_capGroup);
    flatCap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    squareCap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    roundCap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_joinGroup = new QGroupBox(tr("Join Style"), parent);
    m_joinGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    QRadioButton *bevelJoin = new QRadioButton(tr("Bevel"), m_joinGroup);
    QRadioButton *miterJoin = new QRadioButton(tr("Miter"), m_joinGroup);
    QRadioButton *roundJoin = new QRadioButton(tr("Round"), m_joinGroup);
    bevelJoin->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    miterJoin->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    roundJoin->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_styleGroup = new QGroupBox(tr("Pen Style"), parent);
    m_styleGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    QRadioButton *solidLine = new QRadioButton(m_styleGroup);
    QRadioButton *dashLine = new QRadioButton(m_styleGroup);
    QRadioButton *dotLine = new QRadioButton(m_styleGroup);
    QRadioButton *dashDotLine = new QRadioButton(m_styleGroup);
    QRadioButton *dashDotDotLine = new QRadioButton(m_styleGroup);
    QRadioButton *customDashLine = new QRadioButton(tr("Custom"), m_styleGroup);

    QPixmap line_solid(":/res/images/line_solid.png");
    solidLine->setIcon(line_solid);
    solidLine->setIconSize(line_solid.size());
    QPixmap line_dashed(":/res/images/line_dashed.png");
    dashLine->setIcon(line_dashed);
    dashLine->setIconSize(line_dashed.size());
    QPixmap line_dotted(":/res/images/line_dotted.png");
    dotLine->setIcon(line_dotted);
    dotLine->setIconSize(line_dotted.size());
    QPixmap line_dash_dot(":/res/images/line_dash_dot.png");
    dashDotLine->setIcon(line_dash_dot);
    dashDotLine->setIconSize(line_dash_dot.size());
    QPixmap line_dash_dot_dot(":/res/images/line_dash_dot_dot.png");
    dashDotDotLine->setIcon(line_dash_dot_dot);
    dashDotDotLine->setIconSize(line_dash_dot_dot.size());

    int fixedHeight = bevelJoin->sizeHint().height();
    solidLine->setFixedHeight(fixedHeight);
    dashLine->setFixedHeight(fixedHeight);
    dotLine->setFixedHeight(fixedHeight);
    dashDotLine->setFixedHeight(fixedHeight);
    dashDotDotLine->setFixedHeight(fixedHeight);

    m_pathModeGroup = new QGroupBox(tr("Line Style"), parent);
    m_pathModeGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    QRadioButton *curveMode = new QRadioButton(tr("Curves"), m_pathModeGroup);
    QRadioButton *lineMode = new QRadioButton(tr("Lines"), m_pathModeGroup);

    // layouts
    QVBoxLayout *capGroupLayout = new QVBoxLayout(m_capGroup);
    capGroupLayout->addWidget(flatCap);
    capGroupLayout->addWidget(squareCap);
    capGroupLayout->addWidget(roundCap);

    QVBoxLayout *joinGroupLayout = new QVBoxLayout(m_joinGroup);
    joinGroupLayout->addWidget(bevelJoin);
    joinGroupLayout->addWidget(miterJoin);
    joinGroupLayout->addWidget(roundJoin);

    QVBoxLayout *styleGroupLayout = new QVBoxLayout(m_styleGroup);
    styleGroupLayout->addWidget(solidLine);
    styleGroupLayout->addWidget(dashLine);
    styleGroupLayout->addWidget(dotLine);
    styleGroupLayout->addWidget(dashDotLine);
    styleGroupLayout->addWidget(dashDotDotLine);
    styleGroupLayout->addWidget(customDashLine);

    QVBoxLayout *pathModeGroupLayout = new QVBoxLayout(m_pathModeGroup);
    pathModeGroupLayout->addWidget(curveMode);
    pathModeGroupLayout->addWidget(lineMode);

    // connections
    connect(flatCap, SIGNAL(clicked()), m_renderer, SLOT(setFlatCap()));
    connect(squareCap, SIGNAL(clicked()), m_renderer, SLOT(setSquareCap()));
    connect(roundCap, SIGNAL(clicked()), m_renderer, SLOT(setRoundCap()));

    connect(bevelJoin, SIGNAL(clicked()), m_renderer, SLOT(setBevelJoin()));
    connect(miterJoin, SIGNAL(clicked()), m_renderer, SLOT(setMiterJoin()));
    connect(roundJoin, SIGNAL(clicked()), m_renderer, SLOT(setRoundJoin()));

    connect(curveMode, SIGNAL(clicked()), m_renderer, SLOT(setCurveMode()));
    connect(lineMode, SIGNAL(clicked()), m_renderer, SLOT(setLineMode()));

    connect(solidLine, SIGNAL(clicked()), m_renderer, SLOT(setSolidLine()));
    connect(dashLine, SIGNAL(clicked()), m_renderer, SLOT(setDashLine()));
    connect(dashDotLine, SIGNAL(clicked()), m_renderer, SLOT(setDashDotLine()));
    connect(dashDotDotLine, SIGNAL(clicked()), m_renderer, SLOT(setDashDotDotLine()));
    connect(customDashLine, SIGNAL(clicked()), m_renderer, SLOT(setCustomDashLine()));

    // set defaults
    flatCap->setChecked(true);
    bevelJoin->setChecked(true);
    curveMode->setChecked(true);
    solidLine->setChecked(true);
}

void PathStrokeControls::layoutForDesktop()
{
    QGroupBox *mainGroup = new QGroupBox(tr("Path Stroking"), this);
    mainGroup->setFixedWidth(180);

    createCommonControls(mainGroup);

    QGroupBox *penWidthGroup = new QGroupBox(tr("Pen Width"), mainGroup);
    QSlider *penWidth = new QSlider(Qt::Horizontal, penWidthGroup);
    penWidth->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    penWidth->setRange(0, 500);

    QPushButton *animatedButton = new QPushButton(tr("Animate"), mainGroup);
    animatedButton->setCheckable(true);

    QPushButton *showSourceButton = new QPushButton(tr("Show Source"), mainGroup);

#ifdef QT_OPENGL_SUPPORT
    QPushButton *enableOpenGLButton = new QPushButton(tr("Use OpenGL"), mainGroup);
    enableOpenGLButton->setCheckable(true);
    enableOpenGLButton->setChecked(m_renderer->usesOpenGL());
    if (!QGLFormat::hasOpenGL())
        enableOpenGLButton->hide();
#endif

    QPushButton *whatsThisButton = new QPushButton(tr("What's This"), mainGroup);
    whatsThisButton->setCheckable(true);

    // layouts
    QVBoxLayout *penWidthGroupLayout = new QVBoxLayout(penWidthGroup);
    penWidthGroupLayout->addWidget(penWidth);

    QVBoxLayout *mainGroupLayout = new QVBoxLayout(mainGroup);
    mainGroupLayout->setMargin(3);
    mainGroupLayout->addWidget(m_capGroup);
    mainGroupLayout->addWidget(m_joinGroup);
    mainGroupLayout->addWidget(m_styleGroup);
    mainGroupLayout->addWidget(penWidthGroup);
    mainGroupLayout->addWidget(m_pathModeGroup);
    mainGroupLayout->addWidget(animatedButton);
    mainGroupLayout->addStretch(1);
    mainGroupLayout->addWidget(showSourceButton);
#ifdef QT_OPENGL_SUPPORT
    mainGroupLayout->addWidget(enableOpenGLButton);
#endif
    mainGroupLayout->addWidget(whatsThisButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->addWidget(mainGroup);

    // connections
    connect(animatedButton, SIGNAL(toggled(bool)), m_renderer, SLOT(setAnimated(bool)));
    connect(penWidth, SIGNAL(valueChanged(int)), m_renderer, SLOT(setPenWidth(int)));

    connect(showSourceButton, SIGNAL(clicked()), m_renderer, SLOT(showSource()));
#ifdef QT_OPENGL_SUPPORT
    connect(enableOpenGLButton, SIGNAL(clicked(bool)), m_renderer, SLOT(enableOpenGL(bool)));
#endif
    connect(whatsThisButton, SIGNAL(clicked(bool)), m_renderer, SLOT(setDescriptionEnabled(bool)));
    connect(m_renderer, SIGNAL(descriptionEnabledChanged(bool)),
            whatsThisButton, SLOT(setChecked(bool)));

    // defaults
    animatedButton->setChecked(true);
    penWidth->setValue(50);
}

void PathStrokeControls::layoutForSmallScreen()
{
    createCommonControls(this);

    m_capGroup->layout()->setMargin(0);
    m_joinGroup->layout()->setMargin(0);
    m_styleGroup->layout()->setMargin(0);
    m_pathModeGroup->layout()->setMargin(0);

    QPushButton* okBtn = new QPushButton(tr("OK"), this);
    okBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    okBtn->setMinimumSize(100,okBtn->minimumSize().height());

    QPushButton* quitBtn = new QPushButton(tr("Quit"), this);
    quitBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    quitBtn->setMinimumSize(100, okBtn->minimumSize().height());

    QLabel *penWidthLabel = new QLabel(tr(" Width:"));
    QSlider *penWidth = new QSlider(Qt::Horizontal, this);
    penWidth->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    penWidth->setRange(0, 500);

#ifdef QT_OPENGL_SUPPORT
    QPushButton *enableOpenGLButton = new QPushButton(this);
    enableOpenGLButton->setText(tr("Use OpenGL"));
    enableOpenGLButton->setCheckable(true);
    enableOpenGLButton->setChecked(m_renderer->usesOpenGL());
    if (!QGLFormat::hasOpenGL())
        enableOpenGLButton->hide();
#endif

    // layouts
    QHBoxLayout *penWidthLayout = new QHBoxLayout(0);
    penWidthLayout->addWidget(penWidthLabel, 0, Qt::AlignRight);
    penWidthLayout->addWidget(penWidth);

    QVBoxLayout *leftLayout = new QVBoxLayout(0);
    leftLayout->addWidget(m_capGroup);
    leftLayout->addWidget(m_joinGroup);
#ifdef QT_OPENGL_SUPPORT
    leftLayout->addWidget(enableOpenGLButton);
#endif
    leftLayout->addLayout(penWidthLayout);

    QVBoxLayout *rightLayout = new QVBoxLayout(0);
    rightLayout->addWidget(m_styleGroup);
    rightLayout->addWidget(m_pathModeGroup);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setMargin(0);

    // Add spacers around the form items so we don't look stupid at higher resolutions
    mainLayout->addItem(new QSpacerItem(0,0), 0, 0, 1, 4);
    mainLayout->addItem(new QSpacerItem(0,0), 1, 0, 2, 1);
    mainLayout->addItem(new QSpacerItem(0,0), 1, 3, 2, 1);
    mainLayout->addItem(new QSpacerItem(0,0), 3, 0, 1, 4);

    mainLayout->addLayout(leftLayout, 1, 1);
    mainLayout->addLayout(rightLayout, 1, 2);
    mainLayout->addWidget(quitBtn, 2, 1, Qt::AlignHCenter | Qt::AlignTop);
    mainLayout->addWidget(okBtn, 2, 2, Qt::AlignHCenter | Qt::AlignTop);

#ifdef QT_OPENGL_SUPPORT
    connect(enableOpenGLButton, SIGNAL(clicked(bool)), m_renderer, SLOT(enableOpenGL(bool)));
#endif

    connect(penWidth, SIGNAL(valueChanged(int)), m_renderer, SLOT(setPenWidth(int)));
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(emitQuitSignal()));
    connect(okBtn, SIGNAL(clicked()), this, SLOT(emitOkSignal()));

    m_renderer->setAnimated(true);
    penWidth->setValue(50);
}
