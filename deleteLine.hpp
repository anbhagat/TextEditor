#ifndef DELETE_LINE_HPP
#define DELETE_LINE_HPP

#include "Command.hpp"

class DeleteLine: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    std::string tempText;
    int tempLineNum;
    int tempColNum;
};

#endif // DELETE_LINE_HPP