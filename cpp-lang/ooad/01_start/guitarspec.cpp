#include "guitarspec.h"

GuitarSpec::GuitarSpec(Builder::Builder builder, const std::string &model, Type::Type type,
                       Wood::Wood backWood, Wood::Wood topWood, unsigned numStrings)
    : m_builder(builder),
      m_model(model),
      m_type(type),
      m_backWood(backWood),
      m_topWood(topWood),
      m_numStrings(numStrings)
{

}
