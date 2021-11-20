#ifndef DOWN_CURSOR_HPP
#define DOWN_CURSOR_HPP
#include "Command.hpp"

class CursorDown: public Command
{
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};
#endif // DOWN_CURSOR_HPP


