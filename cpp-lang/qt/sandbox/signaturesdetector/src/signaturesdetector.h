#ifndef SIGNATURESDETECTOR
#define SIGNATURESDETECTOR

#include <QWidget>

class SignaturesDetectorPrivate;

class SignaturesDetector : public QWidget {
    Q_OBJECT

public:
    explicit SignaturesDetector(QWidget *parent = 0);
    ~SignaturesDetector();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void onBrowseButtonClicked();
    void onScanningFinished();

private:
    void makeLayouts();
    void makeConnections();
    QIcon makeWindowIcon() const;
    bool aboutToClose();

    SignaturesDetectorPrivate *d;
    static QSize s_defaultSize;
};

#endif // SIGNATURESDETECTOR

