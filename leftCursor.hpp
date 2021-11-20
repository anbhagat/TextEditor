#ifndef LEFT_CURSOR_HPP
#define LEFT_CURSOR_HPP
#include "Command.hpp"

class CursorLeft: public Command
{
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};
#endif // LEFT_CURSOR_HPP