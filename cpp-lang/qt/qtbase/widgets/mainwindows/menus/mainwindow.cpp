#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_fileMenu(Q_NULLPTR),
      m_editMenu(Q_NULLPTR),
      m_formatMenu(Q_NULLPTR),
      m_helpMenu(Q_NULLPTR),
      m_alignmentGroup(Q_NULLPTR),
      m_newAct(Q_NULLPTR),
      m_openAct(Q_NULLPTR),
      m_saveAct(Q_NULLPTR),
      m_printAct(Q_NULLPTR),
      m_exitAct(Q_NULLPTR),
      m_undoAct(Q_NULLPTR),
      m_redoAct(Q_NULLPTR),
      m_cutAct(Q_NULLPTR),
      m_copyAct(Q_NULLPTR),
      m_pasteAct(Q_NULLPTR),
      m_boldAct(Q_NULLPTR),
      m_italicAct(Q_NULLPTR),
      m_leftAlignAct(Q_NULLPTR),
      m_rightAlignAct(Q_NULLPTR),
      m_justifyAct(Q_NULLPTR),
      m_centerAct(Q_NULLPTR),
      m_setLineSpacingAct(Q_NULLPTR),
      m_setParagraphSpacingAct(Q_NULLPTR),
      m_aboutAct(Q_NULLPTR),
      m_aboutQtAct(Q_NULLPTR),
      m_infoLabel(Q_NULLPTR)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_infoLabel = new QLabel(tr("<i>Choose a menu option, or right click to invoke a context menu</i>"));
    m_infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    m_infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(m_infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Menus"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(m_copyAct);
    menu.addAction(m_cutAct);
    menu.addAction(m_pasteAct);
    menu.exec(event->globalPos());
}

void MainWindow::newFile()
{
    m_infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void MainWindow::open()
{
    m_infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void MainWindow::save()
{
    m_infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void MainWindow::print()
{
    m_infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void MainWindow::undo()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Undo</b>"));
}

void MainWindow::redo()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Redo</b>"));
}

void MainWindow::cut()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Cut</b>"));
}

void MainWindow::copy()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void MainWindow::paste()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}

void MainWindow::bold()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Bold</b>"));
}

void MainWindow::italic()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Italic</b>"));
}

void MainWindow::leftAlign()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Left Align</b>"));
}

void MainWindow::rightAlign()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Right Align</b>"));
}

void MainWindow::justify()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Justify</b>"));
}

void MainWindow::center()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Center</b>"));
}

void MainWindow::setLineSpacing()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Set Line Spacing</b>"));
}

void MainWindow::setParagraphSpacing()
{
    m_infoLabel->setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b>"));
}

void MainWindow::about()
{
    m_infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
                       tr("The <b>Menu</b> example shows how to create "
                          "menu-bar menus and context menus."));
}

void MainWindow::aboutQt()
{
    m_infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}

