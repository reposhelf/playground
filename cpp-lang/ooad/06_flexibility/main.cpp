#include "inventory.h"
#include "instrument.h"
#include "instrumentspec.h"
#include "builder.h"
#include "instrumenttype.h"
#include "type.h"
#include "numstrings.h"
#include "wood.h"
#include "model.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <QCoreApplication>


void initInventory(Inventory &inventory)
{
    std::map<std::string, std::string> properties;

    properties[InstrumentType::NAME] = InstrumentType::GUITAR;
    properties[Builder::NAME] = Builder::COLLINGS;
    properties[Model::NAME] = Model::CJ;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[NumStrings::NAME] = NumStrings::SIX;
    properties[Wood::BACK_WOOD_NAME] = Wood::INDIAN_ROSEWOOD;
    properties[Wood::TOP_WOOD_NAME] = Wood::SITKA;
    inventory.addInstrument("11277", 3999.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::GUITAR;
    properties[Builder::NAME] = Builder::MARTIN;
    properties[Model::NAME] = Model::D18;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[NumStrings::NAME] = NumStrings::SIX;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAHOGANY;
    properties[Wood::TOP_WOOD_NAME] = Wood::ADIRONDACK;
    inventory.addInstrument("122784", 5495.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::GUITAR;
    properties[Builder::NAME] = Builder::FENDER;
    properties[Type::NAME] = Type::ELECTRIC;
    properties[NumStrings::NAME] = NumStrings::SIX;
    properties[Wood::BACK_WOOD_NAME] = Wood::ALDER;
    properties[Wood::TOP_WOOD_NAME] = Wood::ALDER;
    inventory.addInstrument("V65593", 1499.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::GUITAR;
    properties[Builder::NAME] = Builder::FENDER;
    properties[Type::NAME] = Type::ELECTRIC;
    properties[NumStrings::NAME] = NumStrings::SIX;
    properties[Wood::BACK_WOOD_NAME] = Wood::ALDER;
    properties[Wood::TOP_WOOD_NAME] = Wood::ALDER;
    inventory.addInstrument("V9512", 1549.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::GUITAR;
    properties[Builder::NAME] = Builder::GIBSON;
    properties[Model::NAME] = Model::SG61;
    properties[Type::NAME] = Type::ELECTRIC;
    properties[NumStrings::NAME] = NumStrings::SIX;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAHOGANY;
    properties[Wood::TOP_WOOD_NAME] = Wood::MAHOGANY;
    inventory.addInstrument("82765501", 1890.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::GUITAR;
    properties[Builder::NAME] = Builder::GIBSON;
    properties[Model::NAME] = Model::LES_PAUL;
    properties[Type::NAME] = Type::ELECTRIC;
    properties[NumStrings::NAME] = NumStrings::SIX;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAPLE;
    properties[Wood::TOP_WOOD_NAME] = Wood::MAPLE;
    inventory.addInstrument("70108276", 2295.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::MANDOLIN;
    properties[Builder::NAME] = Builder::GIBSON;
    properties[Model::NAME] = Model::F5G;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAPLE;
    properties[Wood::TOP_WOOD_NAME] = Wood::MAPLE;
    inventory.addInstrument("9019920", 5495.99, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::MANDOLIN;
    properties[Builder::NAME] = Builder::COLLINGS;
    properties[Model::NAME] = Model::D18;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAPLE;
    properties[Wood::TOP_WOOD_NAME] = Wood::MAPLE;
    inventory.addInstrument("9919920", 5195.99, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::MANDOLIN;
    properties[Builder::NAME] = Builder::GIBSON;
    properties[Model::NAME] = Model::D18;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[Wood::BACK_WOOD_NAME] = Wood::ADIRONDACK;
    properties[Wood::TOP_WOOD_NAME] = Wood::BRASILIAN_ROSEWOOD;
    inventory.addInstrument("9819920", 5195.99, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::BANJO;
    properties[Builder::NAME] = Builder::GIBSON;
    properties[Model::NAME] = Model::RB3;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAPLE;
    inventory.addInstrument("8900231", 2945.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::BANJO;
    properties[Builder::NAME] = Builder::MARTIN;
    properties[Model::NAME] = Model::RB3;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAPLE;
    inventory.addInstrument("8800231", 2945.95, new InstrumentSpec(properties));

    properties.clear();

    properties[InstrumentType::NAME] = InstrumentType::BANJO;
    properties[Builder::NAME] = Builder::GIBSON;
    properties[Model::NAME] = Model::RB3;
    properties[Type::NAME] = Type::ACOUSTIC;
    properties[Wood::BACK_WOOD_NAME] = Wood::ADIRONDACK;
    inventory.addInstrument("7800231", 2945.95, new InstrumentSpec(properties));
}

int main()
{
    Inventory inventory;
    initInventory(inventory);

    std::map<std::string, std::string> properties;
    properties[Builder::NAME] = Builder::GIBSON;
    properties[Wood::BACK_WOOD_NAME] = Wood::MAPLE;
    InstrumentSpec clientSpec(properties);

    std::vector<Instrument *> matchingInstruments = inventory.search(clientSpec);
    if (!matchingInstruments.empty()) {
        std::cout << "You might like these instruments:" << std::endl;
        for (auto i : matchingInstruments) {
            InstrumentSpec *spec = i->getSpec();
            std::cout << "We have a " + spec->getProperty(InstrumentType::NAME)
                         + " with the following properties:" << std::endl;
            auto currProperties = spec->getProperties();
            for (auto property : currProperties) {
                if (property.first == InstrumentType::NAME)
                    continue;
                std::cout << "    " + property.first + ": "
                             + property.second << std::endl;
            }
            std::cout << "You can have this " + spec->getProperty(InstrumentType::NAME)
                         + " for $" << i->getPrice() << "\n---" << std::endl;
        }
    } else {
        std::cout << "Sorry, we have nothing for you" << std::endl;
    }

    return 0;
}
