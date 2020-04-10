#ifndef PATHSTROKECONTROLS_H
#define PATHSTROKECONTROLS_H

#include <QWidget>

class PathStrokeRenderer;
class QGroupBox;
class PathStrokeControls : public QWidget
{
    Q_OBJECT

public:
    PathStrokeControls(PathStrokeRenderer *renderer, bool smallScreen, QWidget *parent = Q_NULLPTR);

signals:
    void okPressed();
    void quitPressed();

private slots:
    void emitQuitSignal();
    void emitOkSignal();

private:
    void createCommonControls(QWidget *parent);
    void layoutForDesktop();
    void layoutForSmallScreen();

    PathStrokeRenderer *m_renderer;

    QGroupBox *m_capGroup;
    QGroupBox *m_joinGroup;
    QGroupBox *m_styleGroup;
    QGroupBox *m_pathModeGroup;
};

#endif // PATHSTROKECONTROLS_H
