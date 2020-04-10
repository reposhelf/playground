#include "compositionrenderer.h"

#include <QtWidgets>
#include <QGLPixelBuffer>

const int ANIMATION_INTERVAL = 15;

QRectF rectangleAround(const QPointF &pos, const QSize &size = QSize(250, 200))
{
    QRectF rect(pos, size);
    rect.translate(-size.width() / 2, -size.height() / 2);
    return rect;
}

CompositionRenderer::CompositionRenderer(QWidget *parent)
    : ArthurFrame(parent),
      m_circleColor(255),
      m_circleAlpha(127),
      m_animationEnabled(true),
      m_animationTimer(startTimer(ANIMATION_INTERVAL)),
      m_compositionMode(QPainter::CompositionMode_SourceOut),
      m_currentObject(NoObject),
      m_image(QImage(":/flower.jpg")),
      m_buffer(),
      m_baseBuffer(),
      m_circlePos(QPointF(200, 100)),
      m_offset()
{
#ifdef QT_OPENGL_SUPPORT
    m_pbuffer = Q_NULLPTR;
    m_pbufferSize = 1024;
#endif

    m_image.setAlphaChannel(QImage(":/flower_alpha.jpg"));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void CompositionRenderer::setCirclePos(const QPointF &pos)
{
    const QRect oldRect = rectangleAround(m_circlePos).toAlignedRect();
    m_circlePos = pos;
    const QRect newRect = rectangleAround(m_circlePos).toAlignedRect();
#if defined(USE_OPENGL) && !defined(QT_OPENGL_ES)
    if (usesOpenGL()) {
        update();
        return;
    }
#endif
    update(oldRect | newRect);
}

void CompositionRenderer::setCircleColor(int circleColor)
{
    m_circleColor = circleColor;
    update();
}

void CompositionRenderer::setCircleAlpha(int circleAlpha)
{
    m_circleAlpha = circleAlpha;
    update();
}

void CompositionRenderer::setAnimationEnabled(bool animationEnabled)
{
    if (m_animationEnabled == animationEnabled)
        return;

    m_animationEnabled = animationEnabled;

    if (m_animationEnabled) {
        Q_ASSERT(!m_animationTimer);
        m_animationTimer = startTimer(ANIMATION_INTERVAL);
    } else {
        killTimer(m_animationTimer);
        m_animationTimer = 0;
    }
}

void CompositionRenderer::setClearMode()
{
    m_compositionMode = QPainter::CompositionMode_Clear;
    update();
}

void CompositionRenderer::setSourceMode()
{
    m_compositionMode = QPainter::CompositionMode_Source;
    update();
}

void CompositionRenderer::setDestMode()
{
    m_compositionMode = QPainter::CompositionMode_Destination;
    update();
}

void CompositionRenderer::setSourceOverMode()
{
    m_compositionMode = QPainter::CompositionMode_SourceOver;
    update();
}

void CompositionRenderer::setDestOverMode()
{
    m_compositionMode = QPainter::CompositionMode_DestinationOver;
    update();
}

void CompositionRenderer::setSourceInMode()
{
    m_compositionMode = QPainter::CompositionMode_SourceIn;
    update();
}

void CompositionRenderer::setDestInMode()
{
    m_compositionMode = QPainter::CompositionMode_DestinationIn;
    update();
}

void CompositionRenderer::setSourceOutMode()
{
    m_compositionMode = QPainter::CompositionMode_SourceOut;
    update();
}

void CompositionRenderer::setDestOutMode()
{
    m_compositionMode = QPainter::CompositionMode_DestinationOut;
    update();
}

void CompositionRenderer::setSourceAtopMode()
{
    m_compositionMode = QPainter::CompositionMode_SourceAtop;
    update();
}

void CompositionRenderer::setDestAtopMode()
{
    m_compositionMode = QPainter::CompositionMode_DestinationAtop;
    update();
}

void CompositionRenderer::setXorMode()
{
    m_compositionMode = QPainter::CompositionMode_Xor;
    update();
}

void CompositionRenderer::setPlusMode()
{
    m_compositionMode = QPainter::CompositionMode_Plus;
    update();
}

void CompositionRenderer::setMultiplyMode()
{
    m_compositionMode = QPainter::CompositionMode_Multiply;
    update();
}

void CompositionRenderer::setScreenMode()
{
    m_compositionMode = QPainter::CompositionMode_Screen;
    update();
}

void CompositionRenderer::setOverlayMode()
{
    m_compositionMode = QPainter::CompositionMode_Overlay;
    update();
}

void CompositionRenderer::setDarkenMode()
{
    m_compositionMode = QPainter::CompositionMode_Darken;
    update();
}

void CompositionRenderer::setLightenMode()
{
    m_compositionMode = QPainter::CompositionMode_Lighten;
    update();
}

void CompositionRenderer::setColorDodgeMode()
{
    m_compositionMode = QPainter::CompositionMode_ColorDodge;
    update();
}

void CompositionRenderer::setColorBurnMode()
{
    m_compositionMode = QPainter::CompositionMode_ColorBurn;
    update();
}

void CompositionRenderer::setHardLightMode()
{
    m_compositionMode = QPainter::CompositionMode_HardLight;
    update();
}

void CompositionRenderer::setSoftLightMode()
{
    m_compositionMode = QPainter::CompositionMode_SoftLight;
    update();
}

void CompositionRenderer::setDifferenceMode()
{
    m_compositionMode = QPainter::CompositionMode_Difference;
    update();
}

void CompositionRenderer::setExclusionMode()
{
    m_compositionMode = QPainter::CompositionMode_Exclusion;
    update();
}

void CompositionRenderer::paint(QPainter *painter)
{
#if defined(USE_OPENGL) && !defined(QT_OPENGL_ES)
    if (usesOpenGL()) {

        int new_pbuf_size = m_pbufferSize;
        if (size().width() > m_pbufferSize || size().height() > m_pbufferSize)
            new_pbuf_size *= 2;

        if (size().width() < m_pbufferSize/2 && size().height() < m_pbufferSize/2)
            new_pbuf_size /= 2;

        if (!m_pbuffer || new_pbuf_size != m_pbufferSize) {
            if (m_pbuffer) {
                m_pbuffer->deleteTexture(m_baseTex);
                m_pbuffer->deleteTexture(m_compositingTex);
                delete m_pbuffer;
            }

            m_pbuffer = new QGLPixelBuffer(QSize(new_pbuf_size, new_pbuf_size), QGLFormat::defaultFormat(), glWidget());
            m_pbuffer->makeCurrent();
            m_baseTex = m_pbuffer->generateDynamicTexture();
            m_compositingTex = m_pbuffer->generateDynamicTexture();
            m_pbufferSize = new_pbuf_size;
        }

        if (size() != m_previousSize) {
            m_previousSize = size();
            QPainter p(m_pbuffer);
            p.setCompositionMode(QPainter::CompositionMode_Source);
            p.fillRect(QRect(0, 0, m_pbuffer->width(), m_pbuffer->height()), Qt::transparent);
            drawBase(p);
            p.end();
            m_pbuffer->updateDynamicTexture(m_baseTex);
        }

        qreal x_fraction = width()/float(m_pbuffer->width());
        qreal y_fraction = height()/float(m_pbuffer->height());

        {
            QPainter p(m_pbuffer);
            p.setCompositionMode(QPainter::CompositionMode_Source);
            p.fillRect(QRect(0, 0, m_pbuffer->width(), m_pbuffer->height()), Qt::transparent);

            p.save(); // Needed when using the GL1 engine
            p.beginNativePainting(); // Needed when using the GL2 engine

            glBindTexture(GL_TEXTURE_2D, m_baseTex);
            glEnable(GL_TEXTURE_2D);
            glColor4f(1.,1.,1.,1.);

            glBegin(GL_QUADS);
            {
                glTexCoord2f(0, 1.0);
                glVertex2f(0, 0);

                glTexCoord2f(x_fraction, 1.0);
                glVertex2f(width(), 0);

                glTexCoord2f(x_fraction, 1.0-y_fraction);
                glVertex2f(width(), height());

                glTexCoord2f(0, 1.0-y_fraction);
                glVertex2f(0, height());
            }
            glEnd();

            glDisable(GL_TEXTURE_2D);

            p.endNativePainting(); // Needed when using the GL2 engine
            p.restore(); // Needed when using the GL1 engine

            drawSource(p);
            p.end();
            m_pbuffer->updateDynamicTexture(m_compositingTex);
        }

        painter->beginNativePainting(); // Needed when using the GL2 engine
        glWidget()->makeCurrent(); // Needed when using the GL1 engine
        glBindTexture(GL_TEXTURE_2D, m_compositingTex);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(1.,1.,1.,1.);
        glBegin(GL_QUADS);
        {
            glTexCoord2f(0, 1.0);
            glVertex2f(0, 0);

            glTexCoord2f(x_fraction, 1.0);
            glVertex2f(width(), 0);

            glTexCoord2f(x_fraction, 1.0-y_fraction);
            glVertex2f(width(), height());

            glTexCoord2f(0, 1.0-y_fraction);
            glVertex2f(0, height());
        }
        glEnd();
        glDisable(GL_TEXTURE_2D);
        painter->endNativePainting(); // Needed when using the GL2 engine
    } else
#endif
    {
        // using a QImage
        if (m_buffer.size() != size()) {
            m_buffer = QImage(size(), QImage::Format_ARGB32_Premultiplied);
            m_baseBuffer = QImage(size(), QImage::Format_ARGB32_Premultiplied);

            m_baseBuffer.fill(0);

            QPainter p(&m_baseBuffer);

            drawBase(p);
        }

        memcpy(m_buffer.bits(), m_baseBuffer.bits(), m_buffer.byteCount());

        {
            QPainter p(&m_buffer);
            drawSource(p);
        }

        painter->drawImage(0, 0, m_buffer);
    }
}

void CompositionRenderer::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_animationTimer)
        updateCirclePos();
}

