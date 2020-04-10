#include <QTime>
#include "drawdialog.h"

// constructor()

DrawDialog::DrawDialog(QWidget *parent)
    :QDialog(parent)
{
    setupUi(this);
    connect(generateButton, SIGNAL(clicked()), this, SLOT(generate()));
}

// generate()

void DrawDialog::generate()
{
    if (qualificationRadioButton->isChecked()) {
        qualificationInit();
        qualificationGenerate();
    } else {
        return;
    }
}

// qualificationInit()

void DrawDialog::qualificationInit()
{
    m_teams.insert("England", 5);
    m_teams.insert("Spain", 5);
    m_teams.insert("France", 5);
    m_teams.insert("Germany", 5);
    m_teams.insert("Holland", 5);
    m_teams.insert("Italy", 5);
    m_teams.insert("Portugal", 5);
    m_teams.insert("Croatia", 4);
    m_teams.insert("Greece", 4);
    m_teams.insert("Russia", 4);
    m_teams.insert("Czech Republic", 4);
    m_teams.insert("Switzerland", 4);
    m_teams.insert("Belgium", 2);
    m_teams.insert("Sweden", 2);
    m_teams.insert("Turkey", 2);
    m_teams.insert("Ireland", 2);
    m_teams.insert("Scotland", 2);
    m_teams.insert("Norway", 1);
    m_teams.insert("Poland", 1);
    m_teams.insert("Romania", 1);
    m_teams.insert("Slovenia", 1);
    m_teams.insert("Austria", 1);
    m_teams.insert("Bulgaria", 0);
    m_teams.insert("Denmark", 0);
    m_teams.insert("Finland", 0);
    m_teams.insert("Hungary", 0);
    m_teams.insert("Nothern Ireland", 0);
}

// qualificationGenerate()

void DrawDialog::qualificationGenerate()
{
    listWidget->clear();
    for (int i = 5; i >= 0; --i) {
        QMapIterator<QString, quint8> it(m_teams);
        QStringList teams;
        while (it.hasNext()) {
            it.next();
            if (it.value() == i)
                teams.append(it.key());
        }
        if (!teams.isEmpty())
            display(teams);
        else
            displayMyTeam();
    }
}

// display()

void DrawDialog::display(QStringList &teams)
{
    int randomNum = QTime::currentTime().hour()
            + QTime::currentTime().minute()
            + QTime::currentTime().second()
            + QTime::currentTime().msec();
    srand(randomNum);
    int choice = rand() % teams.count();
    listWidget->addItem(teams[choice]);
}

// display()

void DrawDialog::displayMyTeam()
{
    listWidget->addItem("Ukraine");
}
