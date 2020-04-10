#ifndef LIGHTONCOMMAND_H
#define LIGHTONCOMMAND_H

#include "command.h"

class Light;
class LightOnCommand : public Command
{
public:
    LightOnCommand(Light *light);
    ~LightOnCommand();

    void execute() const;
    void undo() const;

private:
    Light *_light;
};

#endif // LIGHTONCOMMAND_H
