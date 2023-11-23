#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
<<<<<<< HEAD
    input = NULL;
=======
>>>>>>> d2ba28e795f7b28ed55c846d91e39ea8ae0d98d9
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    

}

GameMechs::GameMechs(int boardX, int boardY)
{
<<<<<<< HEAD
    input = NULL;
=======
>>>>>>> d2ba28e795f7b28ed55c846d91e39ea8ae0d98d9
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

// do you need a destructor?
GameMechs::~GameMechs()
{

}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
<<<<<<< HEAD
    if(MacUILib_hasChar()) {
        input = MacUILib_getChar();
    } 
=======
>>>>>>> d2ba28e795f7b28ed55c846d91e39ea8ae0d98d9
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
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
    input = '\0';
<<<<<<< HEAD
=======
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
>>>>>>> d2ba28e795f7b28ed55c846d91e39ea8ae0d98d9
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}