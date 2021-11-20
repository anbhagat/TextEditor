#include "deleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
    tempLineNum = model.cursorLine();
    tempColNum = model.cursorColumn();
    model.delLine();
    tempText = model.getText();
}

void DeleteLine::undo(EditorModel& model)
{
    model.index(tempLineNum, tempColNum);
    model.addLine(tempText);
}