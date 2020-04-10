// FileBufferDialog.cpp

#include <QGridLayout>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QPushButton>
#include <QFileDialog>
#include "Saver.h"
#include "FileBufferDialog.h"

FileBufferDialog::FileBufferDialog() : QDialog( 0 )
{   
    // button box:
    QDialogButtonBox *box = new QDialogButtonBox( Qt::Vertical );
    m_saveButton = new QPushButton( "Save..." );
    box->addButton( m_saveButton, QDialogButtonBox::AcceptRole );
    m_deleteButton = new QPushButton( "Delete" );
    box->addButton( m_deleteButton, QDialogButtonBox::AcceptRole );
    m_clearButton = new QPushButton( "Clear" );
    box->addButton( m_clearButton, QDialogButtonBox::AcceptRole );

    // widgets location:
    QGridLayout *layout = new QGridLayout( this );
    layout->addWidget( m_list = new FileListWidget( this ), 0, 0 );
    layout->addWidget( box, 0, 1 );

    // connection made:
    connect( m_clearButton, SIGNAL(clicked()), this, SLOT(clearItems()) );
    connect( m_deleteButton, SIGNAL(clicked()), this, SLOT(deleteItem()) );
    connect( m_saveButton, SIGNAL(clicked()), this, SLOT(saveItem()) );
}

void FileBufferDialog::clearItems()
{
    m_list->clear();
}

void FileBufferDialog::deleteItem()
{
    delete m_list->currentItem();
}

void FileBufferDialog::saveItem()
{
    if ( !m_list->currentItem() )
        m_list->setNewCurrentItem();
    QString dirName = openDir( this ) + "/";
    while ( m_list->count() != 0 && (!dirName.isNull()) ) {
        Saver s;
        s.save( m_list->currentItem()->text(), dirName );
        deleteItem();
    }
}

QString FileBufferDialog::openDir( FileBufferDialog *parent )
{
    QString result = QFileDialog::getExistingDirectory(
                parent,
                QObject::tr( "Select a directory" ),
                QDir::currentPath() );
    return result;
}