void CompositionRenderer::mousePressEvent(QMouseEvent *event)
{
    setDescriptionEnabled(false);

    QRectF circle = rectangleAround(m_circlePos);

    if (circle.contains(event->pos())) {
        m_currentObject = Circle;
        m_offset = circle.center() - event->pos();
    } else {
        m_currentObject = NoObject;
    }
    if (m_animationEnabled) {
        killTimer(m_animationTimer);
        m_animationTimer = 0;
    }
}

void CompositionRenderer::mouseMoveEvent(QMouseEvent *event)
{
    if (m_currentObject == Circle)
        setCirclePos(event->pos() + m_offset);
}

void CompositionRenderer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    m_currentObject = NoObject;

    if (m_animationEnabled) {
        Q_ASSERT(!m_animationTimer);
        m_animationTimer = startTimer(ANIMATION_INTERVAL);
    }
}

void CompositionRenderer::updateCirclePos()
{
    if (m_currentObject != NoObject)
        return;

    QDateTime dt = QDateTime::currentDateTime();
    qreal t = (dt.toTime_t() * 1000 + dt.time().msec()) / 1000.0;

    qreal x = width() / qreal(2) + (qCos(t * 8 / 11) + qSin(-t)) * width() / qreal(4);
    qreal y = height() / qreal(2) + (qSin(t * 6 / 7) + qCos(t * qreal(1.5))) * height() / qreal(4);

    setCirclePos(QLineF(m_circlePos, QPointF(x, y)).pointAt(0.02));
}

