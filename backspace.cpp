#include "backspace.hpp"

void Backspace::execute(EditorModel& model)
{
    tempCol = model.cursorColumn();
    model.backspace();
    
    if (tempCol > 1)
    {
        tempChar = model.getChar();
    }
}

void Backspace::undo(EditorModel& model)
{
    if (tempCol == 1)
    {
        model.newLine();
    }
    else
    {
        model.insertChar(tempChar);
    }
}
