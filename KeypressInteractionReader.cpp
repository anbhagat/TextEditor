// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "Interaction.hpp"

#include "Command.hpp"
//Include all the various source files for each command
#include "rightCursor.hpp"
#include "leftCursor.hpp"
#include "upCursor.hpp"
#include "downCursor.hpp"
#include "endCursor.hpp"
#include "newLine.hpp"
#include "homeCursor.hpp"
#include "deleteLine.hpp"
#include "backspace.hpp"
#include "insertCharacter.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
                case 'I': //Cursor Up
                {
                    return Interaction::command(new CursorUp());
                }
                case 'K': //Cursor Down
                {
                    return Interaction::command(new CursorDown());
                }
                case 'U': //Cursor Left
                {
                    return Interaction::command(new CursorLeft());
                }
                case 'O': //Cursor Right
                {
                    return Interaction::command(new CursorRight());
                }
                case 'Y': //Cursor Home
                {
                    return Interaction::command(new CursorHome());
                }
                case 'P': //Cursor End
                {
                    return Interaction::command(new CursorEnd());
                }
                //Both Ctrl+ J & Ctrl+M correspond to NewLine 
                case 'J': //New Line
                {
                    return Interaction::command(new NewLine());
                }
                case 'M': //New Line
                {
                    return Interaction::command(new NewLine());
                }
                case 'H': //Backspace
                {
                    return Interaction::command(new Backspace());
                }
                case 'D': //Delete Line
                {
                    return Interaction::command(new DeleteLine());
                }
                case 'Z': //Undo
                {
                    return Interaction::undo();
                }
                case 'A': //Re-Do
                {
                    return Interaction::redo();
                }
                case 'X':
                    return Interaction::quit();
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            Interaction currInt = Interaction::command(new InsertCharacter(keypress.code()));
            return currInt;
        }
    }
}

