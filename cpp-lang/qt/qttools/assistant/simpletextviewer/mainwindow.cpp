#include "mainwindow.h"
#include "textedit.h"
#include "assistant.h"
#include "findfiledialog.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _textViewer(Q_NULLPTR),
      _assistant(Q_NULLPTR),
      _fileMenu(Q_NULLPTR),
      _helpMenu(Q_NULLPTR),
      _assistantAct(Q_NULLPTR),
      _clearAct(Q_NULLPTR),
      _openAct(Q_NULLPTR),
      _exitAct(Q_NULLPTR),
      _aboutAct(Q_NULLPTR),
      _aboutQtAct(Q_NULLPTR)

{
    _assistant = new Assistant;

    _textViewer = new TextEdit;
    QUrl baseUrl(QCoreApplication::applicationFilePath());
    QUrl relativeUrl("../simpletextviewer/documentation/intro.html");
    _textViewer->setContents(baseUrl.resolved(relativeUrl).toString());
    setCentralWidget(_textViewer);

    createActions();
    createMenus();

    setWindowTitle(tr("Simple Text Viewer"));
    resize(750, 400);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)

    delete _assistant;
}

void MainWindow::about()
{
    // TODO: add implementation
}

void MainWindow::showDocumentation()
{
    _assistant->showDocumentation("index.html");
}

void MainWindow::open()
{
    FindFileDialog dialog(_textViewer, _assistant);
    dialog.exec();
}

void MainWindow::createActions()
{
    _assistantAct = new QAction(tr("Help Contents"), this);
    _assistantAct->setShortcut(QKeySequence::HelpContents);
    connect(_assistantAct, SIGNAL(triggered()), this, SLOT(showDocumentation()));

    _openAct = new QAction(tr("&Open..."), this);
    _openAct->setShortcut(QKeySequence::Open);
    connect(_openAct, SIGNAL(triggered()), this, SLOT(open()));

    _exitAct = new QAction(tr("&Exit"), this);
    _exitAct->setShortcut(QKeySequence::Quit);
    connect(_exitAct, SIGNAL(triggered()), this, SLOT(close()));

    _aboutAct = new QAction(tr("&About"), this);
    connect(_aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    _aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(_aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    _fileMenu = new QMenu(tr("&File"), this);
    _fileMenu->addAction(_openAct);
    _fileMenu->addSeparator();
    _fileMenu->addAction(_exitAct);

    _helpMenu = new QMenu(tr("&Help"), this);
    _helpMenu->addAction(_assistantAct);
    _helpMenu->addSeparator();
    _helpMenu->addAction(_aboutAct);
    _helpMenu->addAction(_aboutQtAct);

    menuBar()->addMenu(_fileMenu);
    menuBar()->addMenu(_helpMenu);
}
