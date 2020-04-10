#include "gradientwidget.h"
#include "gradientrenderer.h"
#include "gradienteditor.h"
#include "hoverpoints.h"

#include <QtWidgets>

GradientWidget::GradientWidget(QWidget *parent)
    : QWidget(parent),
      m_renderer(Q_NULLPTR),
      m_editor(Q_NULLPTR),
      m_linearButton(Q_NULLPTR),
      m_radialButton(Q_NULLPTR),
      m_conicalButton(Q_NULLPTR),
      m_padSpreadButton(Q_NULLPTR),
      m_reflectSpreadButton(Q_NULLPTR),
      m_repeatSpreadButton(Q_NULLPTR)
{
    setWindowTitle(tr("Gradients"));

    m_renderer = new GradientRenderer(this);

    QGroupBox *mainGroup = new QGroupBox(tr("Gradients"), this);

    QGroupBox *editorGroup = new QGroupBox(tr("Color Editor"), mainGroup);

    m_editor = new GradientEditor(editorGroup);

    QGroupBox *typeGroup = new QGroupBox(tr("Gradient Type"), mainGroup);
    m_linearButton = new QRadioButton(tr("Linear Gradient"), typeGroup);
    m_radialButton = new QRadioButton(tr("Radial Gradient"), typeGroup);
    m_conicalButton = new QRadioButton(tr("Conical Gradient"), typeGroup);

    QGroupBox *spreadGroup = new QGroupBox(tr("Spread Method"), mainGroup);
    m_padSpreadButton = new QRadioButton(tr("Pad Spread"), spreadGroup);
    m_reflectSpreadButton = new QRadioButton(tr("Reflect Spread"), spreadGroup);
    m_repeatSpreadButton = new QRadioButton(tr("Repeat Spread"), spreadGroup);

    QGroupBox *defaultsGroup = new QGroupBox(tr("Defaults"), mainGroup);
    QPushButton *default1Button = new QPushButton(tr("1"), defaultsGroup);
    QPushButton *default2Button = new QPushButton(tr("2"), defaultsGroup);
    QPushButton *default3Button = new QPushButton(tr("3"), defaultsGroup);
    QPushButton *default4Button = new QPushButton(tr("Reset"), defaultsGroup);

    QPushButton *showSourceButton = new QPushButton(tr("Show Source"), mainGroup);
#ifdef QT_OPENGL_SUPPORT
    QPushButton *enableOpenGLButton = new QPushButton(tr("Use OpenGL"), mainGroup);
    enableOpenGLButton->setCheckable(true);
    enableOpenGLButton->setChecked(m_renderer->usesOpenGL());
    if (!QGLFormat::hasOpenGL())
        enableOpenGLButton->hide();
#endif
    QPushButton *whatsThisButton = new QPushButton(tr("What's This?"), mainGroup);
    whatsThisButton->setCheckable(true);

    // layouts
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_renderer);
    mainLayout->addWidget(mainGroup);

    mainGroup->setFixedWidth(180);

    QVBoxLayout *mainGroupLayout = new QVBoxLayout(mainGroup);
    mainGroupLayout->addWidget(editorGroup);
    mainGroupLayout->addWidget(typeGroup);
    mainGroupLayout->addWidget(spreadGroup);
    mainGroupLayout->addWidget(defaultsGroup);
    mainGroupLayout->addStretch(1);
    mainGroupLayout->addWidget(showSourceButton);
#ifdef QT_OPENGL_SUPPORT
    mainGroupLayout->addWidget(enableOpenGLButton);
#endif
    mainGroupLayout->addWidget(whatsThisButton);

    QVBoxLayout *editorLayout = new QVBoxLayout(editorGroup);
    editorLayout->addWidget(m_editor);
    editorLayout->addWidget(default4Button);

    QVBoxLayout *typeGrouplayout = new QVBoxLayout(typeGroup);
    typeGrouplayout->addWidget(m_linearButton);
    typeGrouplayout->addWidget(m_radialButton);
    typeGrouplayout->addWidget(m_conicalButton);

    QVBoxLayout *spreadGroupLayout = new QVBoxLayout(spreadGroup);
    spreadGroupLayout->addWidget(m_padSpreadButton);
    spreadGroupLayout->addWidget(m_reflectSpreadButton);
    spreadGroupLayout->addWidget(m_repeatSpreadButton);

    QHBoxLayout *defaultsGroupLayout = new QHBoxLayout(defaultsGroup);
    defaultsGroupLayout->addWidget(default1Button);
    defaultsGroupLayout->addWidget(default2Button);
    defaultsGroupLayout->addWidget(default3Button);

    connect(m_editor, &GradientEditor::gradientStopsChanged,
            m_renderer, &GradientRenderer::setGradientStops);

    connect(m_linearButton, SIGNAL(clicked()), m_renderer, SLOT(setLinearGradient()));
    connect(m_radialButton, SIGNAL(clicked()), m_renderer, SLOT(setRadialGradient()));
    connect(m_conicalButton, SIGNAL(clicked()), m_renderer, SLOT(setConicalGradient()));

    connect(m_padSpreadButton, SIGNAL(clicked()), m_renderer, SLOT(setPadSpread()));
    connect(m_reflectSpreadButton, SIGNAL(clicked()), m_renderer, SLOT(setReflectSpread()));
    connect(m_repeatSpreadButton, SIGNAL(clicked()), m_renderer, SLOT(setRepeatSpread()));

    connect(default1Button, SIGNAL(clicked()), this, SLOT(setDefault1()));
    connect(default2Button, SIGNAL(clicked()), this, SLOT(setDefault2()));
    connect(default3Button, SIGNAL(clicked()), this, SLOT(setDefault3()));
    connect(default4Button, SIGNAL(clicked()), this, SLOT(setDefault4()));

    connect(showSourceButton, SIGNAL(clicked()), m_renderer, SLOT(showSource()));
