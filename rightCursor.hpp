#ifndef RIGHT_CURSOR_HPP
#define RIGHT_CURSOR_HPP
#include "Command.hpp"

class CursorRight: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};

#endif // RIGHT_CURSOR_HPP