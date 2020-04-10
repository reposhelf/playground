#include "mandolinspec.h"

MandolinSpec::MandolinSpec(Builder builder, const std::string &model, Type type,
                           Style style, Wood backWood, Wood topWood)
    : InstrumentSpec(builder, model, type, backWood, topWood),
      mStyle(style)
{

}

MandolinSpec::~MandolinSpec()
{

}