void MainWindow::createActions()
{
    m_newAct = new QAction(tr("&New"), this);
    m_newAct->setShortcuts(QKeySequence::New);
    m_newAct->setStatusTip(tr("Create a new file"));
    connect(m_newAct, &QAction::triggered, this, &MainWindow::newFile);

    m_openAct = new QAction(tr("&Open..."), this);
    m_openAct->setShortcuts(QKeySequence::Open);
    m_openAct->setStatusTip(tr("Open an existing file"));
    connect(m_openAct, &QAction::triggered, this, &MainWindow::open);

    m_saveAct = new QAction(tr("&Save"), this);
    m_saveAct->setShortcuts(QKeySequence::Save);
    m_saveAct->setStatusTip(tr("Save the document to disk"));
    connect(m_saveAct, &QAction::triggered, this, &MainWindow::save);

    m_printAct = new QAction(tr("&Print..."), this);
    m_printAct->setShortcuts(QKeySequence::Print);
    m_printAct->setStatusTip(tr("Print the document"));
    connect(m_printAct, &QAction::triggered, this, &MainWindow::print);

    m_exitAct = new QAction(tr("E&xit"), this);
    m_exitAct->setShortcuts(QKeySequence::Quit);
    m_exitAct->setStatusTip(tr("Exit the application"));
    connect(m_exitAct, &QAction::triggered, this, &MainWindow::close);

    m_undoAct = new QAction(tr("&Undo"), this);
    m_undoAct->setShortcuts(QKeySequence::Undo);
    m_undoAct->setStatusTip(tr("Undo the last operation"));
    connect(m_undoAct, &QAction::triggered, this, &MainWindow::undo);

    m_redoAct = new QAction(tr("&Redo"), this);
    m_redoAct->setShortcuts(QKeySequence::Redo);
    m_redoAct->setStatusTip(tr("Redo the last operation"));
    connect(m_redoAct, &QAction::triggered, this, &MainWindow::redo);

    m_cutAct = new QAction(tr("C&ut"), this);
    m_cutAct->setShortcuts(QKeySequence::Cut);
    m_cutAct->setStatusTip(tr("Cut the current selection's content to the clipboard "));
    connect(m_cutAct, &QAction::triggered, this, &MainWindow::cut);

    m_copyAct = new QAction(tr("&Copy"), this);
    m_copyAct->setShortcuts(QKeySequence::Copy);
    m_copyAct->setStatusTip(tr("Copy the current selection's content to the clipboard"));
    connect(m_copyAct, &QAction::triggered, this, &MainWindow::copy);

    m_pasteAct = new QAction(tr("&Paste"), this);
    m_pasteAct->setShortcuts(QKeySequence::Paste);
    m_pasteAct->setStatusTip(tr("Paste the clipboard's content to the current selection"));
    connect(m_pasteAct, &QAction::triggered, this, &MainWindow::paste);

    m_boldAct = new QAction(tr("&Bold"), this);
    m_boldAct->setCheckable(true);
    m_boldAct->setShortcuts(QKeySequence::Bold);
    m_boldAct->setStatusTip(tr("Make the text bold"));
    connect(m_boldAct, &QAction::triggered, this, &MainWindow::bold);

    QFont boldFont = m_boldAct->font();
    boldFont.setBold(true);
    m_boldAct->setFont(boldFont);

    m_italicAct = new QAction(tr("&Italic"), this);
    m_italicAct->setCheckable(true);
    m_italicAct->setShortcuts(QKeySequence::Italic);
    m_italicAct->setStatusTip(tr("Make the text italic"));
    connect(m_italicAct, &QAction::triggered, this, &MainWindow::italic);

    QFont italicFont = m_italicAct->font();
    italicFont.setItalic(true);
    m_italicAct->setFont(italicFont);

    m_setLineSpacingAct = new QAction(tr("Set &Line Spacing..."), this);
    m_setLineSpacingAct->setStatusTip(tr("Change the gap between the lines of a paragraph"));
    connect(m_setLineSpacingAct, &QAction::triggered, this, &MainWindow::setLineSpacing);

    m_setParagraphSpacingAct = new QAction(tr("Set &Paragraph Spacing..."), this);
    m_setParagraphSpacingAct->setStatusTip(tr("Change the gap  between paragraphs"));
    connect(m_setParagraphSpacingAct, &QAction::triggered, this, &MainWindow::setParagraphSpacing);

    m_aboutAct = new QAction(tr("&About"), this);
    m_aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(m_aboutAct, &QAction::triggered, this, &MainWindow::about);

    m_aboutQtAct = new QAction(tr("About &Qt"), this);
    m_aboutQtAct->setStatusTip(tr("Show the Qt's library About box"));
    connect(m_aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

    m_leftAlignAct = new QAction(tr("&Left Align"), this);
    m_leftAlignAct->setCheckable(true);
    m_leftAlignAct->setShortcut(Qt::CTRL + Qt::Key_L);
    m_leftAlignAct->setStatusTip(tr("Left align the selected text"));
    connect(m_leftAlignAct, &QAction::triggered, this, &MainWindow::leftAlign);

    m_rightAlignAct = new QAction(tr("&Right Align"), this);
    m_rightAlignAct->setCheckable(true);
    m_rightAlignAct->setShortcut(Qt::CTRL + Qt::Key_R);
    m_rightAlignAct->setStatusTip(tr("Right align the selected text"));
    connect(m_rightAlignAct, &QAction::triggered, this, &MainWindow::rightAlign);

    m_justifyAct = new QAction(tr("&Justify"), this);
    m_justifyAct->setCheckable(true);
    m_justifyAct->setShortcut(Qt::CTRL + Qt::Key_J);
    m_justifyAct->setStatusTip(tr("Justify the selected text"));
    connect(m_justifyAct, &QAction::triggered, this, &MainWindow::justify);

    m_centerAct = new QAction(tr("&Center"), this);
    m_centerAct->setCheckable(true);
    m_centerAct->setShortcut(Qt::CTRL + Qt::Key_E);
    m_centerAct->setStatusTip(tr("Center the selected text"));
    connect(m_centerAct, &QAction::triggered, this, &MainWindow::center);

    m_alignmentGroup = new QActionGroup(this);
    m_alignmentGroup->addAction(m_leftAlignAct);
    m_alignmentGroup->addAction(m_rightAlignAct);
    m_alignmentGroup->addAction(m_justifyAct);
    m_alignmentGroup->addAction(m_centerAct);
    m_leftAlignAct->setChecked(true);
}

void MainWindow::createMenus()
{
    m_fileMenu = menuBar()->addMenu(tr("File"));
    m_fileMenu->addAction(m_newAct);
    m_fileMenu->addAction(m_openAct);
    m_fileMenu->addAction(m_saveAct);
    m_fileMenu->addAction(m_printAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAct);

    m_editMenu = menuBar()->addMenu(tr("Edit"));
    m_editMenu->addAction(m_undoAct);
    m_editMenu->addAction(m_redoAct);
    m_editMenu->addSeparator();
    m_editMenu->addAction(m_cutAct);
    m_editMenu->addAction(m_copyAct);
    m_editMenu->addAction(m_pasteAct);
    m_editMenu->addSeparator();

    m_formatMenu = m_editMenu->addMenu(tr("&Format"));
    m_formatMenu->addAction(m_boldAct);
    m_formatMenu->addAction(m_italicAct);
    m_formatMenu->addSeparator()->setText(tr("Alignment"));
    m_formatMenu->addAction(m_leftAlignAct);
    m_formatMenu->addAction(m_rightAlignAct);
    m_formatMenu->addAction(m_justifyAct);
    m_formatMenu->addAction(m_centerAct);
    m_formatMenu->addSeparator();
    m_formatMenu->addAction(m_setLineSpacingAct);
    m_formatMenu->addAction(m_setParagraphSpacingAct);

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_aboutAct);
    m_helpMenu->addAction(m_aboutQtAct);
}
