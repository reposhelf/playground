#ifndef PATHSTROKEWIDGET_H
#define PATHSTROKEWIDGET_H

#include <QWidget>

class PathStrokeRenderer;
class PathStrokeControls;
class PathStrokeWidget : public QWidget
{
    Q_OBJECT

public:
    PathStrokeWidget(bool smallScreen, QWidget *parent = Q_NULLPTR);

private:
    PathStrokeRenderer *m_renderer;
    PathStrokeControls *m_controls;
};

#endif // PATHSTROKEWIDGET_H
