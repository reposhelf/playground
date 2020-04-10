#ifndef HTTPMULTIPARTHANDLER_H
#define HTTPMULTIPARTHANDLER_H

#include <QObject>

class HttpMultiPartHandler : public QObject
{
    Q_OBJECT
public:
    enum Error
    {
        NoError,
        NoContentLengthError,
        ContentLengthRepresentationError,
        NoFileNameError,
        NoEndBoundaryMarker
    };

    explicit HttpMultiPartHandler(QObject *parent = nullptr);

    void addPartitionedData(const QByteArray &data);
    QString errorString() const;
    void reset();

signals:
    void fileReady(const QString &fileName, const QByteArray &fileContent);
    void error();

private:
    int getDataSize(const QByteArray &data);
    QString getFileName();
    bool stripData();
    void prepareFile();
    void setError(Error errorOccured);

private:
    QByteArray mData;
    int mAllowedSize = 0;
    Error mError = NoError;
};

#endif // HTTPMULTIPARTHANDLER_H
