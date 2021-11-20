#include "homeCursor.hpp"

void CursorHome::execute(EditorModel& model)
{
    tempLineNum = model.cursorLine();
    tempColNum = model.cursorColumn();
    model.home();
}

void CursorHome::undo(EditorModel& model)
{
    model.index(tempLineNum, tempColNum);
}