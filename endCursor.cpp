#include "endCursor.hpp"

void CursorEnd::execute(EditorModel& model)
{
    tempColNum = model.cursorColumn();
    tempLineNum = model.cursorLine();
    model.end();
}

void CursorEnd::undo(EditorModel& model)
{
    model.index(tempLineNum, tempColNum);
}