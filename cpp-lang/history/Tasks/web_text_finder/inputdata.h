#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QString>

class InputData
{
    enum Error {NoError,
                ThreadsAmountError,
                LinksAmountError,
                StartUrlEmpty,
                TextForSearchEmpty
               };

public:
    InputData(const InputData&) = delete;
    InputData &operator=(const InputData&) = delete;
    static InputData *instance();

    void setStartUrl(const QString &startUrl);
    QString startUrl() const { return m_startUrl; }

    void setTextForSearch(const QString &textForSearch);
    QString textForSearch() const { return m_textForSearch; }

    void setMaxThreads(uint maxThreads);
    uint maxThreads() const { return m_maxThreads; }

    void setMaxLinks(uint maxLinks);
    uint maxLinks() const { return m_maxLinks; }

    bool isValid() const;
    QString errorString() const;

private:
    InputData() = default;
    void check() const;

    QString m_startUrl;
    QString m_textForSearch;
    uint m_maxThreads = 1;
    uint m_maxLinks = 1;
    mutable Error m_error;
};

#endif // INPUTDATA_H
