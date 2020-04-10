#ifndef ANIMATEDPROGRESSWIDGET
#define ANIMATEDPROGRESSWIDGET

#include <QLabel>

class QMovie;

class AnimatedProgressWidget : public QLabel
{
    Q_OBJECT

public:
    AnimatedProgressWidget(QWidget *parent = 0);
    virtual ~AnimatedProgressWidget();

public slots:
    void startProgress();
    void stopProgress();

private:
    QMovie *m_movie;
    static const QSize s_scaledSize;
};

#endif // ANIMATEDPROGRESSWIDGET

