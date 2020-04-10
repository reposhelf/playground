#ifndef INSTRUMENTSPEC_H
#define INSTRUMENTSPEC_H

#include "builder.h"
#include "type.h"
#include "wood.h"

#include <string>
#include <map>

class InstrumentSpec
{
public:
    explicit InstrumentSpec(const std::map<std::string, std::string> &properties);
    std::string getProperty(const std::string &prop) const;
    const std::map<std::string, std::string> &getProperties() const;

private:
    std::map<std::string, std::string> mProperties;
};

inline bool operator==(const InstrumentSpec &lhs, const InstrumentSpec &rhs)
{
    return lhs.getProperties() == rhs.getProperties();
}

inline bool operator!=(const InstrumentSpec &lhs, const InstrumentSpec &rhs)
{
    return !(lhs == rhs);
}

#endif // INSTRUMENTSPEC_H
