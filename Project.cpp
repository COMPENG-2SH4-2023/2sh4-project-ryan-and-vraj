#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;



#define DELAY_CONST 100000


//OOD benefit, very limited globa variable declaration
//In Advanced OOD, there won't be any global variables
GameMechs* myGM;
Player*  myPlayer; // both are references

//bool exitFlag; //ask to comment or not

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    

    myGM = new GameMechs(30,15); // makes the board size 30x15
    myPlayer = new Player(myGM);
    //exitFlag = false;
}

void GetInput(void)
{
   myGM->getInput(); //ask about this section
}


void RunLogic(void)
{
    //myGM->getInput();
    myPlayer-> updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput(); //dont repeadtedly process same input
    
}

void DrawScreen(void)
{
   MacUILib_clearScreen(); 
    
    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); // get player pos
    
    //objPos myPlayer->7, 12, 'W');

        for (int i = 0; i < myGM->getBoardSizeY(); i++)
        {
            for (int j = 0; j < myGM->getBoardSizeX(); j++)
            {
                objPos currentPos(j, i, ' ');
                
                if (i == 0 || i == myGM->getBoardSizeY() -1 || j == 0 || j == myGM->getBoardSizeX()-1)
                {
                    objPos borderPos(i, j, '#');
                    MacUILib_printf("%c", borderPos.getSymbol());
                }

                else if (tempPos.isPosEqual(&currentPos))
                {
                    MacUILib_printf("%c", tempPos.symbol);
                }

               
                else 
                {
                    MacUILib_printf("%c", currentPos.getSymbol());
                }
                //MacUILib_printf("i: %d j:%d\n", i, j);
            }

            MacUILib_printf("\n");

            
        }

        
        //MacUILib_printf("Input: %c\n", myGM->getInput());
        MacUILib_printf("BoardSize: %dx%d, Player Position: <%d,%d> + %c\n", 
                        myGM->getBoardSizeX(), 
                        myGM->getBoardSizeY(), 
                        tempPos.x, tempPos.y, tempPos.symbol);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    //ask about deleting off of the heap    
    
    MacUILib_uninit();

    //remove heap instances
    delete[] myGM;
    delete[] myPlayer;
}