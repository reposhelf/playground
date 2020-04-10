#include "instrumentspec.h"

InstrumentSpec::InstrumentSpec(Builder builder, const std::string &model,
                               Type type, Wood backWood, Wood topWood)
    : mBuilder(builder),
      mModel(model),
      mType(type),
      mBackWood(backWood),
      mTopWood(topWood)
{
}

InstrumentSpec::~InstrumentSpec()
{

}
