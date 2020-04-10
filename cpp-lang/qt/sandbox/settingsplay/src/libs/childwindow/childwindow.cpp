#include "childwindow.h"

#include <QtWidgets>

static QPointer<ChildWindow> instance = 0;

ChildWindow *ChildWindow::getChildWindow(QWidget *parent)
{
    if (!instance)
        instance = new ChildWindow(parent);
    return instance;
}

void ChildWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue(QStringLiteral("ChildWindow/text"), m_lineEdit->text());
    settings.setValue(QStringLiteral("ChildWindow/geometry"), saveGeometry());
    QWidget::closeEvent(event);
}

ChildWindow::ChildWindow(QWidget *parent)
    : QWidget(parent),
      m_lineEdit(Q_NULLPTR)
{
    setWindowFlags(windowFlags() |= Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    auto groupBox = new QGroupBox(tr("Text in the settings"));
    m_lineEdit = new QLineEdit;
    auto groupBoxLayout = new QHBoxLayout;
    groupBoxLayout->addWidget(m_lineEdit);
    groupBox->setLayout(groupBoxLayout);

    auto button = new QPushButton(QStringLiteral("Close"));
    connect(button, SIGNAL(clicked()), this, SLOT(close()));

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(button);
    setLayout(mainLayout);

    setWindowTitle(tr("Child Window"));
    resize(400, 200);

    readSettings();
}

ChildWindow::ChildWindow(const ChildWindow &)
    : QWidget()
{
}

ChildWindow &ChildWindow::operator=(const ChildWindow &)
{
    return *this;
}

ChildWindow::~ChildWindow()
{
}

void ChildWindow::readSettings()
{
    QSettings settings;
    m_lineEdit->setText(settings.value(QStringLiteral("ChildWindow/text"), QString()).toString());
    restoreGeometry(settings.value(QStringLiteral("ChildWindow/geometry")).toByteArray());
}
