#include "remotecontrol.h"
#include "light.h"
#include "cellingfan.h"
#include "garagedoor.h"
#include "stereo.h"
#include "lightoncommand.h"
#include "lightoffcommand.h"
#include "cellingfanoncommand.h"
#include "cellingfanoffcommand.h"
#include "cellingfanhighcommand.h"
#include "cellingfanmediumcommand.h"
#include "garagedooropencommand.h"
#include "garagedoorclosecommand.h"
#include "stereoonwithcdcommand.h"
#include "stereooffcommand.h"
#include "macrocommand.h"

#include <iostream>

int main()
{
    // 1
//    Light livingRoomLight("Living Room");
//    Light kitchenLight("Kitchen");
//    CellingFan cellingFan("Living Room");
//    GarageDoor garageDoor("");
//    Stereo stereo("Living Room");

//    auto livingRoomLightOnCommand = new LightOnCommand(&livingRoomLight);
//    auto livingRoomLightOffCommand = new LightOffCommand(&livingRoomLight);
//    auto kitchenLightOnCommand = new LightOnCommand(&kitchenLight);
//    auto kitchenLightOffCommand = new LightOffCommand(&kitchenLight);

//    auto cellingFanOnCommand = new CellingFanOnCommand(&cellingFan);
//    auto cellingFanOffCommand = new CellingFanOffCommand(&cellingFan);

//    auto garageDoorOpenCommand = new GarageDoorOpenCommand(&garageDoor);
//    auto garageDoorCloseCommand = new GarageDoorCloseCommand(&garageDoor);

//    auto stereOnWithCDCommand = new StereoOnWithCDCommand(&stereo);
//    auto stereoOffCommand = new StereoOffCommand(&stereo);

//    RemoteControl remoteControl;
//    remoteControl.setCommand(0, livingRoomLightOnCommand, livingRoomLightOffCommand);
//    remoteControl.setCommand(1, kitchenLightOnCommand, kitchenLightOffCommand);
//    remoteControl.setCommand(2, cellingFanOnCommand, cellingFanOffCommand);
//    remoteControl.setCommand(3, garageDoorOpenCommand, garageDoorCloseCommand);
//    remoteControl.setCommand(4, stereOnWithCDCommand, stereoOffCommand);

//    std::cout << remoteControl.info() << std::endl;

//    remoteControl.buttonOnPressed(0);
//    remoteControl.buttonOffPressed(0);
//    remoteControl.buttonOnPressed(1);
//    remoteControl.buttonOffPressed(1);
//    remoteControl.buttonOnPressed(2);
//    remoteControl.buttonOffPressed(2);
//    remoteControl.buttonOnPressed(3);
//    remoteControl.buttonOffPressed(3);
//    remoteControl.buttonOnPressed(4);
//    remoteControl.buttonOffPressed(4);

    // 2
//    Light livingRoomLight("Living Room");

//    auto livingRoomLightOnCommand = new LightOnCommand(&livingRoomLight);
//    auto livingRoomLightOffCommand = new LightOffCommand(&livingRoomLight);

//    RemoteControl remoteControl;
//    remoteControl.setCommand(0, livingRoomLightOnCommand, livingRoomLightOffCommand);

//    remoteControl.buttonOnPressed(0);
//    remoteControl.buttonOffPressed(0);
//    std::cout << remoteControl.info() << std::endl;
//    remoteControl.buttonUndoPressed();
//    remoteControl.buttonOffPressed(0);
//    remoteControl.buttonOnPressed(0);
//    std::cout << remoteControl.info() << std::endl;
//    remoteControl.buttonUndoPressed();

    // 3
//    CellingFan cellingFan("Living Room");

//    auto cellingFanMediumCommand = new CellingFanMediumCommand(&cellingFan);
//    auto cellingFanHighCommand = new CellingFanHighCommand(&cellingFan);
//    auto cellingFanOffCommand = new CellingFanOffCommand(&cellingFan);

//    RemoteControl remoteControl;
//    remoteControl.setCommand(0, cellingFanMediumCommand, cellingFanOffCommand);
//    remoteControl.setCommand(1, cellingFanHighCommand, cellingFanOffCommand);

//    remoteControl.buttonOnPressed(0);
//    remoteControl.buttonOffPressed(0);
//    std::cout << remoteControl.info() << std::endl;
//    remoteControl.buttonUndoPressed();

//    remoteControl.buttonOnPressed(1);
//    std::cout << remoteControl.info() << std::endl;
//    remoteControl.buttonUndoPressed();

    // 4
    Light light("Living Room");
    Stereo stereo("Living Room");
    CellingFan cellingFan("Living Room");

    std::vector<Command *> onCommands;
    onCommands.push_back(new LightOnCommand(&light));
    onCommands.push_back(new StereoOnWithCDCommand(&stereo));
    onCommands.push_back(new CellingFanMediumCommand(&cellingFan));

    std::vector<Command *> offCommands;
    offCommands.push_back(new LightOffCommand(&light));
    offCommands.push_back(new StereoOffCommand(&stereo));
    offCommands.push_back(new CellingFanOffCommand(&cellingFan));

    auto partyOnCommand = new MacroCommand(onCommands);
    auto partyOffCommand = new MacroCommand(offCommands);

    RemoteControl remoteControl;
    remoteControl.setCommand(0, partyOnCommand, partyOffCommand);

    std::cout << remoteControl.info() << std::endl;
    std::cout << "-------- Pushing Macro On --------" << std::endl;
    remoteControl.buttonOnPressed(0);
    std::cout << "-------- Pushing Macro Off --------" << std::endl;
    remoteControl.buttonOffPressed(0);
    std::cout << "-------- Pushing Macro Undo --------" << std::endl;
    remoteControl.buttonUndoPressed();

    return 0;
}
