#ifndef GUITARSPEC_H
#define GUITARSPEC_H

#include "instrumentspec.h"

class GuitarSpec : public InstrumentSpec
{
public:
    GuitarSpec(Builder builder, const std::string &model, Type type,
               int numStrings, Wood backWood, Wood topWood);
    ~GuitarSpec();
    int getNumStrings() const { return mNumStrings; }

private:
    int mNumStrings;
};

inline bool operator==(const GuitarSpec &lhs, const GuitarSpec &rhs)
{
    return lhs.getBuilder() == rhs.getBuilder() && lhs.getModel() == rhs.getModel()
            && lhs.getType() == rhs.getType() && lhs.getBackWood() == rhs.getBackWood()
            && lhs.getTopWood() == rhs.getTopWood() && lhs.getNumStrings() == rhs.getNumStrings();
}

inline bool operator!=(const GuitarSpec &lhs, const GuitarSpec &rhs)
{
    return !(lhs == rhs);
}

#endif // GUITARSPEC_H