void CompositionRenderer::drawBase(QPainter &painter)
{
    painter.setPen(Qt::NoPen);

    QLinearGradient rectGradient(0, 0, 0, height());
    rectGradient.setColorAt(0, Qt::red);
    rectGradient.setColorAt(.17, Qt::yellow);
    rectGradient.setColorAt(.33, Qt::green);
    rectGradient.setColorAt(.50, Qt::cyan);
    rectGradient.setColorAt(.66, Qt::blue);
    rectGradient.setColorAt(.81, Qt::magenta);
    rectGradient.setColorAt(1, Qt::red);
    painter.setBrush(rectGradient);
    painter.drawRect(width() / 2, 0, width() / 2, height());

    QLinearGradient alphaGradient(0, 0, width(), 0);
    alphaGradient.setColorAt(0, Qt::white);
    alphaGradient.setColorAt(.2, Qt::white);
    alphaGradient.setColorAt(.5, Qt::transparent);
    alphaGradient.setColorAt(.8, Qt::white);
    alphaGradient.setColorAt(1, Qt::white);

    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.setBrush(alphaGradient);
    painter.drawRect(0, 0, width(), height());

    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);

    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.drawImage(rect(), m_image);
}

void CompositionRenderer::drawSource(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setCompositionMode(m_compositionMode);

    QRectF circleRect = rectangleAround(m_circlePos);
    QColor color = QColor::fromHsvF(m_circleColor / 360.0, 1, 1, m_circleAlpha / 255.0);
    QLinearGradient circleGradient(circleRect.topLeft(), circleRect.bottomRight());
    circleGradient.setColorAt(0, color.light());
    circleGradient.setColorAt(.5, color);
    circleGradient.setColorAt(1, color.dark());
    painter.setBrush(circleGradient);

    painter.drawEllipse(circleRect);
}
