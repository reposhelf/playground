#ifndef INSTRUMENTSPEC_H
#define INSTRUMENTSPEC_H

#include "builder.h"
#include "type.h"
#include "wood.h"

#include <string>

class InstrumentSpec
{
public:
    InstrumentSpec(Builder builder, const std::string &model,
                   Type type, Wood backWood, Wood topWood);
    virtual ~InstrumentSpec() = 0;

    Builder getBuilder() const { return mBuilder; }
    std::string getModel() const { return mModel; }
    Type getType() const { return mType; }
    Wood getBackWood() const { return mBackWood; }
    Wood getTopWood() const { return mTopWood; }

private:
    Builder mBuilder;
    std::string mModel;
    Type mType;
    Wood mBackWood;
    Wood mTopWood;
};

inline bool operator==(const InstrumentSpec &lhs, const InstrumentSpec &rhs)
{
    return lhs.getBuilder() == rhs.getBuilder() && lhs.getModel() == rhs.getModel()
            && lhs.getType() == rhs.getType() && lhs.getBackWood() == rhs.getBackWood()
            && lhs.getTopWood() == rhs.getTopWood();
}

inline bool operator!=(const InstrumentSpec &lhs, const InstrumentSpec &rhs)
{
    return !(lhs == rhs);
}

#endif // INSTRUMENTSPEC_H
