#include "mainwindow.h"
#include "arrowpad.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_arrowPad(Q_NULLPTR),
      m_fileMenu(Q_NULLPTR),
      m_exitAct(Q_NULLPTR)
{
    m_arrowPad = new ArrowPad;
    setCentralWidget(m_arrowPad);

    m_exitAct = new QAction(tr("&Exit"), this);
    m_exitAct->setShortcut(QKeySequence::Quit);
    connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));

    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_exitAct);
}
