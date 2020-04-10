// FileListWidget.cpp
#include "FileListWidget.h"
#include <QApplication>

#include <QDebug>

FileListWidget::FileListWidget( QWidget *parent ) :
    QListWidget( parent )
{    
    setAcceptDrops         ( true );
    setSelectionMode       ( QAbstractItemView::ExtendedSelection );
    setDropIndicatorShown  ( true );
    setDragDropMode        ( QAbstractItemView::DragDrop );
    setAlternatingRowColors( true );
    setWrapping            ( true );
    setDefaultDropAction   ( Qt::CopyAction );
}

void FileListWidget::dragEnterEvent( QDragEnterEvent *e )
{
    if ( e->source() != this )
        if ( e->mimeData()->hasUrls() )
            e->acceptProposedAction();
}

void FileListWidget::dropEvent( QDropEvent *e )
{
    if ( e->mimeData()->hasUrls() ) {
        QList<QUrl> urls = e->mimeData()->urls();
        foreach ( QUrl url, urls )
            m_newCurrentItem = ( new QListWidgetItem(url.toLocalFile(), this) );
        e->setDropAction( Qt::CopyAction );
        e->accept();
    }
}

void FileListWidget::mousePressEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton )
        m_startPos = e->pos();
    QListWidget::mousePressEvent( e );
}

void FileListWidget::mouseMoveEvent(QMouseEvent *e)
{
    if ( e->buttons() & Qt::LeftButton ) {
        int distance = ( e->pos() - m_startPos ).manhattanLength();
        if ( distance >= QApplication::startDragDistance() )
            startDrag();
    }
}

void FileListWidget::startDrag()
{
    QList<QListWidgetItem*> items = selectedItems();
    QListWidgetItem *item = 0;
    QList<QUrl> listUrls;
    for ( int i = 0; i < items.size(); i++ ) {
        item = items.at( i );
        if ( item ) {
            QFileInfo fi( item->text() );
            listUrls << QUrl::fromLocalFile( fi.absoluteFilePath() );
        }
    }
    if ( item ) {
        QMimeData *mime = new QMimeData;
        mime->setUrls( listUrls );
        QDrag *drag = new QDrag( this );
        drag->setMimeData( mime );
        if ( drag->exec(Qt::CopyAction) == Qt::CopyAction )
            for ( int i = 0; i < items.size(); i++ )
                delete items[i];
    }
}

void FileListWidget::dragMoveEvent( QDragMoveEvent *e )
{
    if ( e->mimeData()->hasUrls() )
        e->acceptProposedAction();
}

void FileListWidget::setNewCurrentItem()
{
    setCurrentItem( m_newCurrentItem );
}
