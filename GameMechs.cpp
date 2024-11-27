#include "GameMechs.h"
#include "MacUILib.h"

// This should be finsihed. 

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // nothing on the heap 
    // Destructor can stay empty for now
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag; 
}
    

char GameMechs::getInput() // removed const
{   
    // Should this be placed here?    
    if (MacUILib_hasChar() != 0){
        // input will hold the input of the users key presses.
        input = MacUILib_getChar();
    } 
    return input;
}

int GameMechs::getScore() const
{
    return score; 
}

void GameMechs::incrementScore()
{
    score ++; 
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input; 

    

}

void GameMechs::clearInput()
{
    input = 0; // reseting input 
}

// More methods should be added here