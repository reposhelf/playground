#include "printpanel.h"

#include <QtWidgets>

PrintPanel::PrintPanel(QWidget *parent)
    : QWidget(parent),
      m_twoSidedGroupBox(Q_NULLPTR),
      m_colorsGroupBox(Q_NULLPTR),
      m_twoSidedEnabledRadio(Q_NULLPTR),
      m_twoSidedDisabledRadio(Q_NULLPTR),
      m_colorsEnabledRadio(Q_NULLPTR),
      m_colorsDisabledRadio(Q_NULLPTR)
{

    QLabel *label = new QLabel(tr("<b>TROLL PRINT</b>"));
    label->setAlignment(Qt::AlignCenter);


    m_twoSidedGroupBox = new QGroupBox(tr("Two-sided"));
    m_twoSidedEnabledRadio = new QRadioButton(tr("Enabled", "two-sided"));
    m_twoSidedDisabledRadio = new QRadioButton(tr("Disabled", "two-sided"));
    m_twoSidedDisabledRadio->setChecked(true);

    m_colorsGroupBox = new QGroupBox(tr("Colors"));
    m_colorsEnabledRadio = new QRadioButton(tr("Enabled", "colors"));
    m_colorsDisabledRadio = new QRadioButton(tr("Disabled", "colors"));
    m_colorsDisabledRadio->setChecked(true);

    QHBoxLayout *twoSidedLayout = new QHBoxLayout;
    twoSidedLayout->addWidget(m_twoSidedEnabledRadio);
    twoSidedLayout->addWidget(m_twoSidedDisabledRadio);
    m_twoSidedGroupBox->setLayout(twoSidedLayout);

    QHBoxLayout *colorsLayout = new QHBoxLayout;
    colorsLayout->addWidget(m_colorsEnabledRadio);
    colorsLayout->addWidget(m_colorsDisabledRadio);
    m_colorsGroupBox->setLayout(colorsLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(label);
    mainLayout->addWidget(m_twoSidedGroupBox);
    mainLayout->addWidget(m_colorsGroupBox);
    setLayout(mainLayout);
}
