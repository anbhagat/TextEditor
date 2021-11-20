#ifndef END_CURSOR_HPP
#define END_CURSOR_HPP

#include "Command.hpp"

class CursorEnd: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    int tempLineNum;
    int tempColNum;
};


#endif // END_HPP