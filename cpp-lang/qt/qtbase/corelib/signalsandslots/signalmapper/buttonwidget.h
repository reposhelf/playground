#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>
#include <QMap>

class QSignalMapper;
class ButtonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonWidget(QWidget *parent = Q_NULLPTR);
    ~ButtonWidget();

private slots:
    void readFile(const QString &file);

private:
    QMap<QString, QString> m_textMap;
    QSignalMapper *m_signalMapper;
};

#endif // BUTTONWIDGET_H
