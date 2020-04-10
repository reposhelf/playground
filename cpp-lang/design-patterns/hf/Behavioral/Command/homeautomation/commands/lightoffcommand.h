#ifndef LIGHTOFFCOMMAND_H
#define LIGHTOFFCOMMAND_H

#include "command.h"

class Light;
class LightOffCommand : public Command
{
public:
    LightOffCommand(Light *light);
    ~LightOffCommand();

    void execute() const;
    void undo() const;

private:
    Light *_light;
};

#endif // LIGHTOFFCOMMAND_H
