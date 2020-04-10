#include "guitarspec.h"

GuitarSpec::GuitarSpec(Builder builder, const std::string &model, Type type,
                       int numStrings, Wood backWood, Wood topWood)
    : InstrumentSpec(builder, model, type, backWood, topWood),
      mNumStrings(numStrings)
{

}

GuitarSpec::~GuitarSpec()
{

}
