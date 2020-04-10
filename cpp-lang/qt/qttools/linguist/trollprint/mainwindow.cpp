#include "mainwindow.h"
#include "printpanel.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_printPanel(Q_NULLPTR),
      m_fileMenu(Q_NULLPTR),
      m_helpMenu(Q_NULLPTR),
      m_exitAct(Q_NULLPTR),
      m_aboutAct(Q_NULLPTR),
      m_aboutQtAct(Q_NULLPTR)
{
    m_printPanel = new PrintPanel;
    setCentralWidget(m_printPanel);

    createActions();
    createMenus();

    setWindowTitle(tr("Troll Print 1.1"));
}

void MainWindow::about()
{
    QMessageBox::information(this, tr("About Troll Print 1.1"),
                             tr("Troll Print 1.1.\n\nCopyright"
                                " 1999-2000 Software, Inc."));
}

void MainWindow::createActions()
{
    m_exitAct = new QAction(tr("E&xit"), this);
    m_exitAct->setShortcut(QKeySequence::Quit);
    connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));

    m_aboutAct = new QAction(tr("&About"), this);
    m_aboutAct->setShortcut(QKeySequence::HelpContents);
    connect(m_aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    m_aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(m_aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_exitAct);

    menuBar()->addSeparator();

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_aboutAct);
    m_helpMenu->addAction(m_aboutQtAct);
}