#ifdef QT_OPENGL_SUPPORT
    connect(enableOpenGLButton, SIGNAL(clicked(bool)), m_renderer, SLOT(enableOpenGL(bool)));
#endif
    connect(whatsThisButton, SIGNAL(clicked(bool)),
            m_renderer, SLOT(setDescriptionEnabled(bool)));
    connect(whatsThisButton, SIGNAL(clicked(bool)),
            m_renderer->hoverPoints(), SLOT(setDisabled(bool)));
    connect(m_renderer, SIGNAL(descriptionEnabledChanged(bool)),
            whatsThisButton, SLOT(setChecked(bool)));
    connect(m_renderer, SIGNAL(descriptionEnabledChanged(bool)),
            m_renderer->hoverPoints(), SLOT(setDisabled(bool)));

    m_renderer->loadSourceFile(":/gradientwidget.cpp");
    m_renderer->loadDescription(":/gradients.html");

    QTimer::singleShot(50, this, SLOT(setDefault1()));
}

void GradientWidget::setDefault1()
{
    setDefault(1);
}

void GradientWidget::setDefault2()
{
    setDefault(2);
}

void GradientWidget::setDefault3()
{
    setDefault(3);
}

void GradientWidget::setDefault4()
{
    setDefault(4);
}

void GradientWidget::setDefault(int i)
{
    QGradientStops stops;
    switch (i) {
    case 1:
        stops << QGradientStop(0.00, QColor::fromRgba(0));
        stops << QGradientStop(0.04, QColor::fromRgba(0xff131360));
        stops << QGradientStop(0.08, QColor::fromRgba(0xff202ccc));
        stops << QGradientStop(0.42, QColor::fromRgba(0xff93d3f9));
        stops << QGradientStop(0.51, QColor::fromRgba(0xffb3e6ff));
        stops << QGradientStop(0.73, QColor::fromRgba(0xffffffec));
        stops << QGradientStop(0.92, QColor::fromRgba(0xff5353d9));
        stops << QGradientStop(0.96, QColor::fromRgba(0xff262666));
        stops << QGradientStop(1.00, QColor::fromRgba(0));
        m_linearButton->animateClick();
        m_repeatSpreadButton->animateClick();
        break;

    case 2:
        stops << QGradientStop(0.00, QColor::fromRgba(0xffffffff));
        stops << QGradientStop(0.11, QColor::fromRgba(0xfff9ffa0));
        stops << QGradientStop(0.13, QColor::fromRgba(0xfff9ff99));
        stops << QGradientStop(0.14, QColor::fromRgba(0xfff3ff86));
        stops << QGradientStop(0.49, QColor::fromRgba(0xff93b353));
        stops << QGradientStop(0.87, QColor::fromRgba(0xff264619));
        stops << QGradientStop(0.96, QColor::fromRgba(0xff0c1306));
        stops << QGradientStop(1.00, QColor::fromRgba(0));
        m_radialButton->animateClick();
        m_padSpreadButton->animateClick();
        break;

    case 3:
        stops << QGradientStop(0.00, QColor::fromRgba(0));
        stops << QGradientStop(0.10, QColor::fromRgba(0xffe0cc73));
        stops << QGradientStop(0.17, QColor::fromRgba(0xffc6a006));
        stops << QGradientStop(0.46, QColor::fromRgba(0xff600659));
        stops << QGradientStop(0.72, QColor::fromRgba(0xff0680ac));
        stops << QGradientStop(0.92, QColor::fromRgba(0xffb9d9e6));
        stops << QGradientStop(1.00, QColor::fromRgba(0));
        m_conicalButton->animateClick();
        m_padSpreadButton->animateClick();
        break;

    case 4:
        stops << QGradientStop(0.00, QColor::fromRgba(0xff000000));
        stops << QGradientStop(1.00, QColor::fromRgba(0xffffffff));
        break;

    default:
        qWarning("bad default %d\n", i);
        break;
    }

    int hOff = m_renderer->width() / 10;
    int vOff = m_renderer->height() / 8;
    QPolygonF points;
    points << QPointF(m_renderer->width() / 2, m_renderer->height() / 2)
           << QPointF(m_renderer->width() / 2 - hOff, m_renderer->height() / 2 - vOff);

    m_editor->setGradientStops(stops);
    m_renderer->hoverPoints()->setPoints(points);
    m_renderer->setGradientStops(stops);
}
