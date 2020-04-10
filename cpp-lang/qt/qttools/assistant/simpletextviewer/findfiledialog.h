#ifndef FINDFILEDIALOG_H
#define FINDFILEDIALOG_H

#include <QDialog>

class QTreeWidgetItem;
class QComboBox;
class QDialogButtonBox;
class QLabel;
class QToolButton;
class QTreeWidget;

class Assistant;
class TextEdit;

class FindFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindFileDialog(TextEdit *editor, Assistant *assistant);

private slots:
    void browse();
    void help();
    void openFile(QTreeWidgetItem *item = Q_NULLPTR);
    void update();

private:
    void findFiles();
    void showFiles(const QStringList &files);

    void createButtons();
    void createComboBoxes();
    void createFilesTree();
    void createLabels();
    void createLayout();

    Assistant *_currentAssistant;
    TextEdit *_currentTextEdit;

    QTreeWidget *_foundFilesTree;

    QComboBox *_directoryComboBox;
    QComboBox *_fileNameComboBox;

    QLabel *_directoryLabel;
    QLabel *_fileNameLabel;

    QDialogButtonBox *_buttonBox;

    QToolButton *_browseButton;
};

#endif // FINDFILEDIALOG_H
