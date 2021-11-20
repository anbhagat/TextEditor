#ifndef UP_CURSOR_HPP
#define UP_CURSOR_HPP
#include "Command.hpp"

class CursorUp: public Command
{
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};
#endif // UP_CURSOR_HPP