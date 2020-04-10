#ifndef SCANER
#define SCANER

#include <QThread>
#include <QMutex>

class Scaner : public QThread
{
    Q_OBJECT

public:
    explicit Scaner(const QString &path = QString(), QObject *parent = 0);
    ~Scaner();

    void setPath(const QString &path);
    QString path() const { return m_path; }

signals:
    void scanningProgressChanged(int);
    void scanningFileChanged(const QString&);
    void guidDetected(const QString&);

protected:
    void run();

private:
    int totalFileCount(const QString &path) const;
    void scanRecursively(const QString &path);
    QStringList scanFile(const QString &filePath) const;
    void updateScanProgress();

    int m_totalFileCount;
    int m_scannedFileCount;
    QMutex m_mutex;
    QString m_path;
};

#endif // SCANER

