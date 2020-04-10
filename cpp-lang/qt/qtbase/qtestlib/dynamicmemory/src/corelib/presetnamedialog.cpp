#include "presetnamedialog.h"

#include <QtWidgets>

PresetNameDialog::PresetNameDialog(const QStringList &unavailableNames, QWidget *parent)
    : QDialog(parent),
      _buttonBox(0),
      _lineEdit(0),
      _warningLabel(0),
      _unavailableNames(unavailableNames)
{
    // make widgets:
    _buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    _buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    _lineEdit = new QLineEdit;
    _lineEdit->setPlaceholderText("Type name");
    _lineEdit->setMaxLength(NameMaxLength);

    _warningLabel = new QLabel;

    // make connections:
    connect(_buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(_buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    connect(_lineEdit, &QLineEdit::textChanged, this, &PresetNameDialog::presetNameChanged);

    // make layout:
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("Preset:"), 0, 0, 1, 1);
    mainLayout->addWidget(_lineEdit, 0, 1, 1, 1);
    mainLayout->addWidget(_warningLabel, 1, 1, 1, 1);

    auto verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addItem(verticalSpacer, 2, 0);

    QFrame *frame  = new QFrame;
    frame->setFrameShape(QFrame::HLine);
    frame->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(frame, 3, 0, 1, 2);

    mainLayout->addWidget(_buttonBox, 4, 1, 1, 1);
    setLayout(mainLayout);

    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setWindowTitle(QStringLiteral("Set name"));
    setMinimumSize(370, 100);
}

PresetNameDialog::~PresetNameDialog()
{
}

QString PresetNameDialog::presetName() const
{
    return _lineEdit->text();
}

void PresetNameDialog::presetNameChanged(const QString &text)
{
    if (_unavailableNames.contains(text, Qt::CaseInsensitive))
    {
        showWarning("The name already exists.");
        _buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else if (text.contains("None", Qt::CaseInsensitive))
    {
        showWarning("Reserved word.");
        _buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else if (text.isEmpty())
    {
        showWarning("Name is empty");
        _buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
    else
    {
        hideWarning();
        _buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

void PresetNameDialog::showWarning(const QString &text) const
{
    _warningLabel->setStyleSheet("QLabel{background-color:yellow;}");
    _warningLabel->setText(text);
}

void PresetNameDialog::hideWarning() const
{
    _warningLabel->setStyleSheet(QString());
    _warningLabel->setText(QString());
}
