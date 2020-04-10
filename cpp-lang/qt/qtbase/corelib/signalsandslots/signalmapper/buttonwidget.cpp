#include "buttonwidget.h"

#include <QtWidgets>

ButtonWidget::ButtonWidget(QWidget *parent)
    : QWidget(parent),
      m_signalMapper(new QSignalMapper(this))
{
    m_textMap.insert(QStringLiteral("Tax File"), QStringLiteral("taxfile.txt"));
    m_textMap.insert(QStringLiteral("Accounts File"), QStringLiteral("accountsfile.txt"));
    m_textMap.insert(QStringLiteral("Report File"), QStringLiteral("reportfile.txt"));

    setLayout(new QHBoxLayout);

    auto signalMap = static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map);

    for (QMap<QString, QString>::const_iterator i = m_textMap.constBegin();
         i != m_textMap.constEnd(); ++i)
    {
        QPushButton *button = new QPushButton(i.key());
        m_signalMapper->setMapping(button, i.value());
        connect(button, &QAbstractButton::clicked, m_signalMapper, signalMap);
        layout()->addWidget(button);
    }

    connect(m_signalMapper, SIGNAL(mapped(QString)), this, SLOT(readFile(QString)));
}

ButtonWidget::~ButtonWidget()
{
}

void ButtonWidget::readFile(const QString &file)
{
    qDebug() << QString("File %0 was opened succesful.").arg(file);
}
