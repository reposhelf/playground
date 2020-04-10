#include "httpmultiparthandler.h"

static const QString SIZE_VALUE_KEY = "Content-Length:";
static const QString FILE_NAME_VALUE_KYE = "File-Name:";
static const QString BOUNDARY_MARKER = "--boundary_.oOo._";
static const QString BOUNDARY_LINE_SEPARATOR = "\n\r\n";


HttpMultiPartHandler::HttpMultiPartHandler(QObject *parent)
    : QObject(parent)
{

}

void HttpMultiPartHandler::addPartitionedData(const QByteArray &data)
{
    if (mError != NoError)
        return;

    if (mAllowedSize <= 0)
    {
        mAllowedSize = getDataSize(data);
        mData.clear();
    }
    else
    {
        mData += data;
        mAllowedSize -= data.size();
        if (mAllowedSize <= 0)
            prepareFile();
    }
}

QString HttpMultiPartHandler::errorString() const
{
    switch (mError)
    {
    case NoError:
        return "HttpMultiPartHandler::No Error";
    case NoContentLengthError:
        return "HttpMultiPartHandler::Cannot found 'Content-Length' marker";
    case ContentLengthRepresentationError:
        return "HttpMultiPartHandler::Data's size representation failed";
    case NoFileNameError:
        return "HttpMultiPartHandler::Cannot found 'File-Name' marker";
    case NoEndBoundaryMarker:
        return "HttpMultiPartHandler::Cennot found data's end boundary marker";
    default: ;
    }
    return "HttpMultiPartHandler::Unknown error";
}

void HttpMultiPartHandler::reset()
{
    mData.clear();
    mAllowedSize = 0;
    mError = NoError;
}

int HttpMultiPartHandler::getDataSize(const QByteArray &data)
{
    QString lengthStr;
    int pos = data.indexOf(SIZE_VALUE_KEY);
    if (pos == -1)
    {
        setError(NoContentLengthError);
        return 0;
    }

    pos += SIZE_VALUE_KEY.size();
    while (data[++pos] != '\r')
        lengthStr += data[pos];

    bool ok;
    int ret = lengthStr.toInt(&ok);
    if (!ok)
    {
        setError(ContentLengthRepresentationError);
        return 0;
    }

    return ret;
}

QString HttpMultiPartHandler::getFileName()
{
    int pos = mData.indexOf(FILE_NAME_VALUE_KYE);
    if (pos == -1)
    {
        setError(NoFileNameError);
        return QString();
    }

    QString fileName;
    pos += FILE_NAME_VALUE_KYE.size();
    while (mData[++pos] != '\r')
        fileName += mData[pos];
    return fileName;
}

bool HttpMultiPartHandler::stripData()
{
    // clear data's front
    QString fileName = getFileName();
    if (fileName.isEmpty())
        return false;

    int pos = mData.indexOf(fileName);
    pos += fileName.size();
    while (mData[pos] == '\r' || mData[pos] == '\n')
        ++pos;
    mData.remove(0, pos);

    // clear data's end
    pos = mData.indexOf(BOUNDARY_MARKER) - BOUNDARY_LINE_SEPARATOR.size();
    if (pos == -1)
    {
        setError(NoEndBoundaryMarker);
        return false;
    }
    mData.remove(pos, mData.size() - pos);

    return true;
}

void HttpMultiPartHandler::prepareFile()
{
    QString fileName = getFileName();
    if (fileName.isEmpty())
        return;

    if (!stripData())
        return;

    emit fileReady(fileName, mData);
}

void HttpMultiPartHandler::setError(HttpMultiPartHandler::Error errorOccured)
{
    if (mError == errorOccured)
        return;

    mError = errorOccured;
    emit error();
}
