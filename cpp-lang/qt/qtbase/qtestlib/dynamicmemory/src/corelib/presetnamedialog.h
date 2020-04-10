#ifndef PRESETNAMEDIALOG_H
#define PRESETNAMEDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class QLineEdit;
class QLabel;
class PresetNameDialog : public QDialog
{
    Q_OBJECT

public:
    PresetNameDialog(const QStringList &unavailableNames, QWidget *parent = 0);
    ~PresetNameDialog();

    QString presetName() const;

private slots:
    void presetNameChanged(const QString &text);

private:
    enum { NameMaxLength = 16 };

    void showWarning(const QString &) const;
    void hideWarning() const;

    QDialogButtonBox *_buttonBox;
    QLineEdit *_lineEdit;
    QLabel *_warningLabel;
    QStringList _unavailableNames;
};

#endif // PRESETNAMEDIALOG_H
