#include "inputdata.h"

InputData *InputData::instance()
{
    static InputData inputData;
    return &inputData;
}

void InputData::setStartUrl(const QString &startUrl)
{
    m_startUrl = startUrl;
}

void InputData::setTextForSearch(const QString &textForSearch)
{
    m_textForSearch = textForSearch;
}

void InputData::setMaxThreads(uint maxThreads)
{
    m_maxThreads = maxThreads;
}

void InputData::setMaxLinks(uint maxLinks)
{
    m_maxLinks = maxLinks;
}

bool InputData::isValid() const
{
    check();
    return m_error == NoError;
}

QString InputData::errorString() const
{
    switch (m_error) {
    case NoError:
        return QString();
    case ThreadsAmountError:
        return "InputData: error: amount of threads must be in range 1:32";
    case LinksAmountError:
        return "InputData: error: amount of links must be in range 1:99";
    case StartUrlEmpty:
        return "InputData: error: start URL is empty";
    case TextForSearchEmpty:
        return "InputData: error: text for search is empty";
    default:
        break;
    }
    return QString();
}

void InputData::check() const
{
    if (m_maxThreads < 1 || m_maxThreads > 32) {
        m_error = ThreadsAmountError;
        return;
    }

    if (m_maxLinks < 1 || m_maxLinks > 99) {
        m_error = LinksAmountError;
        return;
    }

    if (m_startUrl.isEmpty()) {
        m_error = StartUrlEmpty;
        return;
    }

    if (m_textForSearch.isEmpty()) {
        m_error = TextForSearchEmpty;
        return;
    }

    m_error = NoError;
}
