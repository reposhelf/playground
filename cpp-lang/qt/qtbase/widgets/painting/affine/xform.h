#ifndef XFORM_H
#define XFORM_H

#include "arthurwidgets.h"

#include <QBasicTimer>
#include <QPolygonF>

class HoverPoints;
class QLineEdit;
class XFormView : public ArthurFrame
{
    Q_OBJECT
    Q_PROPERTY(XFormType type READ type WRITE setType)
    Q_PROPERTY(bool animation READ animation WRITE setAnimation)
    Q_PROPERTY(qreal shear READ shear WRITE setShear)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap)
    Q_ENUMS(XFormType)

public:
    enum XFormType { VectorType, PixmapType, TextType };

    XFormView(QWidget *parent);
    void paint(QPainter *) Q_DECL_OVERRIDE;
    void drawVectorType(QPainter *);
    void drawPixmapType(QPainter *);
    void drawTextType(QPainter *);

    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE;
    HoverPoints *hoverPoints() const { return m_points; }

    XFormType type() const { return m_type; }
    void setType(XFormType t);

    bool animation() const { return m_timer.isActive(); }
    void setAnimation(bool animate);

    qreal shear() const { return m_shear; }
    void setShear(qreal s);

    qreal scale() const { return m_scale; }
    void setScale(qreal s);

    qreal rotation() const { return m_rotation; }
    void setRotation(qreal r);

    QString text() const { return m_text; }
    void setText(const QString &t);

    QPixmap pixmap() const { return m_pixmap; }
    void setPixmap(const QPixmap &p);

public slots:
    void updateCtrlPoints(const QPolygonF &);
    void changeRotation(int r);
    void changeScale(int s);
    void changeShear(int s);

    void setVectorType();
    void setPixmapType();
    void setTextType();
    void reset();

signals:
    void rotationChanged(int);
    void scaleChanged(int);
    void shearChanged(int);

protected:
    void timerEvent(QTimerEvent *);
    void wheelEvent(QWheelEvent *);

private:
    XFormType m_type;
    QBasicTimer m_timer;
    qreal m_shear;
    qreal m_scale;
    qreal m_rotation;
    QString m_text;
    QPixmap m_pixmap;
    HoverPoints *m_points;
    QPolygonF m_ctrlPoints;
};

class XFormWidget : public QWidget
{
    Q_OBJECT

public:
    XFormWidget(QWidget *parent);

private:
    XFormView *m_view;
    QLineEdit *m_textEditor;
};

#endif // XFORM_H
