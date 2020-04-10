#ifndef MANDOLINSPEC_H
#define MANDOLINSPEC_H

#include "instrumentspec.h"
#include "style.h"

class MandolinSpec : public InstrumentSpec
{
public:
    MandolinSpec(Builder builder, const std::string &model, Type type,
                 Style style, Wood backWood, Wood topWood);
    ~MandolinSpec();
    Style getStyle() const { return mStyle; }

private:
    Style mStyle;
};

inline bool operator==(const MandolinSpec &lhs, const MandolinSpec &rhs)
{
    return lhs.getBuilder() == rhs.getBuilder() && lhs.getModel() == rhs.getModel()
            && lhs.getType() == rhs.getType() && lhs.getBackWood() == rhs.getBackWood()
            && lhs.getTopWood() == rhs.getTopWood() && lhs.getStyle() == rhs.getStyle();
}

inline bool operator!=(const MandolinSpec &lhs, const MandolinSpec &rhs)
{
    return !(lhs == rhs);
}

#endif // MANDOLINSPEC_H
