#include "signaturesdetector.h"
#include "scaner.h"
#include "animatedprogresswidget.h"

#include <QtWidgets>

//----------------------------------------------------SignaturesDetecrotPrivate

class SignaturesDetectorPrivate
{
public:
    SignaturesDetectorPrivate();
    ~SignaturesDetectorPrivate();

    QLineEdit *m_pathLineEdit;
    QPushButton *m_browseButton;
    QProgressBar *m_scanProgressBar;
    QFrame *m_progressFrame;
    QTextEdit *m_displayGuid;
    Scaner *m_scaner;
    AnimatedProgressWidget *m_animatedProgress;
    QTabWidget *m_tabWidget;

    static const int s_columnCount = 1;
    static const int s_spacing = 3;
    static const int s_leftMargin = 3;
    static const int s_topMargin = 3;
    static const int s_rightMargin = 3;
    static const int s_bottomMargin = 3;
    static const int s_progressMin = 0;
    static const int s_progressMax = 100;
};

SignaturesDetectorPrivate::SignaturesDetectorPrivate()
    : m_pathLineEdit(new QLineEdit),
      m_browseButton(new QPushButton),
      m_scanProgressBar(new QProgressBar),
      m_progressFrame(new QFrame),
      m_displayGuid(new QTextEdit),
      m_scaner(new Scaner),
      m_animatedProgress(new AnimatedProgressWidget),
      m_tabWidget(new QTabWidget)
{
        m_pathLineEdit->setReadOnly(true);

        m_browseButton->setText("Browse...");

        m_scanProgressBar->setMinimum(s_progressMin);
        m_scanProgressBar->setMaximum(s_progressMax);
        m_scanProgressBar->setValue(s_progressMin);

        m_progressFrame->hide();

        m_displayGuid->setReadOnly(true);

        m_tabWidget->setTabPosition(QTabWidget::South);
        m_tabWidget->addTab(m_displayGuid, QObject::tr("GUID"));
}

SignaturesDetectorPrivate::~SignaturesDetectorPrivate()
{
//    if (m_scaner) {
//        m_scaner->wait();
//        delete m_scaner;
//        m_scaner = 0;
//    }
    delete m_scaner;
}

//-----------------------------------------------------------SignaturesDetecror

QSize SignaturesDetector::s_defaultSize = QSize(640, 480);

SignaturesDetector::SignaturesDetector(QWidget *parent)
    : QWidget(parent),
      d(new SignaturesDetectorPrivate)
{
    makeLayouts();
    makeConnections();

    resize(s_defaultSize);
    setWindowTitle("Signatures Detector");
    setWindowIcon(makeWindowIcon());
}

SignaturesDetector::~SignaturesDetector()
{
    delete d;
}

void SignaturesDetector::closeEvent(QCloseEvent *event)
{
    if (d->m_scaner && d->m_scaner->isRunning()) {
        aboutToClose() ? event->accept() : event->ignore();
    }
}

void SignaturesDetector::onBrowseButtonClicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Choose Directory"),
                                                     QDir::homePath(), QFileDialog::ShowDirsOnly);

    if (!path.isEmpty()) {
        // show progress control:
        d->m_progressFrame->show();
        d->m_animatedProgress->startProgress();

        // scan path:
        d->m_pathLineEdit->setText(path);
        d->m_scaner->setPath(path);
        d->m_scaner->start();

        // clear previous result:
        d->m_displayGuid->clear();
    }
}

void SignaturesDetector::onScanningFinished()
{
    d->m_scanProgressBar->setValue(d->s_progressMin);
    d->m_animatedProgress->stopProgress();
    d->m_progressFrame->hide();
}

void SignaturesDetector::makeLayouts()
{
    // make layout for the line edit and button:
    QGroupBox *scanningArea = new QGroupBox(tr("Scanning area"));
    scanningArea->setLayout(new QBoxLayout(QBoxLayout::LeftToRight));
    scanningArea->layout()->addWidget(d->m_pathLineEdit);
    scanningArea->layout()->addWidget(d->m_browseButton);
    scanningArea->layout()->setSpacing(d->s_spacing);
    scanningArea->layout()->setContentsMargins(
                d->s_leftMargin, d->s_topMargin, d->s_rightMargin, d->s_bottomMargin);

    // make layout for the progress bar:
    d->m_progressFrame->setLayout(new QBoxLayout(QBoxLayout::TopToBottom));
    d->m_progressFrame->layout()->addWidget(d->m_scanProgressBar);
    d->m_progressFrame->layout()->addWidget(d->m_animatedProgress);
    d->m_progressFrame->layout()->setSpacing(d->s_spacing);
    d->m_progressFrame->layout()->setContentsMargins(
                d->s_leftMargin, d->s_topMargin, d->s_rightMargin, d->s_bottomMargin);

    // make layout for the main widget:
    setLayout(new QVBoxLayout());
    layout()->addWidget(scanningArea);
    layout()->addWidget(d->m_progressFrame);
    layout()->addWidget(d->m_tabWidget);
    layout()->setContentsMargins(
                d->s_leftMargin, d->s_topMargin, d->s_rightMargin, d->s_bottomMargin);
}

void SignaturesDetector::makeConnections()
{
    connect(d->m_browseButton, SIGNAL(clicked()), this, SLOT(onBrowseButtonClicked()));
    connect(d->m_scaner, SIGNAL(finished()), this, SLOT(onScanningFinished()));
    connect(d->m_scaner, SIGNAL(scanningProgressChanged(int)),
            d->m_scanProgressBar, SLOT(setValue(int)));
    connect(d->m_scaner, SIGNAL(guidDetected(QString)),
            d->m_displayGuid, SLOT(append(QString)));
}

QIcon SignaturesDetector::makeWindowIcon() const
{
    QIcon icon;
    icon.addFile(":/img/16x16/main_icon.png");
    icon.addFile(":/img/32x32/main_icon.png");
    return icon;
}

bool SignaturesDetector::aboutToClose()
{
    QMessageBox box(this);
    QPushButton *closeAnyway = box.addButton(tr("Cancel Scan && Close"),
                                             QMessageBox::AcceptRole);
    QPushButton *cancelClose = box.addButton(tr("Do Not Close"),
                                             QMessageBox::RejectRole);
    box.setDefaultButton(cancelClose);
    box.setWindowTitle(tr("Close the Application?"));
    box.setText(QString("The application is currently executed"));
    box.setInformativeText(tr("If you close the application it can lead "
                              "to data corruption. Do you want to cancel the execute "
                              "process and close the application anyway?"));
    box.exec();
    if (box.clickedButton() != closeAnyway)
        return false;

    return true;
}
