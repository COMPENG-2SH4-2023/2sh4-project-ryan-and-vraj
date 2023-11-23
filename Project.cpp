#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
   MacUILib_clearScreen(); 
    
    int i = 0;
    int j = 0;

    
    objPos objectPos(7, 12, 'W');

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 20; j++)
            {
                objPos currentPos(i, j, ' ');
                
                if (i == 0 || i == 9 || j == 0 || j == 19)
                {
                    objPos borderPos(i, j, '#');
                    MacUILib_printf("%c", borderPos.getSymbol());
                }

                else if (objectPos.isPosEqual(&currentPos))
                {
                    MacUILib_printf("%c", objectPos.getSymbol());
                }
                 
                else 
                {
                    MacUILib_printf("%c", currentPos.getSymbol());
                }
            }

            printf("\n");
        }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}