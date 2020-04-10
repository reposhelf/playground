#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QTimer>

enum Direction {
    UP,
    DOWN
};

class Ball : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

public:
    Ball( QGraphicsScene *scene, QObject *object = 0, QGraphicsEllipseItem *parent = 0 );
    ~Ball();

    virtual void mousePressEvent( QGraphicsSceneMouseEvent *e );
    virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent *e );
    void bounce();

private slots:
    void move();

private:
    static const int       m_diameter = 40;
    static const double    m_bounceKoef = 0.6;
    static const int       m_step = 1;
    static const int       m_interval = 7;

    int             m_topLimit;
    int             m_bottomLimit;
    int             m_hgt;
    QTimer         *m_timer;
    Direction       m_direction;
    QGraphicsScene *m_scene;
};

#endif // BALL_H
