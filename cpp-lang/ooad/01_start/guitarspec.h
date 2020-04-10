#ifndef GUITARSPEC_H
#define GUITARSPEC_H

#include "builder.h"
#include "type.h"
#include "wood.h"

#include <string>

class GuitarSpec
{
public:
    GuitarSpec(Builder::Builder builder, const std::string &model, Type::Type type,
               Wood::Wood backWood, Wood::Wood topWood, unsigned numStrings);

    Builder::Builder builder() const { return m_builder; }
    std::string model() const { return m_model; }
    Type::Type type() const { return m_type; }
    Wood::Wood backWood() const { return m_backWood; }
    Wood::Wood topWood() const { return m_topWood; }
    unsigned numStrings() const { return m_numStrings; }

private:
    Builder::Builder m_builder;
    std::string m_model;
    Type::Type m_type;
    Wood::Wood m_backWood;
    Wood::Wood m_topWood;
    unsigned m_numStrings;
};

inline bool operator==(const GuitarSpec &lhs, const GuitarSpec &rhs)
{
    return lhs.builder() == rhs.builder() && lhs.model() == rhs.model()
            && lhs.type() == rhs.type() && lhs.backWood() == rhs.backWood()
            && lhs.topWood() == rhs.topWood() && lhs.numStrings() == rhs.numStrings();
}

inline bool operator!=(const GuitarSpec &lhs, const GuitarSpec &rhs)
{
    return !(lhs == rhs);
}

#endif // GUITARSPEC_H
