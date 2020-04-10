#include "instrumentspec.h"

InstrumentSpec::InstrumentSpec(const std::map<std::string, std::string> &properties)
    : mProperties(properties)
{
}

std::string InstrumentSpec::getProperty(const std::string &prop) const
{
    auto search = mProperties.find(prop);
    if (search != mProperties.end())
        return search->second;
    return "Unspecified";
}

const std::map<std::string, std::string> &InstrumentSpec::getProperties() const
{
    return mProperties;
}
