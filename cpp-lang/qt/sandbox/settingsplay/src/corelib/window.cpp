#include "window.h"
#include "childwindow.h"

#include <QtWidgets>

Window::Window(QWidget *parent)
    : QWidget(parent),
      m_lineEdit(Q_NULLPTR)
{
    auto groupBox = new QGroupBox(tr("Text in the settings"));
    m_lineEdit = new QLineEdit;
    auto groupBoxLayout = new QHBoxLayout;
    groupBoxLayout->addWidget(m_lineEdit);
    groupBox->setLayout(groupBoxLayout);

    auto button = new QPushButton(tr("Show Child"));
    connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(button);
    setLayout(mainLayout);

    setWindowTitle(tr("Parent Window"));
    resize(400, 200);

    readSettings();
}

Window::~Window()
{
}

void Window::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue(QStringLiteral("ParentWindow/text"), m_lineEdit->text());
    settings.setValue(QStringLiteral("ParentWindow/geometry"), saveGeometry());
    QWidget::closeEvent(event);
}

void Window::onButtonClicked()
{
    auto childWindow = ChildWindow::getChildWindow(this);
    childWindow->show();
}

void Window::readSettings()
{
    QSettings settings;
    m_lineEdit->setText(settings.value(QStringLiteral("ParentWindow/text"), QString()).toString());
    restoreGeometry(settings.value(QStringLiteral("ParentWindow/geometry")).toByteArray());
}
