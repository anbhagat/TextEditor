#ifndef HOME_CURSOR_HPP
#define HOME_CURSOR_HPP

#include "Command.hpp"

class CursorHome: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    int tempColNum;
    int tempLineNum;
    
};


#endif //