#include "assistant.h"

#include <QProcess>
#include <QLibraryInfo>
#include <QDir>
#include <QCoreApplication>
#include <QUrl>
#include <QMessageBox>

Assistant::Assistant()
    : _process(Q_NULLPTR)
{
}

Assistant::~Assistant()
{
    if (_process && _process->state() == QProcess::Running) {
        _process->terminate();
        _process->waitForFinished(3000);
    }
    delete _process;
}

void Assistant::showDocumentation(const QString &file)
{
    if (!startAssistant())
        return;

    QByteArray ba("SetSource ");
    ba.append("qthelp://org.qt-project.examples.simpletextviewer/doc/");

    _process->write(ba + file.toLocal8Bit() + '\n');
}

bool Assistant::startAssistant()
{
    if (!_process)
        _process = new QProcess;

    if (_process->state() != QProcess::Running) {
        QString app = QLibraryInfo::location(QLibraryInfo::BinariesPath)
                + QDir::separator()
                + QLatin1String("assistant");

        QUrl baseUrl(QCoreApplication::applicationFilePath());
        QUrl relativeUrl("../simpletextviewer/documentation/simpletextviewer.qhc");

        QStringList args;
        args << QLatin1String("-collectionFile")
             << baseUrl.resolved(relativeUrl).toString()
             << QLatin1String("-enableRemoteControl");

        _process->start(app, args);

        if (!_process->waitForStarted()) {
            QMessageBox::critical(0, QObject::tr("Simple Text Viewer"),
                                  QObject::tr("Unable to launch Qt Assistant (%0)").arg(app));
            return false;
        }
    }
    return true;
}
