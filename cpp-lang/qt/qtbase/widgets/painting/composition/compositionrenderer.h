#ifndef COMPOSITIONRENDERER_H
#define COMPOSITIONRENDERER_H

#include "arthurwidgets.h"

class QGLPixelBuffer;
class CompositionRenderer : public ArthurFrame
{
    Q_OBJECT
    Q_PROPERTY(int circleColor READ circleColor WRITE setCircleColor)
    Q_PROPERTY(int circleAlpha READ circleAlpha WRITE setCircleAlpha)
    Q_PROPERTY(bool animationEnabled READ animationEnabled WRITE setAnimationEnabled)

    enum ObjectType { NoObject, Circle, Rectangle, Image };

public:
    CompositionRenderer(QWidget *parent = Q_NULLPTR);

    QSize sizeHint() const Q_DECL_OVERRIDE { return QSize(500, 400); }

    int circleColor() const { return m_circleColor; }
    int circleAlpha() const { return m_circleAlpha; }
    bool animationEnabled() const { return m_animationEnabled; }

    void setCirclePos(const QPointF &pos);

public slots:
    void setCircleColor(int circleColor);
    void setCircleAlpha(int circleAlpha);
    void setAnimationEnabled(bool animationEnabled);

    void setClearMode();
    void setSourceMode();
    void setDestMode();
    void setSourceOverMode();
    void setDestOverMode();
    void setSourceInMode();
    void setDestInMode();
    void setSourceOutMode();
    void setDestOutMode();
    void setSourceAtopMode();
    void setDestAtopMode();
    void setXorMode();

    void setPlusMode();
    void setMultiplyMode();
    void setScreenMode();
    void setOverlayMode();
    void setDarkenMode();
    void setLightenMode();
    void setColorDodgeMode();
    void setColorBurnMode();
    void setHardLightMode();
    void setSoftLightMode();
    void setDifferenceMode();
    void setExclusionMode();

protected:
    void paint(QPainter *painter) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    void updateCirclePos();
    void drawBase(QPainter &painter);
    void drawSource(QPainter &painter);

    int m_circleColor;
    int m_circleAlpha;
    bool m_animationEnabled;
    int m_animationTimer;

    QPainter::CompositionMode m_compositionMode;
    ObjectType m_currentObject;

    QImage m_image;
    QImage m_buffer;
    QImage m_baseBuffer;

    QPointF m_circlePos;
    QPointF m_offset;

#ifdef QT_OPENGL_SUPPORT
    QGLPixelBuffer *m_pbuffer;
    GLuint m_baseTex;
    GLuint m_compositingTex;
    int m_pbufferSize;
    QSize m_previousSize;
#endif
};

#endif // COMPOSITIONRENDERER_H
