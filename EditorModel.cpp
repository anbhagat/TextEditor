// EditorModel.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <iostream>


EditorModel::EditorModel()
    :lineNum{1}, colNum{1}
{
    textFile.push_back("");
}

int EditorModel::cursorLine() const
{
    return lineNum;
}


int EditorModel::cursorColumn() const
{
    return colNum;
}


int EditorModel::lineCount() const
{
    return textFile.size();
}

const std::string& EditorModel::line(int lineNumber) const
{
    return textFile[lineNumber - 1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return error;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    error = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    error = "";
}

void EditorModel::right()
{
    if (lineNum < lineCount())
    {
        lineNum += 1;
        colNum = 1;
    }
    else if (colNum < line(lineNum).length()+1)
    {
        colNum += 1;
    }
    else
    {
        throw EditorException("You are at the end of this text file.");
    }
}

void EditorModel::left()
{
    if (colNum > 1)
    {
        colNum -= 1;
    }
    else if (lineNum > 1)
    {
        lineNum -= 1;
        colNum = line(lineNum).length() + 1;
    }
    else
    {
        throw EditorException("You are at the beginning of this text file.");
    }
}

void EditorModel::up()
{
    if (lineNum > 1)
    {
        lineNum -= 1;
        if (colNum > line(lineNum).length() + 1)
        {
            colNum = line(lineNum).length() + 1;
        }
    }
    else
    {
        throw EditorException("This is the top of the text file");
    }
}

void EditorModel::down()
{
    if (lineNum < lineCount())
    {
        lineNum += 1;
        if (colNum > line(lineNum).length()+1)
        {
            colNum = line(lineNum).length()+1;
        }
    }
    else
    {
        throw EditorException("This is the bottom of the file");
    }
}

void EditorModel::home()
{
    colNum = 1;
}

void EditorModel::end()
{
    colNum = line(lineNum).length()+1;
}

void EditorModel::backspace()
{
    if (colNum == 1 && lineNum == 1)
    {
        throw EditorException("This is the beginning of the text file");
    }
    else if (colNum == 1)
    {
        colNum = textFile[lineNum-2].length()+1;
        textFile[lineNum-2] += line(lineNum);
        textFile.erase(textFile.begin() + lineNum - 1);
        lineNum -= 1;
    }
    else
    {
        c = textFile[lineNum-1][colNum-2];
        textFile[lineNum-1] = textFile[lineNum-1].erase(colNum-2,1);
        colNum -= 1;
    }
}

void EditorModel::addLine(std::string l)
{
    int index = lineNum - 1;
    textFile.insert(textFile.begin() + index, l);
}

void EditorModel::newLine()
{
    int index = lineNum -1;
    std::string temp = textFile[index].substr(colNum-1);
    textFile[index] = textFile[index].substr(0, colNum-1);
    textFile.insert(textFile.begin() + lineNum, temp);
    lineNum += 1;
    colNum = 1;
}

void EditorModel::delLine()
{
    text = textFile[lineNum-1];
    if (lineCount() != 1)
    {
        textFile.erase(textFile.begin() + lineNum-1);
        if (lineNum < 1)
        {
            lineNum = 1;
        }
        else
        {
            lineNum -= 1;
            
        }
        if (colNum > textFile[lineNum-1].length()+1)
        {
            colNum = textFile[lineNum-1].length()+1;
        }
    }
    else
    {
        textFile.push_back("");
        textFile.erase(textFile.begin() + lineNum-1);
        lineNum = 1;
        colNum = 1;
    }
}

void EditorModel::insertChar(char c)
{
    textFile[lineNum-1] = textFile[lineNum-1].insert(colNum-1,1,c);
    colNum += 1;

}

char EditorModel::getChar()
{
    return c;
}

void EditorModel::index(int l, int col)
{
    lineNum = l;
    colNum = col;
}

std::string EditorModel::getText()
{
    return text;
}