#include "findfiledialog.h"
#include "textedit.h"
#include "assistant.h"

#include <QtWidgets>

FindFileDialog::FindFileDialog(TextEdit *editor, Assistant *assistant)
    : QDialog(editor),
      _currentAssistant(assistant),
      _currentTextEdit(editor),
      _foundFilesTree(Q_NULLPTR),
      _directoryComboBox(Q_NULLPTR),
      _fileNameComboBox(Q_NULLPTR),
      _directoryLabel(Q_NULLPTR),
      _fileNameLabel(Q_NULLPTR),
      _buttonBox(Q_NULLPTR),
      _browseButton(Q_NULLPTR)
{
    createButtons();
    createComboBoxes();
    createFilesTree();
    createLabels();
    createLayout();

    _directoryComboBox->addItem(QDir::toNativeSeparators(QDir::currentPath()));
    _fileNameComboBox->addItem("*");
    findFiles();

    setWindowTitle(tr("Find File"));
}

void FindFileDialog::browse()
{
    QString currentDirectory = _directoryComboBox->currentText();
    QString newDirectory = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                             currentDirectory);
    if (!newDirectory.isEmpty()) {
        _directoryComboBox->addItem(QDir::toNativeSeparators(newDirectory));
        _directoryComboBox->setCurrentIndex(_directoryComboBox->count() - 1);
        update();
    }
}

void FindFileDialog::help()
{
    _currentAssistant->showDocumentation("filedialog.html");
}

void FindFileDialog::openFile(QTreeWidgetItem *item)
{
    if (!item) {
        item = _foundFilesTree->currentItem();
        if (!item)
            return;
    }

    QString fileName = item->text(0);
    QString path = _directoryComboBox->currentText() + QDir::separator();

    _currentTextEdit->setContents(path + fileName);
    close();
}

void FindFileDialog::update()
{
    findFiles();
    _buttonBox->button(QDialogButtonBox::Open)->setEnabled(
                _foundFilesTree->topLevelItemCount() > 0);
}

void FindFileDialog::findFiles()
{
    QRegExp filePattern(_fileNameComboBox->currentText() + "*");
    filePattern.setPatternSyntax(QRegExp::Wildcard);

    QDir directory(_directoryComboBox->currentText());

    QStringList allFiles = directory.entryList(QDir::Files | QDir::NoSymLinks);
    QStringList matchFiles;

    foreach (QString file, allFiles) {
        if (filePattern.exactMatch(file))
            matchFiles << file;
    }
    showFiles(matchFiles);
}

void FindFileDialog::showFiles(const QStringList &files)
{
    _foundFilesTree->clear();

    for (int i = 0; i < files.count(); ++i) {
        QTreeWidgetItem *item = new QTreeWidgetItem(_foundFilesTree);
        item->setText(0, files[i]);
    }

    if (files.count() > 0)
        _foundFilesTree->setCurrentItem(_foundFilesTree->topLevelItem(0));
}

void FindFileDialog::createButtons()
{
    _browseButton = new QToolButton;
    _browseButton->setText(tr("..."));
    connect(_browseButton, SIGNAL(clicked()), this, SLOT(browse()));

    _buttonBox = new QDialogButtonBox(QDialogButtonBox::Open
                                      | QDialogButtonBox::Cancel
                                      | QDialogButtonBox::Help);
    connect(_buttonBox, SIGNAL(accepted()), this, SLOT(openFile()));
    connect(_buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(_buttonBox, SIGNAL(helpRequested()), this, SLOT(help()));
}

void FindFileDialog::createComboBoxes()
{
    _directoryComboBox = new QComboBox;
    _fileNameComboBox = new QComboBox;

    _fileNameComboBox->setEditable(true);
    _fileNameComboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    _directoryComboBox->setMinimumContentsLength(30);
    _directoryComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    _directoryComboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(_fileNameComboBox, SIGNAL(editTextChanged(QString)), this, SLOT(update()));
    connect(_directoryComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(update()));
}

void FindFileDialog::createFilesTree()
{
    _foundFilesTree = new QTreeWidget;
    _foundFilesTree->setColumnCount(1);
    _foundFilesTree->setHeaderLabels(QStringList(tr("Matching Files")));
    _foundFilesTree->setRootIsDecorated(false);
    _foundFilesTree->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(_foundFilesTree, SIGNAL(itemActivated(QTreeWidgetItem*,int)),
            this, SLOT(openFile(QTreeWidgetItem*)));
}

void FindFileDialog::createLabels()
{
    _directoryLabel = new QLabel(tr("Search in:"));
    _fileNameLabel = new QLabel(tr("File name (including wildcards):"));
}

void FindFileDialog::createLayout()
{
    QHBoxLayout *fileLayout = new QHBoxLayout;
    fileLayout->addWidget(_fileNameLabel);
    fileLayout->addWidget(_fileNameComboBox);

    QHBoxLayout *directoryLayout = new QHBoxLayout;
    directoryLayout->addWidget(_directoryLabel);
    directoryLayout->addWidget(_directoryComboBox);
    directoryLayout->addWidget(_browseButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(fileLayout);
    mainLayout->addLayout(directoryLayout);
    mainLayout->addWidget(_foundFilesTree);
    mainLayout->addStretch();
    mainLayout->addWidget(_buttonBox);
    setLayout(mainLayout);

}
