#ifndef DYNAMICMEMORYWIDGET_H
#define DYNAMICMEMORYWIDGET_H

#include "dynamicmemory.h"

#include <QWidget>

namespace Ui {
class DynamicMemoryWidget;
}

class DynamicMemory;
class QComboBox;
class DynamicMemoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DynamicMemoryWidget(DynamicMemory *dm, QWidget *parent = 0);
    ~DynamicMemoryWidget();

private slots:
    void onAddButtonClicked();
    void onRemoveButtonClicked();
    void onDynamicMemoryStatusChanged(DynamicMemory::StatusFlags flags);

private:
    void updateControls() const;
    void generateOption0(QComboBox *combo) const;
    void generateOption1(QComboBox *combo) const;
//    bool isCurrentPresetNull() const;

    Ui::DynamicMemoryWidget *ui;
    DynamicMemory *_dm;
};

#endif // DYNAMICMEMORYWIDGET_H
